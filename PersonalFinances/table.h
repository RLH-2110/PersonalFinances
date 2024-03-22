#pragma once

#include "includes.h"

#define tbl_mainbox rowRender.back()
#define tbl_addbox rowRender[rowRender.size() - 2]
#define tbl_rowRenderNormalElementLen  rowRender.size() - 2

class Table
{
protected:

	int fields;
	sf::Vector2f size;

	// arrays (all indexed by 'fields')
	std::string *titleStrings;
	std::vector <std::string*> elements;

	std::vector <sf::RectangleShape> rowRender;

	void generateRenderInfo();

	float innerMargin = 2.0f;
	float outerLineThickness = 1.0f;
	float mainboxOuterLineThickness = 1.0f;

	void initBorder(const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness);
	void vectorAssign(const std::vector <std::string*>& elements);

	void calculateSize();

public:
	sf::Vector2f position;
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

	Table(const sf::Vector2f& position, int fields, const std::string * const titleStrings);
	Table(const sf::Vector2f& position, int fields, const std::string * const titleStrings, const std::vector <std::string*>& elements);

	Table(const sf::Vector2f& position, int fields, const std::string * const titleStrings, const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness);
	Table(const sf::Vector2f& position, int fields, const std::string * const titleStrings, const std::vector <std::string*>& elements, const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness);
	

	Table(const sf::Vector2f& position, int fields, std::string*&& titleStrings);
	Table(const sf::Vector2f& position, int fields, std::string*&& titleStrings, const std::vector <std::string*>& elements);


	Table(const sf::Vector2f& position, int fields, std::string*&& titleStrings, const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness);
	Table(const sf::Vector2f& position, int fields, std::string*&& titleStrings, const std::vector <std::string*>& elements, const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness);

	~Table();

	void render(sf::RenderWindow& window) const;
	void renderText(sf::RenderWindow& window, std::string text, sf::Vector2f position) const;

	void addElement(const std::string * const element);
	void addElement(std::string*&& element);

	bool removeElement(int elementID);

	// getters
	int getFields() const { return fields; }
	sf::Vector2f getSize() const { return size; }

	float getInnerMargin() const { return innerMargin; }
	float getOuterLineThickness() const { return outerLineThickness; }
	float getMainboxOuterLineThickness() const { return mainboxOuterLineThickness; }

	const sf::RectangleShape getAddbox() const {
		if (fields == 0 || rowRender.size() < 2) {
			puts("No Addbox defined!");
			return sf::RectangleShape();
		}
		return tbl_addbox;
	}

	//setters

	void setInnerMargin(float value) { innerMargin = value; generateRenderInfo(); }
	void setOuterLineThickness(float value) { outerLineThickness = value;	generateRenderInfo(); }
	void setMainboxOuterLineThickness(float value) { mainboxOuterLineThickness = value;	generateRenderInfo(); }

};
