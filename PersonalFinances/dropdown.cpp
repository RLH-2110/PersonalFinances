#include "includes.h";

using sf::Vector2i;
using sf::Vector2f;
using std::wstring;
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
			this->titleStrings = new wstring[fields];
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
			elements.push_back(new wstring(*dropdown.elements[i]));
		}
	}
	catch (const std::bad_alloc &e) {
		error(errorID::outOfMem);
	}

}

Dropdown::Dropdown(const sf::Vector2f& position, int fields, const std::wstring * const titleStrings) { // its expected that the array is terminated by an emptry string. emptry string terminator is optinal, but its better than relying on the fields integer being correct to determin the array lenght.
	puts("update code!");
}

Dropdown::Dropdown(const sf::Vector2f& position, int fields, const std::wstring * const titleStrings, const std::vector <std::wstring*>& elements)
	: Table(position, fields, titleStrings)
{
	puts("update code!");
}

Dropdown::Dropdown(const sf::Vector2f& position, int fields, const std::wstring * const titleStrings, const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness)
	: Dropdown(position, fields, titleStrings)
{
	initBorder(innerMargin, outerLineThickness, mainboxOuterLineThickness);
}
Dropdown::Dropdown(const sf::Vector2f& position, int fields, const std::wstring * const titleStrings, const std::vector <std::wstring*>& elements, const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness)
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

