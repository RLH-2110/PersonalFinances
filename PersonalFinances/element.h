#pragma once

#include "includes.h"

class Element
{
protected:

	sf::Vector2f size;
public:
	sf::Vector2f position;



	Element();
	Element(const Element& element);
	Element& operator=(const Element& other);
	
	Element(const sf::Vector2f& position);
	Element(const sf::Vector2f& position, const sf::Vector2f& size);

	bool isClicked(sf::Vector2i& position) const;

	void handleClick(sf::Vector2i& positon) {}; // will be overwritten

	// getters
	sf::Vector2f getSize() const { return size; }

};
