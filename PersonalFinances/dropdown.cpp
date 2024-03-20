#include "includes.h";

using sf::Vector2i;
using sf::Vector2f;
using std::string;
using std::vector;



/*
contains unessarry safety checks for now.
Depending on how I implement stuff later, I might remove them.
*/

Dropdown::Dropdown(const sf::Vector2i& position, int fields, const std::string * const titleStrings) { // its expected that the array is terminated by an emptry string. emptry string terminator is optinal, but its better than relying on the fields integer being correct to determin the array lenght.
	this->position = position;
	this->fields = fields;

	try {
		this->titleStrings = new string[fields];
	}
	catch (const std::bad_alloc &e) {
		error(errorID::outOfMem);
	}

	// check if the string array metches the number of fields, and add the strings to the list.
	for (int i = 0; i < fields; i++) {
		if (titleStrings[i] == std::string("")) {	// check if the current element is an empty string (terminator)
			delete[] this->titleStrings; this->titleStrings = nullptr;
			error(errorID::arraySizeMismatch); 
		}
		this->titleStrings[i] = titleStrings[i];
	}

	fontData = stdFont;

	generateRenderInfo();
}

Dropdown::Dropdown(const sf::Vector2i& position, int fields, const std::string * const titleStrings, const std::vector <std::string*>& elements) 
	:	Dropdown(position, fields, titleStrings)
	{
	for (int i = 0; i < elements.size(); i++) {

		string *contents = new string[fields];	// create new memory, indipendent from what happens outside this class

		//copy the data in the new memory

		// check if the string array metches the number of fields, and add the strings to contents
		for (int j = 0; j < fields; j++) {
			if (elements[i][j] == std::string("")) {	// check if the current element is an empty string (terminator)
				delete[] contents; contents = nullptr;
				error(errorID::arraySizeMismatch);
			}
			contents[j] = elements[i][j];
		}

		this->elements.push_back(contents); // save it in the vector
	}
}


Dropdown::~Dropdown() {
		delete [] titleStrings; titleStrings = nullptr;

		elements.clear();

	while (!elements.empty()) {	// deallocate all pointers and remove all elements from the vector
		free(elements.back());
		elements.pop_back();
	}

}


void Dropdown::generateRenderInfo() {

	puts("dont forget to test generateRenderInfo()!");

	sf::Text sizeFinder;
	sizeFinder.setFont(fontData.font);
	sizeFinder.setStyle(fontData.style);		
	sizeFinder.setCharacterSize(fontData.fontSize);
	sizeFinder.setPosition(0.0f,0.0f);

	sf::FloatRect bounds;

	rowRender.clear();

	sf::RectangleShape prev;

	for (int i = 0; i < fields; i++) {

		sizeFinder.setString(titleStrings[i]);
		bounds = sizeFinder.getGlobalBounds();

		// add inner margin
		bounds.height += innerMargin;
		bounds.width += innerMargin;

		// place in vector
		rowRender.emplace_back(sf::Vector2f(bounds.width, bounds.height));

		if (i == 0)
			rowRender.back().setPosition(outerLineThickness,outerLineThickness);
		else
			rowRender.back().setPosition(prev.getSize().x + prev.getPosition().x, outerLineThickness);

		//prev = rowRender.back;
	}

	// generate bigger rect that encompasses all the other rects
	rowRender.emplace_back(sf::Vector2f(prev.getSize().x + prev.getPosition().x + 2*outerLineThickness, bounds.height + 2*outerLineThickness)); // bounding box around all the elements
	rowRender.back().setOutlineThickness(outerLineThickness);
}

void Dropdown::render() const{
	puts("not implemented");
	// use rowRender to render rows, and to place text in those rows
}

