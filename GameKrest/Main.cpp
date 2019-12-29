// libraries
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

//Global variables, classes, functions

int main()
{
	setlocale(LC_ALL, "rus");
	// ������ � �������������
	bool choice = false;
	int type_of_game = 0;
	int krest_or_zero = -1;
	while (choice == false)
	{
		std::cout << "����� ���������� � ���� ��������-������!\n";
		std::cout << "������� ����: ������ �� ������� ������ �� ��������� ������ ���� 3�3 ����� (���� ������ ��������, ������ ������ ������).\n";
		std::cout << "������, ����������� � ��� 3 ����� ������ �� ���������, ����������� ��� ���������, ����������. ������ ��� ������ �����, �������� ��������.\n";
		std::cout << "����� ��������� ������� ��� �����, �������� ����� ������� ���� �� ������ �������.\n";
		std::cout << "�������� ����� ����. ������� 1, ���� ������ ������ � ������ ���������; ������� 2, ���� ������ ������ � �����������: ";
		std::cin >> type_of_game;
		std::cout << "\n" << "������ �������� �� ����� ������ ������ ������. ������� 0, ���� ������ ������ ��������; ������� 1, ���� ������ ������ ����������: ";
		std::cin >> krest_or_zero;
		choice = true;
	}

	RenderWindow window(VideoMode(800, 800), "SFML Game");
	//Render shapes
	//Images
	sf::Texture white; //Image/texture object
	if (white.loadFromFile("Data/white.png") == 0) //Load an image, if not close the program
	{
		return 1;
	}

	sf::Texture krestik; //Image/texture object
	if (krestik.loadFromFile("Data/krestik.png") == 0) //Load an image, if not close the program
	{
		return 1;
	}

	sf::Texture nolik; //Image/texture object
	if (nolik.loadFromFile("Data/nolik.png") == 0) //Load an image, if not close the program
	{
		return 1;
	}

	//Rectangle shape
	RectangleShape rect0; //������ ������
	rect0.setSize(sf::Vector2f(200, 200)); //Width and height
	rect0.setPosition(100, 100); //Position
	rect0.setFillColor(sf::Color::White); //White fill color so we don't change the images colors
	rect0.setOutlineColor(sf::Color::Green);
	rect0.setOutlineThickness(1);
	rect0.setTexture(&white); //Bind an image/texture to the rectangle

	RectangleShape rect1; //������ ������
	rect1.setSize(sf::Vector2f(200, 200)); //Width and height
	rect1.setPosition(300, 100); //Position
	rect1.setFillColor(sf::Color::White); //White fill color so we don't change the images colors
	rect1.setOutlineColor(sf::Color::Green);
	rect1.setOutlineThickness(1);
	rect1.setTexture(&white); //Bind an image/texture to the rectangle

	RectangleShape rect2; //������ ������
	rect2.setSize(sf::Vector2f(200, 200)); //Width and height
	rect2.setPosition(500, 100); //Position
	rect2.setFillColor(sf::Color::White); //White fill color so we don't change the images colors
	rect2.setOutlineColor(sf::Color::Green);
	rect2.setOutlineThickness(1);
	rect2.setTexture(&white); //Bind an image/texture to the rectangle

	RectangleShape rect3; //��������� ������
	rect3.setSize(sf::Vector2f(200, 200)); //Width and height
	rect3.setPosition(100, 300); //Position
	rect3.setFillColor(sf::Color::White); //White fill color so we don't change the images colors
	rect3.setOutlineColor(sf::Color::Green);
	rect3.setOutlineThickness(1);
	rect3.setTexture(&white); //Bind an image/texture to the rectangle

	RectangleShape rect4; //����� ������
	rect4.setSize(sf::Vector2f(200, 200)); //Width and height
	rect4.setPosition(300, 300); //Position
	rect4.setFillColor(sf::Color::White); //White fill color so we don't change the images colors
	rect4.setOutlineColor(sf::Color::Green);
	rect4.setOutlineThickness(1);
	rect4.setTexture(&white); //Bind an image/texture to the rectangle

	RectangleShape rect5; //������ ������
	rect5.setSize(sf::Vector2f(200, 200)); //Width and height
	rect5.setPosition(500, 300); //Position
	rect5.setFillColor(sf::Color::White); //White fill color so we don't change the images colors
	rect5.setOutlineColor(sf::Color::Green);
	rect5.setOutlineThickness(1);
	rect5.setTexture(&white); //Bind an image/texture to the rectangle

	RectangleShape rect6; //������� ������
	rect6.setSize(sf::Vector2f(200, 200)); //Width and height
	rect6.setPosition(100, 500); //Position
	rect6.setFillColor(sf::Color::White); //White fill color so we don't change the images colors
	rect6.setOutlineColor(sf::Color::Green);
	rect6.setOutlineThickness(1);
	rect6.setTexture(&white); //Bind an image/texture to the rectangle

	RectangleShape rect7; //������� ������
	rect7.setSize(sf::Vector2f(200, 200)); //Width and height
	rect7.setPosition(300, 500); //Position
	rect7.setFillColor(sf::Color::White); //White fill color so we don't change the images colors
	rect7.setOutlineColor(sf::Color::Green);
	rect7.setOutlineThickness(1);
	rect7.setTexture(&white); //Bind an image/texture to the rectangle

	RectangleShape rect8; //������� ������
	rect8.setSize(sf::Vector2f(200, 200)); //Width and height
	rect8.setPosition(500, 500); //Position
	rect8.setFillColor(sf::Color::White); //White fill color so we don't change the images colors
	rect8.setOutlineColor(sf::Color::Green);
	rect8.setOutlineThickness(1);
	rect8.setTexture(&white); //Bind an image/texture to the rectangle

	// �������� ����������� ���� ���������
	bool proverka = false;
	int res = 0;
	int count = 1;
	bool play = true;
	bool leftClick=false;
	int mouseX = 0, mouseY = 0;
	int cells[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	// Render shapes
	Event event; // ������� ����� �������
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);
	// Game loop
	if (type_of_game == 1)
	{
		while (play == true)
		{

			// EVENTS
			// ���� ������� ����, ������������ ��
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
				{
					play = false;
				}
				//Left mouse button pressed down (clicked)
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				{
					leftClick = true;
				}

				//Mouse moved in the window
				if (event.type == sf::Event::MouseMoved)
				{
					mouseX = event.mouseMove.x; //X position of the mouse
					mouseY = event.mouseMove.y; //Y position of the mouse
				}
				if (event.type == sf::Event::Closed)
				{
					play = false;
				}
			}
			// Logic
			// ��������
			int i; // �������� �������. ���� �� ���� ����� �� ������� �� 0, ���� ������� ����� �� 1 ���� ������� ������� �� 2
				// ��������� ������� ������� ������

				// ��������� �� ���� �������       
			for (i = 0; i <= 2; i++)
			{
				// ��������  ��� �� � ������ ������
				if (cells[i][0] == 1 && cells[i][1] == 1 && cells[i][2] == 1) { res = 1; }
			}

			// ��������� �� ���� ��������     
			for (i = 0; i <= 2; i++)
			{
				// �������� ��� �� � ������� ������
				if (cells[0][i] == 1 && cells[1][i] == 1 && cells[2][i] == 1) { res = 1; }
			}

			// �������� ����������
			if (cells[0][0] == 1 && cells[1][1] == 1 && cells[2][2] == 1) { res = 1; }
			if (cells[2][0] == 1 && cells[1][1] == 1 && cells[0][2] == 1) { res = 1; }

			// ��������� ������� ������� ������
			// ��������� �� ���� �������       
			for (i = 0; i <= 2; i++)
			{
				// ��������  ��� �� � ������ ��������
				if (cells[i][1] == 2 && cells[i][2] == 2 && cells[i][2] == 2) { res = 2; }
			}

			// ��������� �� ���� ��������
			for (i = 0; i <= 2; i++)
			{
				// �������� ��� �� � ������� �������� 
				if (cells[1][i] == 2 && cells[2][i] == 2 && cells[2][i] == 2) { res = 2; }
			}

			// �������� ����������
			if (cells[0][0] == 2 && cells[1][1] == 2 && cells[2][2] == 2) { res = 2; }
			if (cells[2][0] == 2 && cells[1][1] == 2 && cells[0][2] == 2) { res = 2; }

			if (res == 0)
			{
				if (count == 1)
				{
					//If the left mouse button was clicked
					if (leftClick == true)
					{
						if (rect0.getGlobalBounds().contains(mouseX, mouseY))
						{
							if (cells[0][0] == 0)
							{
								rect0.setTexture(&krestik);
								count = 2;
								cells[0][0] = 1;
							}
						}
						if (rect1.getGlobalBounds().contains(mouseX, mouseY))
						{
							if (cells[0][1] == 0)
							{
								rect1.setTexture(&krestik);
								count = 2;
								cells[0][1] = 1;
							}
						}

						if (rect2.getGlobalBounds().contains(mouseX, mouseY))
						{
							if (cells[0][2] == 0)
							{
								rect2.setTexture(&krestik);
								count = 2;
								cells[0][2] = 1;
							}
						}

						if (rect3.getGlobalBounds().contains(mouseX, mouseY))
						{
							if (cells[1][0] == 0)
							{
								rect3.setTexture(&krestik);
								count = 2;
								cells[1][0] = 1;
							}
						}

						if (rect4.getGlobalBounds().contains(mouseX, mouseY))
						{
							if (cells[1][1] == 0)
							{
								rect4.setTexture(&krestik);
								count = 2;
								cells[1][1] = 1;
							}
						}

						if (rect5.getGlobalBounds().contains(mouseX, mouseY))
						{
							if (cells[1][2] == 0)
							{
								rect5.setTexture(&krestik);
								count = 2;
								cells[1][2] = 1;
							}
						}

						if (rect6.getGlobalBounds().contains(mouseX, mouseY))
						{
							if (cells[2][0] == 0)
							{
								rect6.setTexture(&krestik);
								count = 2;
								cells[2][0] = 1;
							}
						}

						if (rect7.getGlobalBounds().contains(mouseX, mouseY))
						{
							if (cells[2][1] == 0)
							{
								rect7.setTexture(&krestik);
								count = 2;
								cells[2][1] = 1;
							}
						}

						if (rect8.getGlobalBounds().contains(mouseX, mouseY))
						{
							if (cells[2][2] == 0)
							{
								rect8.setTexture(&krestik);
								count = 2;
								cells[2][2] = 1;
							}
						}
						leftClick = false;
					}
				}
				if (count == 2)
				{
					//If the left mouse button was clicked
					if (leftClick == true)
					{
						if (rect0.getGlobalBounds().contains(mouseX, mouseY))
						{
							if (cells[0][0] == 0)
							{
								rect0.setTexture(&nolik);
								count = 1;
								cells[0][0] = 2;
							}
						}

						if (rect1.getGlobalBounds().contains(mouseX, mouseY))
						{
							if (cells[0][1] == 0)
							{
								rect1.setTexture(&nolik);
								count = 1;
								cells[0][1] = 2;
							}
						}

						if (rect2.getGlobalBounds().contains(mouseX, mouseY))
						{
							if (cells[0][2] == 0)
							{
								rect2.setTexture(&nolik);
								count = 1;
								cells[0][2] = 2;
							}
						}

						if (rect3.getGlobalBounds().contains(mouseX, mouseY))
						{
							if (cells[1][0] == 0)
							{
								rect3.setTexture(&nolik);
								count = 1;
								cells[1][0] = 2;
							}
						}

						if (rect4.getGlobalBounds().contains(mouseX, mouseY))
						{
							if (cells[1][1] == 0)
							{
								rect4.setTexture(&nolik);
								count = 1;
								cells[1][1] = 2;
							}
						}

						if (rect5.getGlobalBounds().contains(mouseX, mouseY))
						{
							if (cells[1][2] == 0)
							{
								rect5.setTexture(&nolik);
								count = 1;
								cells[1][2] = 2;
							}
						}

						if (rect6.getGlobalBounds().contains(mouseX, mouseY))
						{
							if (cells[2][0] == 0)
							{
								rect6.setTexture(&nolik);
								count = 1;
								cells[2][0] = 2;
							}
						}

						if (rect7.getGlobalBounds().contains(mouseX, mouseY))
						{
							if (cells[2][1] == 0)
							{
								rect7.setTexture(&nolik);
								count = 1;
								cells[2][1] = 2;
							}
						}

						if (rect8.getGlobalBounds().contains(mouseX, mouseY))
						{
							if (cells[2][2] == 0)
							{
								rect8.setTexture(&nolik);
								count = 1;
								cells[2][2] = 2;
							}
						}
						leftClick = false;
					}
				}

			}
			if (res == 1)
			{
				std::cout << "������ ��������! ������� ������, ����� ����� �� ����.";
			}
			if (res == 2)
			{
				std::cout << "�������� ��������! ������� ������, ����� ����� �� ����.";
			}

			// Rendering
			window.clear();
			window.draw(rect0);
			window.draw(rect1);
			window.draw(rect2);
			window.draw(rect3);
			window.draw(rect4);
			window.draw(rect5);
			window.draw(rect6);
			window.draw(rect7);
			window.draw(rect8);
			window.display();
		}
		// Clean up
		window.close();
		return 0;
	}
}


//	while (play == true)
//	{
//
//		// EVENTS
//		Event event; // ������� ����� �������
//		// ���� ������� ����, ������������ ��
//		while (window.pollEvent(event))
//		{
//
//			if (event.type == sf::Event::Closed)
//			{
//				play = false;
//			}
//		}
//		// Logic
//
//		// Rendering
//		window.clear();
//		window.draw(rect0);
//		window.draw(rect1);
//		window.draw(rect2);
//		window.draw(rect3);
//		window.draw(rect4);
//		window.draw(rect5);
//		window.draw(rect6);
//		window.draw(rect7);
//		window.draw(rect8);
//		window.display();
//	}
//	// Clean up
//	window.close();
//	return 0;
//}



//	RenderWindow window (VideoMode(800, 600), "SFML Game");
//	bool play = true;
//	bool apressed = false;
//	bool areleased = false;
//	int mouseX=0, mouseY=0;
//	// Render shapes
//	Event event; // ������� ����� �������
//	window.setFramerateLimit(60);
//	window.setKeyRepeatEnabled(false);
//    // Game loop
//	while (play == true)
//	{
//
//		// EVENTS
//		Event event; // ������� ����� �������
//		// ���� ������� ����, ������������ ��
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::KeyPressed and event.key.code == Keyboard::A)
//				apressed = true;
//			if (event.type == sf::Event::KeyReleased and event.key.code == Keyboard::A)
//				areleased = true;
//			if (event.type == sf::Event::Closed)
//			{
//				play = false;
//			}
//		}
//		// Logic
//		if (apressed == true)
//		{
//			std::cout << "A has been pressed";
//			apressed = false;
//		}
//		if (areleased == true)
//		{
//			std::cout << "A has been released";
//			areleased = false;
//		}
//		// Rendering
//		window.clear();
//
//		window.display();
//	}
//	// Clean up
//	window.close();
//	return 0;
//}