#pragma once

#include "includes.h"
#include "element.h"

#define tbl_mainbox rowRender.back()
#define tbl_addbox rowRender[rowRender.size() - 2]
#define tbl_rowRenderNormalElementLen  rowRender.size() - 2

class Table : public Element
{
protected:

	int fields;

	// arrays (all indexed by 'fields')
	std::wstring *titleStrings;
	std::vector <std::wstring*> elements;

	std::vector <sf::RectangleShape> rowRender;

	void generateRenderInfo();

	float innerMargin = 2.0f;
	float outerLineThickness = 1.0f;
	float mainboxOuterLineThickness = 1.0f;

	void initBorder(const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness);
	void vectorAssign(const std::vector <std::wstring*>& elements);

	void calculateSize();

public:
	FontData fontData;

	

	Table();
	Table(const Table& table);
	Table& operator=(const Table& other);

	Table(const sf::Vector2f& position, int fields, const std::wstring * const titleStrings);
	Table(const sf::Vector2f& position, int fields, const std::wstring * const titleStrings, const std::vector <std::wstring*>& elements);

	Table(const sf::Vector2f& position, int fields, const std::wstring * const titleStrings, const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness);
	Table(const sf::Vector2f& position, int fields, const std::wstring * const titleStrings, const std::vector <std::wstring*>& elements, const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness);
	

	Table(const sf::Vector2f& position, int fields, std::wstring*&& titleStrings);
	Table(const sf::Vector2f& position, int fields, std::wstring*&& titleStrings, const std::vector <std::wstring*>& elements);


	Table(const sf::Vector2f& position, int fields, std::wstring*&& titleStrings, const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness);
	Table(const sf::Vector2f& position, int fields, std::wstring*&& titleStrings, const std::vector <std::wstring*>& elements, const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness);

	~Table();

	void render(sf::RenderWindow& window) const;
	void renderText(sf::RenderWindow& window, const std::wstring& text, const sf::RectangleShape& rect) const; // rect = the field in wich the text is placed

	void addElement(const std::wstring * const element);
	void addElement(std::wstring*&& element);

	bool removeElement(unsigned int elementID);

	void handleClick(sf::Vector2i & position);

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
