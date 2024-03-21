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

	float innerMargin = 2.0f;
	float outerLineThickness = 1.0f;
	float mainboxOuterLineThickness = 1.0f;

	void initBorder(const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness);
public:
	bool extended = true;

	sf::Vector2i position;
	FontData fontData;

	Dropdown(const sf::Vector2i& position, int fields, const std::string * const titleStrings);
	Dropdown(const sf::Vector2i& position, int fields, const std::string * const titleStrings, const std::vector <std::string*>& elements);

	Dropdown(const sf::Vector2i& position, int fields, const std::string * const titleStrings, const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness);
	Dropdown(const sf::Vector2i& position, int fields, const std::string * const titleStrings, const std::vector <std::string*>& elements, const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness);
	~Dropdown();

	void render(sf::RenderWindow& window) const;

	// getters
	int getFields() const { return fields; }
	int getExtendedHeight() const { return extendedHeight; }
	sf::Vector2i getSize() const { return size; }

	float getInnerMargin() const { return innerMargin; }
	float getOuterLineThickness() const { return outerLineThickness; }
	float getMainboxOuterLineThickness() const { return mainboxOuterLineThickness; }

	//setters

	void setInnerMargin(float value) { innerMargin = value; generateRenderInfo(); }
	void setOuterLineThickness(float value) {	outerLineThickness = value;	generateRenderInfo(); 	}
	void setMainboxOuterLineThickness(float value) {	mainboxOuterLineThickness = value;	generateRenderInfo(); }

};
