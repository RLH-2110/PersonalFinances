#pragma once
#include <SFML/Graphics.hpp>

struct FontData {
	sf::Font font;
	unsigned int fontSize;
	uint32_t style;
};

extern FontData stdFont;