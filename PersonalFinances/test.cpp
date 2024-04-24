#include "includes.h"

#ifdef DEBUG



void dropdownTests();
void fontTest();
void tableTests();

void test() {
	
	//fontTest();
	tableTests();
	//dropdownTests();
	

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

void tableTests() {
	
	// constructor 1, valid data
	/*{
		std::wstring bar[] = { L"hello world", L"" };
		Table foo = Table(sf::Vector2i(0, 0), 1, bar);
	}*/

	// constructor 2, valid data
	/*{
		std::wstring bar[] = { L"hello world", L"" };
		std::vector<std::wstring*> barFields;

		// fill in some valid test data
		std::wstring data[] = { L"This1",L"" };
		barFields.push_back(data);
		std::wstring data1[] = { L"nanam",L"" };
		barFields.push_back(data1);
		std::wstring data2[] = { L"last string!!!!!!!!!!!!!!!!",L"" };
		barFields.push_back(data2);

		Table foo = Table(sf::Vector2i(0, 0), 1, bar,barFields);
	}*/

	// constructor 1 and 2, invalid data
	/*{
		{
			std::wstring bar[] = { L"hello world", L"affe",L"" };
			Table foo = Table(sf::Vector2i(0, 0), 1, bar);
		}
		{
			std::wstring bar[] = { L"hello world", L"huhn",L"" };
			std::vector<std::wstring*> barFields;

			// fill in some valid test data
			std::wstring data[] = { L"This1",L"po",L"" };
			barFields.push_back(data);
			std::wstring data2[] = { L"nanam",L"15454",L"45",L"" };
			barFields.push_back(data2);
			std::wstring data3[] = { L"last string!!!!!!!!!!!!!!!!",L"emaf",L"",L"",L"",L"Jafsa" };
			barFields.push_back(data3);
			std::wstring data4[] = { L"", L"" };
			barFields.push_back(data4);

			Table foo = Table(sf::Vector2i(0, 0), 1, bar, barFields);
		}
	}*/

	// render test
	{
		sf::RenderWindow window(sf::VideoMode(250, 600), "Table Test Window");


		sf::Text text("Hello world!\nHallo Welt!", stdFont.font, stdFont.fontSize * 2);
		text.setStyle(text.Bold | text.Italic | text.Underlined | text.StrikeThrough);



		wstrVector bar = { L"hello world" };

		std::vector<wstrVector> barFields;

		// fill in some valid test data
		barFields.emplace_back(wstrVector{L"This1"});
		barFields.emplace_back(wstrVector{L"nanam"});
		barFields.emplace_back(wstrVector{ L"last string!!!!!!!!!!!!!!!!" });

		float leftOffset = 4;
		bool displaySize = false;

		Table tbl1 = Table(sf::Vector2f(leftOffset, 5.0f), 1, bar, 1, 1, 1);
		Table tbl2 = Table(sf::Vector2f(leftOffset, 100.0f), 1, bar, barFields, 1, 1, 1);


		wstrVector bar2 = { L"Ex1 ", L"Ex2 "};

		barFields.clear();

		// fill in some valid test data
		barFields.emplace_back(wstrVector{ L"data1", L"data2" });
		barFields.emplace_back(wstrVector{ L"data3", L"data4" });
		barFields.emplace_back(wstrVector{ L"data5", L"data6" });

		Table tbl3 = Table(sf::Vector2f(leftOffset, 250.0f), 2, std::move(bar2), barFields, 1, 1, 1);

		wstrVector bar3 = { L"ID", L"ABC", L"123R$"};

		barFields.clear();

		// fill in some valid test data
		barFields.emplace_back(wstrVector{L"1", L"ABC", L"123€"});
		barFields.emplace_back(wstrVector{L"2", L"DEF", L"456₱"});
		barFields.emplace_back(wstrVector{L"3", L"GHI", L"789£"});

		Table tbl4 = Table(sf::Vector2f(leftOffset, 400.0f), 3, std::move(bar3), barFields, 1, 1, 1);

		float i = 1;
		float j = 1;
		float l = 1;

		sf::Text status;
		status.setFont(stdFont.font);
		status.setCharacterSize(stdFont.fontSize);
		status.setPosition(150, 5);
		status.setFillColor(sf::Color::Black);

		status.setString("i:1 j:1 l:1");

		sf::Text instruct = status;
		instruct.setPosition(5, 570);
		instruct.setString("Space,Return,LShift,RShift");


		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();

				if (event.type == sf::Event::MouseButtonPressed) {
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					tbl1.handleClick(mousePos);
					tbl2.handleClick(mousePos);
					tbl3.handleClick(mousePos);
					tbl4.handleClick(mousePos);

				}

				if (event.type == sf::Event::KeyPressed) {

					if (event.key.code == sf::Keyboard::Return)
						displaySize = !displaySize;

					if (event.key.code == sf::Keyboard::LShift) {
						tbl4.addElement( wstrVector { L"MoreData1",L"MoreData2",L"MoreData3"});
					}

					if (event.key.code == sf::Keyboard::RShift) {
						tbl4.removeElement(3);
					}

					if (event.key.code == sf::Keyboard::Space) {
						i++;
						if (i > 5) {
							i = 1;
							j++;
							if (j > 5) {
								j = 1;
								l++;
								if (l > 5) l = 1;

								tbl1.setInnerMargin(l);
								tbl2.setInnerMargin(l);
								tbl3.setInnerMargin(l);
								tbl4.setInnerMargin(l);
							}
							tbl1.setOuterLineThickness(j);
							tbl2.setOuterLineThickness(j);
							tbl3.setOuterLineThickness(j);
							tbl4.setOuterLineThickness(j);
						}
						tbl1.setMainboxOuterLineThickness(i);
						tbl2.setMainboxOuterLineThickness(i);
						tbl3.setMainboxOuterLineThickness(i);
						tbl4.setMainboxOuterLineThickness(i);

					}
					std::wstring str = L"i:" + std::to_wstring(i) + L" j:" + std::to_wstring(j) + L" l:" + std::to_wstring(l) + L"";
					status.setString(str);

				}
			}

#ifdef DEBUG
			sf::RectangleShape showSize;
			showSize.setFillColor(sf::Color::Transparent);
			showSize.setOutlineThickness(1.0f);
			showSize.setOutlineColor(sf::Color::Magenta);

#endif // DEBUG

			window.clear(sf::Color::White);
			tbl1.render(window);
			tbl2.render(window);
			tbl3.render(window);
			tbl4.render(window);

			window.draw(instruct);
			window.draw(status);

			if (displaySize) {
				showSize.setPosition(tbl1.position);
				showSize.setSize(tbl1.getSize());
				window.draw(showSize);

				showSize.setPosition(tbl2.position);
				showSize.setSize(tbl2.getSize());
				window.draw(showSize);

				showSize.setPosition(tbl3.position);
				showSize.setSize(tbl3.getSize());
				window.draw(showSize);

				showSize.setPosition(tbl4.position);
				showSize.setSize(tbl4.getSize());
				window.draw(showSize);
			}

			window.display();

		}

	}
	
}

void dropdownTests() {
	

	// constructor 1, valid data
	/*{
		std::wstring bar[] = { L"hello world", L"" };
		Dropdown foo = Dropdown(sf::Vector2i(0, 0), 1, bar);
	}*/

	// constructor 2, valid data
	/*{
		std::wstring bar[] = { L"hello world", L"" };
		std::vector<std::wstring*> barFields;

		// fill in some valid test data
		std::wstring data[] = { L"This1",L"" };
		barFields.push_back(data);
		std::wstring data1[] = { L"nanam",L"" };
		barFields.push_back(data1);
		std::wstring data2[] = { L"last string!!!!!!!!!!!!!!!!",L"" };
		barFields.push_back(data2);

		Dropdown foo = Dropdown(sf::Vector2i(0, 0), 1, bar,barFields);
	}*/

	// constructor 1 and 2, invalid data
	/*{
		{
			std::wstring bar[] = { L"hello world", L"affe",L"" };
			Dropdown foo = Dropdown(sf::Vector2i(0, 0), 1, bar);
		}
		{
			std::wstring bar[] = { L"hello world", L"huhn",L"" };
			std::vector<std::wstring*> barFields;

			// fill in some valid test data
			std::wstring data[] = { L"This1",L"po",L"" };
			barFields.push_back(data);
			std::wstring data2[] = { L"nanam",L"15454",L"45",L"" };
			barFields.push_back(data2);
			std::wstring data3[] = { L"last string!!!!!!!!!!!!!!!!",L"emaf",L"",L"",L"",L"Jafsa" };
			barFields.push_back(data3);
			std::wstring data4[] = { L"", L"" };
			barFields.push_back(data4);

			Dropdown foo = Dropdown(sf::Vector2i(0, 0), 1, bar, barFields);
		}
	}*/

	// render test
	/*{
		sf::RenderWindow window(sf::VideoMode(200, 400), L"Dropdown Test Window");


		sf::Text text("Hello world!\nHallo Welt!", stdFont.font, stdFont.fontSize * 2);
		text.setStyle(text.Bold | text.Italic | text.Underlined | text.StrikeThrough);



		std::wstring bar[] = { L"hello world", L"" };

		std::vector<std::wstring*> barFields;

		// fill in some valid test data
		std::wstring data[] = { L"This1",L"" };
		barFields.push_back(data);
		std::wstring data1[] = { L"nanam",L"" };
		barFields.push_back(data1);
		std::wstring data2[] = { L"last string!!!!!!!!!!!!!!!!",L"" };
		barFields.push_back(data2);

		int leftOffset = 4;

		Dropdown dp1 = Dropdown(sf::Vector2i(leftOffset, 5), 1, bar,1,1,1);
		Dropdown dp2 = Dropdown(sf::Vector2i(leftOffset, 50), 1, bar, barFields,1,1,1);


		std::wstring bar2[] = { L"Ex1", L"Ex2", L"" };

		barFields.clear();

		// fill in some valid test data
		std::wstring data3[] = { L"data1",L"data2",L"" };
		barFields.push_back(data3);
		std::wstring data4[] = { L"data3",L"data4",L"" };
		barFields.push_back(data4);
		std::wstring data5[] = { L"data5",L"data6",L"" };
		barFields.push_back(data5);

		Dropdown dp3 = Dropdown(sf::Vector2i(leftOffset, 150), 2, bar2, barFields, 1, 1, 1);

		std::wstring bar3[] = { L"ID", L"ABC", L"123",L"" };

		barFields.clear();

		// fill in some valid test data
		std::wstring data6[] = { L"1",L"ABC",L"123",L"" };
		barFields.push_back(data6);
		std::wstring data7[] = { L"2",L"DEF",L"456",L"" };
		barFields.push_back(data7);
		std::wstring data8[] = { L"3",L"GHI",L"789",L"" };
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
					std::wstring str = L"i:" + std::to_string(i) + L" j:" + std::to_string(j) + L" l:" + std::to_string(l) + L"";
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

	}*/
}

#endif