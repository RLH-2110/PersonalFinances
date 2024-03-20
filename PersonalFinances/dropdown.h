#pragma once

#include "includes.h"

class Dropdown
{

	// todo

private:
	int fields;
	int extendedHeight;
	sf::Vector2i size;	

	// arrays (all indexed by 'fields')
	std::string *titleStrings;
	std::vector <std::string*> elements;

	std::vector <sf::RectangleShape> rowRender;

	void generateRenderInfo();

	const float innerMargin = 2.0f;
	const float outerLineThickness = 1.0f;

public:
	sf::Vector2i position;
	FontData fontData;

	Dropdown(const sf::Vector2i& position, int fields, const std::string * const titleStrings);
	Dropdown(const sf::Vector2i& position, int fields, const std::string * const titleStrings, const std::vector <std::string*>& elements);
	~Dropdown();

	void render() const;

	// getters
	int getFields() const { return fields; }
	int getExtendedHeight() const { return extendedHeight; }
	sf::Vector2i getSize() const { return size; }
};
