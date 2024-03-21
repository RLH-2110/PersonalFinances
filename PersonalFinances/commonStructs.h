#pragma once
#include <SFML/Graphics.hpp>

struct FontData {
	sf::Font font;
	unsigned int fontSize;
	uint32_t style;

	FontData(){}

	FontData(FontData& data) {
		font = data.font;
		fontSize = data.fontSize;
		style = data.style;
	}
};

extern FontData stdFont;