#pragma once

#include "includes.h"

class Dropdown
{

	// todo

private:
	int fields;
	int extendedHeight;


	// arrays (all indexed by 'fields')
	std::string *titleStrings;
	std::vector <std::string*> elements;

	int *maxTextLength;

public:
	sf::Vector2i position;

	Dropdown(const sf::Vector2i& position, int fields, const std::string * const titleStrings);
	Dropdown(const sf::Vector2i& position, int fields, const std::string * const titleStrings, const std::vector <std::string*>& elements);
	~Dropdown();
};