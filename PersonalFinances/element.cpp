#pragma once

#include "includes.h"
#include "element.h"



Element::Element() {
	position = sf::Vector2f(0, 0);
	size = position;
}

Element::Element(const Element& element) {
	size = element.size;
	position = element.position;
}

Element& Element::operator=(const Element& other)
{
	// Guard self assignment
	if (this == &other)
		return *this;

	try {
		Element ret(other);
		return ret;
	}
	catch (std::bad_alloc) {
		error(errorID::outOfMem);
		return *this;
	}
}

Element::Element(const sf::Vector2f& position) {
	this->position = position;
	size = sf::Vector2f(0, 0);
}
Element::Element(const sf::Vector2f& position, const sf::Vector2f& size) {
	this->position = position;
	this->size = size;
}

bool Element::isClicked(sf::Vector2i& position) const {
	sf::Vector2f mousePos((float)(position.x), (float)(position.y)); // convert it to float, since I fear compareing ints to floatsS

	if (	mousePos.x >= this->position.x	&& mousePos.x <= this->position.x + this->size.x)
		if (mousePos.y >= this->position.y	&& mousePos.y <= this->position.y + this->size.y)
			return true;

	return false;
}

