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
	Dropdown& operator=(const Dropdown& other)
	{
		// Guard self assignment
		if (this == &other)
			return *this;


		try {
			Dropdown ret(other);
			return ret;
		}
		catch (std::bad_alloc) {
			error(errorID::outOfMem);
			return *this;
		}
	}

	Dropdown(const sf::Vector2f& position, int fields, const std::string * const titleStrings);
	Dropdown(const sf::Vector2f& position, int fields, const std::string * const titleStrings, const std::vector <std::string*>& elements);

	Dropdown(const sf::Vector2f& position, int fields, const std::string * const titleStrings, const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness);
	Dropdown(const sf::Vector2f& position, int fields, const std::string * const titleStrings, const std::vector <std::string*>& elements, const float innerMargin, const float outerLineThickness, const float mainboxOuterLineThickness);
	~Dropdown();

	void render(sf::RenderWindow& window) const;

	// getters
	int getExtendedHeight() const { return extendedHeight; }
	bool getExtended() const { return extended; }

	// setters
	void setExtended(bool extended) { this->extended = extended; }
};
