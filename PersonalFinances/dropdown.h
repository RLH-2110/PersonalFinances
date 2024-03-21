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

	const float outerLineThickness = 1.0f;
	const float mainboxOuterLineThickness = 1.0f;
public:
	const float innerMargin = 2.0f;

	sf::Vector2i position;
	FontData fontData;

	Dropdown(const sf::Vector2i& position, int fields, const std::string * const titleStrings);
	Dropdown(const sf::Vector2i& position, int fields, const std::string * const titleStrings, const std::vector <std::string*>& elements);
	~Dropdown();

	void render(sf::RenderWindow& window) const;

	// getters
	int getFields() const { return fields; }
	int getExtendedHeight() const { return extendedHeight; }
	sf::Vector2i getSize() const { return size; }
};
