#pragma once

#include "includes.h"

class Dropdown : public Table
{
protected:

	int extendedHeight;
	bool extended = true;

	void generateRenderInfo();
public:
	
	Dropdown();
	Dropdown(const Dropdown& dropdown);
	Dropdown& operator=(const Dropdown& other);

	Dropdown(const sf::Vector2f& position, int fields, const std::wstring * const titleStrings);
	Dropdown(const sf::Vector2f& position, int fields, const std::wstring * const titleStrings, const std::vector <std::wstring*>& elements);

	Dropdown(const sf::Vector2f& position, int fields, const std::wstring * const titleStrings, const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness);
	Dropdown(const sf::Vector2f& position, int fields, const std::wstring * const titleStrings, const std::vector <std::wstring*>& elements, const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness);
	~Dropdown();

	void render(sf::RenderWindow& window) const;

	// getters
	int getExtendedHeight() const { return extendedHeight; }
	bool getExtended() const { return extended; }

	// setters
	void setExtended(bool extended) { this->extended = extended; }
};
