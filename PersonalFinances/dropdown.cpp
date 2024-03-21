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

Dropdown::Dropdown(const sf::Vector2i& position, int fields, const std::string * const titleStrings, const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness) 
	: Dropdown(position, fields, titleStrings)
{
	initBorder(innerMargin, outerLineThickness, mainboxOuterLineThickness);
}
Dropdown::Dropdown(const sf::Vector2i& position, int fields, const std::string * const titleStrings, const std::vector <std::string*>& elements, const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness)
	: Dropdown(position, fields, titleStrings, elements)
{
	initBorder(innerMargin, outerLineThickness, mainboxOuterLineThickness);
}
void Dropdown::initBorder(const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness) {
	this->innerMargin = innerMargin;
	this->outerLineThickness = outerLineThickness;
	this->mainboxOuterLineThickness = mainboxOuterLineThickness;
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

	int sizeX, sizeY;

	for (int i = 0; i < fields; i++) {

		// find text with
		sizeFinder.setString(titleStrings[i]);
		bounds = sizeFinder.getGlobalBounds();

		// add inner margin
		sizeX = bounds.width + innerMargin *2;

		// find text height
		sizeFinder.setString("ABCDEFGHIJKLMNOPQRTSUVWXYZ123456789+-*/;:"); // apperently characters can have different height, so we just take the biggest one
		bounds = sizeFinder.getGlobalBounds();
		
		// add inner margin
		sizeY = bounds.height + innerMargin *2;

		// place in vector
		rowRender.emplace_back(sf::Vector2f(sizeX, sizeY));

		rowRender.back().setFillColor(sf::Color::Transparent);
		rowRender.back().setOutlineColor(sf::Color::Black);
		rowRender.back().setOutlineThickness(outerLineThickness);

		if (i == 0)
			rowRender.back().setPosition(outerLineThickness+mainboxOuterLineThickness,outerLineThickness+ mainboxOuterLineThickness);
		else 
			rowRender.back().setPosition(prev.getSize().x + prev.getPosition().x + outerLineThickness, outerLineThickness + mainboxOuterLineThickness);
		
		prev = rowRender.back();
	}

	// generate bigger rect that encompasses all the other rects
	rowRender.emplace_back(
		sf::Vector2f(
		prev.getPosition().x + prev.getSize().x - mainboxOuterLineThickness + outerLineThickness,
		prev.getGlobalBounds().height )
	); // bounding box around all the elements

#ifdef DEBUG
	printf("----------\nsizeX: %f\nposX: %f\n mbOLT: %f\n oLT: %f\nresult: %f\n----------\n", prev.getSize().x, prev.getPosition().x, mainboxOuterLineThickness, outerLineThickness, rowRender.back().getSize().x);
#endif // DEBUG


	rowRender.back().setPosition(mainboxOuterLineThickness, mainboxOuterLineThickness);
	rowRender.back().setFillColor(sf::Color::Transparent);
	rowRender.back().setOutlineColor(sf::Color::Black);
	rowRender.back().setOutlineThickness(mainboxOuterLineThickness);
}

void Dropdown::render(sf::RenderWindow& window) const{

	// use rowRender to render rows, and to place text in those rows


	// mosty test code for now, its not done!
	float yOffset = position.y;
	int xOffset = position.x;

	// draw the main box
	
	sf::RectangleShape rect = rowRender.back();
	rect.setPosition(sf::Vector2f(xOffset + rect.getPosition().x, yOffset + rect.getPosition().y));


#ifdef DEBUG
	rect.setOutlineColor(sf::Color::Red);
#endif // DEBUG

	window.draw(rect);
	
	sf::Text textDraw;
	textDraw.setFont(fontData.font);
	textDraw.setCharacterSize(fontData.fontSize);
	textDraw.setStyle(fontData.style);
	textDraw.setFillColor(sf::Color::Black);

	// draw the title fields
	for (int j = 0; j < rowRender.size() - 1; j++) { // the last one is the big sourounding box that we ignore for now.

		rect = rowRender[j];
		rect.setPosition(sf::Vector2f(xOffset + rect.getPosition().x, yOffset + rect.getPosition().y));

		window.draw(rect);

		textDraw.setPosition(rect.getPosition().x + innerMargin, rect.getPosition().y + innerMargin);
		textDraw.setString(titleStrings[j]);

		window.draw(textDraw);
		
	}

	//yOffset += rowRender.front().getSize().y + rowRender.back().getOutlineThickness() * 2;
	yOffset += rowRender.back().getGlobalBounds().height - mainboxOuterLineThickness;

	for (int i = 0; i < elements.size(); i++) {


		for (int j = 0; j < rowRender.size() - 1; j++) { // the last one is the big sourounding box that we ignore

			rect = rowRender[j];

#ifdef DEBUG
			rect.setOutlineColor(sf::Color::Blue);
#endif // DEBUG

			
			// make them flush with the outer border
			{
				// psyeudo code for clarity:
				// if (j == first_element || j == last_element) {
				//		increase the size by outlineThiekness; }
				//
				// if (j is both first and last element){
				//		increase size by 1 again;
				//		shift position left based on he outer line thickness; }
				// else if (j == first_element){
				//		shift position left based on he outer line thickness; }
				// else {
				//		set position normally; }


				// why does that make it look good? IDK, I just adjust it as needed. I have no idea about this front end stuff.

				int first_element = 0;
				int last_element = rowRender.size() - 2;

				if (j == first_element || j == last_element) { // first or last element
					rect.setSize(sf::Vector2f(rect.getSize().x + rowRender.back().getOutlineThickness(), rect.getSize().y)); // increase the size by the size of the outline
				}
				if (j == first_element && j == last_element) { // first and last at the same time
					rect.setSize(sf::Vector2f(rect.getSize().x + rowRender.back().getOutlineThickness(), rect.getSize().y)); // increase the size by the size of the outline again
					rect.setPosition(sf::Vector2f(xOffset + rect.getPosition().x - rowRender.back().getOutlineThickness(), yOffset + rect.getPosition().y));
				}else if (j == first_element) {	// first element
					rect.setPosition(sf::Vector2f(xOffset + rect.getPosition().x - rowRender.back().getOutlineThickness(), yOffset + rect.getPosition().y));
				}
				else {	//	elements in the middle or the last element
					rect.setPosition(sf::Vector2f(xOffset + rect.getPosition().x, yOffset + rect.getPosition().y));
				}
			}
			

			//rect.setPosition(sf::Vector2f(xOffset + rect.getPosition().x, yOffset + rect.getPosition().y));

			window.draw(rect);
		}
		yOffset += rowRender.front().getSize().y + rowRender.front().getOutlineThickness();
	}

}

