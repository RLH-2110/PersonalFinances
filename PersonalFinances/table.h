#pragma once

#include "includes.h"

class Table
{

protected:
	int fields;
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
	sf::Vector2i position;
	FontData fontData;

	Table();
	Table(const Table& table);
	Table& operator=(const Table& other)
	{
		// Guard self assignment
		if (this == &other)
			return *this;


		try {
			Table ret(other);
			return ret;
		}
		catch (std::bad_alloc) {
			error(errorID::outOfMem);
			return *this;
		}
	}

	Table(const sf::Vector2i& position, int fields, const std::string * const titleStrings);
	Table(const sf::Vector2i& position, int fields, const std::string * const titleStrings, const std::vector <std::string*>& elements);

	Table(const sf::Vector2i& position, int fields, const std::string * const titleStrings, const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness);
	Table(const sf::Vector2i& position, int fields, const std::string * const titleStrings, const std::vector <std::string*>& elements, const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness);
	~Table();

	void render(sf::RenderWindow& window) const;

	// getters
	int getFields() const { return fields; }
	sf::Vector2i getSize() const { return size; }

	float getInnerMargin() const { return innerMargin; }
	float getOuterLineThickness() const { return outerLineThickness; }
	float getMainboxOuterLineThickness() const { return mainboxOuterLineThickness; }

	//setters

	void setInnerMargin(float value) { innerMargin = value; generateRenderInfo(); }
	void setOuterLineThickness(float value) { outerLineThickness = value;	generateRenderInfo(); }
	void setMainboxOuterLineThickness(float value) { mainboxOuterLineThickness = value;	generateRenderInfo(); }
};