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
		sf::RenderWindow window(sf::VideoMode(200, 400), "Dropdown Test Window");


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

		int leftOffset = 4;

		Dropdown dp1 = Dropdown(sf::Vector2i(leftOffset, 5), 1, bar,1,1,1);
		Dropdown dp2 = Dropdown(sf::Vector2i(leftOffset, 50), 1, bar, barFields,1,1,1);


		std::string bar2[] = { "Ex1", "Ex2", "" };

		barFields.clear();

		// fill in some valid test data
		std::string data3[] = { "data1","data2","" };
		barFields.push_back(data3);
		std::string data4[] = { "data3","data4","" };
		barFields.push_back(data4);
		std::string data5[] = { "data5","data6","" };
		barFields.push_back(data5);

		Dropdown dp3 = Dropdown(sf::Vector2i(leftOffset, 150), 2, bar2, barFields, 1, 1, 1);

		std::string bar3[] = { "ID", "ABC", "123","" };

		barFields.clear();

		// fill in some valid test data
		std::string data6[] = { "1","ABC","123","" };
		barFields.push_back(data6);
		std::string data7[] = { "2","DEF","456","" };
		barFields.push_back(data7);
		std::string data8[] = { "3","GHI","789","" };
		barFields.push_back(data8);

		Dropdown dp4 = Dropdown(sf::Vector2i(leftOffset, 250), 3, bar3, barFields, 1, 1, 1);

		int i = 1;
		int j = 1;
		int l = 1;

		sf::Text status;
		status.setFont(stdFont.font);
		status.setCharacterSize(stdFont.fontSize);
		status.setPosition(100, 5);
		status.setFillColor(sf::Color::Black);

		status.setString("i:1 j:1 l:1");

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();

				if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::Space) {
						i++;
						if (i > 5) {
							i = 1;
							j++;
							if (j > 5) {
								j = 1;
								l++;
								if (l > 5) l = 1;

								dp1.setInnerMargin(l);
								dp2.setInnerMargin(l);
								dp3.setInnerMargin(l);
								dp4.setInnerMargin(l);
							}
							dp1.setOuterLineThickness(j);
							dp2.setOuterLineThickness(j);
							dp3.setOuterLineThickness(j);
							dp4.setOuterLineThickness(j);
						}
						dp1.setMainboxOuterLineThickness(i);
						dp2.setMainboxOuterLineThickness(i);
						dp3.setMainboxOuterLineThickness(i);
						dp4.setMainboxOuterLineThickness(i);

					}
					std::string str = "i:" + std::to_string(i) + " j:" + std::to_string(j) + " l:" + std::to_string(l) + "";
					status.setString(str);

				}
			}

			window.clear(sf::Color::White);
			dp1.render(window);
			dp2.render(window);
			dp3.render(window);
			dp4.render(window);
			window.draw(status);
			window.display();
		}

	}
}

#endif