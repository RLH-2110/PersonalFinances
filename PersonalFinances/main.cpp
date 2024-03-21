#include "test.h"
#include "includes.h"


//#define fileNotFoundDebug
#ifdef fileNotFoundDebug

#include <iostream>
#include <fstream>
#include <filesystem>

#endif // fileNotFoundDebug



FontData stdFont;

void init() {

#ifdef fileNotFoundDebug
	std::string filename = "./ComicMono.ttf";
	std::ifstream file(filename);

	if (file) {
		std::cout << "File exists.\n";
	}
	else {
		std::cout << "File not found. Full path: " << std::filesystem::absolute(filename) << std::endl;
	}

#endif // fileNotFoundDebug

	sf::Font sfFont;
	if (sfFont.loadFromFile("./ComicMono.ttf") == false) error(errorID::fontLoadError);

	stdFont.fontSize = 12;	//9
	stdFont.style = sf::Text::Regular;
	stdFont.font = sfFont;
		
}

int main()
{
	init();

#ifdef DEBUG
	test();
#endif // DEBUG

	

	

	/*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}*/

	



	return 0;
}