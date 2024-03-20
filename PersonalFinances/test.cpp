#ifdef DEBUG

#include "includes.h"

void dropdownTests();
void fontTest();

void test() {
	
	//fontTest();
	dropdownTests();
	

}

void fontTest() {
	sf::RenderWindow window(sf::VideoMode(200, 60), "Font Test Window");
	sf::Text text("Hello world!\nHallo Welt!", stdFont.font, stdFont.fontSize * 2);
	text.setStyle(text.Bold | text.Italic | text.Underlined | text.StrikeThrough);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(text);
		window.display();
	}
}

void dropdownTests() {

	// constructor 1, valid data
	{
		std::string bar[] = { "hello world", "" };
		Dropdown foo = Dropdown(sf::Vector2i(0, 0), 1, bar);
	}

	// constructor 2, valid data
	/*{
		std::string bar[] = { "hello world", "" };
		std::vector<std::string*> barFields;

		// fill in some valid test data
		std::string data[] = { "This1","" };
		barFields.push_back(data);
		std::string data1[] = { "nanam","" };
		barFields.push_back(data1);
		std::string data2[] = { "last string!!!!!!!!!!!!!!!!","" };
		barFields.push_back(data2);

		Dropdown foo = Dropdown(sf::Vector2i(0, 0), 1, bar,barFields);
	}*/

	// constructor 1 and 2, invalid data
	/*{
		{
			std::string bar[] = { "hello world", "affe","" };
			Dropdown foo = Dropdown(sf::Vector2i(0, 0), 1, bar);
		}
		{
			std::string bar[] = { "hello world", "huhn","" };
			std::vector<std::string*> barFields;

			// fill in some valid test data
			std::string data[] = { "This1","po","" };
			barFields.push_back(data);
			std::string data2[] = { "nanam","15454","45","" };
			barFields.push_back(data2);
			std::string data3[] = { "last string!!!!!!!!!!!!!!!!","emaf","","","","Jafsa" };
			barFields.push_back(data3);
			std::string data4[] = { "", "" };
			barFields.push_back(data4);

			Dropdown foo = Dropdown(sf::Vector2i(0, 0), 1, bar, barFields);
		}
	}*/

}

#endif