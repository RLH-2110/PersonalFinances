#include "includes.h";

using sf::Vector2i;
using sf::Vector2f;
using std::string;
using std::vector;



/*
contains unessarry safety checks for now.
Depending on how I implement stuff later, I might remove them.
*/

Dropdown::Dropdown() {
	fields = 0;
}

Dropdown::Dropdown(const Dropdown& dropdown) {

	fields = dropdown.fields;
	size = dropdown.size;

	innerMargin = dropdown.innerMargin;
	outerLineThickness = dropdown.outerLineThickness;
	mainboxOuterLineThickness = dropdown.mainboxOuterLineThickness;

	position = dropdown.position;
	fontData = dropdown.fontData;

	rowRender = dropdown.rowRender;

	{	//	titleStrings //
		try {
			this->titleStrings = new string[fields];
		}
		catch (const std::bad_alloc &e) {
			error(errorID::outOfMem);
		}

		for (int i = 0; i < fields; i++) {
			titleStrings[i] = dropdown.titleStrings[i];
		}
	}


	try {	// elements
		for (int i = 0; i < dropdown.elements.size(); i++) {
			elements.push_back(new string(*dropdown.elements[i]));
		}
	}
	catch (const std::bad_alloc &e) {
		error(errorID::outOfMem);
	}

}

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
	: Table(position, fields, titleStrings)
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


Dropdown::~Dropdown() {
		delete [] titleStrings; titleStrings = nullptr;

		elements.clear();

	while (!elements.empty()) {	// deallocate all pointers and remove all elements from the vector
		free(elements.back());
		elements.pop_back();
	}

}





void Dropdown::generateRenderInfo() {	// DO NOT USE THESE MACROS IN HERE: mainbox, addbox
	puts("update code!");
}

void Dropdown::render(sf::RenderWindow& window) const{
	puts("update code!");

}

