#include "includes.h"

#ifdef DEBUG



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
	/*{
		std::string bar[] = { "hello world", "" };
		Dropdown foo = Dropdown(sf::Vector2i(0, 0), 1, bar);
	}*/

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

	// render test
	{
		sf::RenderWindow window(sf::VideoMode(100, 300), "Dropdown Test Window");


		sf::Text text("Hello world!\nHallo Welt!", stdFont.font, stdFont.fontSize * 2);
		text.setStyle(text.Bold | text.Italic | text.Underlined | text.StrikeThrough);



		std::string bar[] = { "hello world", "" };

		std::vector<std::string*> barFields;

		// fill in some valid test data
		std::string data[] = { "This1","" };
		barFields.push_back(data);
		std::string data1[] = { "nanam","" };
		barFields.push_back(data1);
		std::string data2[] = { "last string!!!!!!!!!!!!!!!!","" };
		barFields.push_back(data2);



		Dropdown dp1 = Dropdown(sf::Vector2i(1, 0), 1, bar);
		Dropdown dp2 = Dropdown(sf::Vector2i(1, 50), 1, bar, barFields);


		std::string bar2[] = { "Ex1", "Ex2", "" };

		barFields.clear();

		// fill in some valid test data
		std::string data3[] = { "data1","data2","" };
		barFields.push_back(data3);
		std::string data4[] = { "data3","data4","" };
		barFields.push_back(data4);
		std::string data5[] = { "data5","data6","" };
		barFields.push_back(data5);

		Dropdown dp3 = Dropdown(sf::Vector2i(1, 150), 2, bar2, barFields);

		std::string bar3[] = { "ID", "ABC", "123","" };

		barFields.clear();

		// fill in some valid test data
		std::string data6[] = { "1","ABC","123","" };
		barFields.push_back(data6);
		std::string data7[] = { "2","DEF","456","" };
		barFields.push_back(data7);
		std::string data8[] = { "3","GHI","789","" };
		barFields.push_back(data8);

		Dropdown dp4 = Dropdown(sf::Vector2i(1, 220), 3, bar3, barFields);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear(sf::Color::White);
			dp1.render(window);
			dp2.render(window);
			dp3.render(window);
			dp4.render(window);
			window.display();
		}

	}
}

#endif