#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <ctime>
#include <sstream>

using namespace sf;

int main()
{
	srand(time(0));
	RenderWindow window(VideoMode(800, 600), "Pong Game!");
	window.setFramerateLimit(60);

	bool up = false, down = false, endGame = false;
	float leftPadSpeed = 0, rightPadSpeed = 0;
	float xBallSpeed = -8 * pow(-1, rand()%2), yBallSpeed = -8 * pow(-1, rand() % 2);
	int leftScore = 0, rightScore = 0;

	// Шрифт
	Font font;
	font.loadFromFile("RiseofKingdom.ttf");

	// Счет
	Text score;
	score.setFont(font);
	score.setCharacterSize(30);
	score.setPosition(370, 20);
	score.setString("0    0");



	// Текстуры
	Texture textureBackground;
	textureBackground.loadFromFile("background.png");

	RectangleShape background;
	background.setSize(Vector2f(800, 600));
	background.setPosition(0, 0);
	background.setTexture(&textureBackground);

	Texture textureLeftPad;
	textureLeftPad.loadFromFile("blue.png");

	RectangleShape leftPad;
	leftPad.setSize(Vector2f(28, 153));
	leftPad.setOrigin(14, 77);
	leftPad.setPosition(50, 300);
	leftPad.setTexture(&textureLeftPad);

	Texture textureRightPad;
	textureRightPad.loadFromFile("red.png");

	RectangleShape rightPad;
	rightPad.setSize(Vector2f(28, 151));
	rightPad.setOrigin(27, 75);
	rightPad.setPosition(750, 300);
	rightPad.setTexture(&textureRightPad);

	CircleShape ball;
	ball.setRadius(15);
	ball.setOrigin(15, 15);
	ball.setFillColor(Color(0, 255, 0));
	ball.setPosition(400, 300);

	while (window.isOpen())
	{
		Event event;
		if (endGame == false)
		{
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
				}

				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up)
				{
					up = true;
				}

				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down)
				{
					down = true;
				}

				if (event.type == Event::KeyReleased && event.key.code == Keyboard::Up)
				{
					up = false;
				}

				if (event.type == Event::KeyReleased && event.key.code == Keyboard::Down)
				{
					down = false;
				}
			}


			// Левая ракетка
			if (up == true)
			{
				leftPadSpeed = -5;
			}
			if (down == true)
			{
				leftPadSpeed = 5;
			}
			if (up == true && down == true)
			{
				leftPadSpeed = 0;
			}
			if (up == false && down == false)
			{
				leftPadSpeed = 0;
			}
			leftPad.move(0, leftPadSpeed);
			if (leftPad.getPosition().y < 88)
			{
				leftPad.setPosition(50, 90);
			}
			if (leftPad.getPosition().y > 505)
			{
				leftPad.setPosition(50, 510);
			}


			// Правая ракетка
			if (ball.getPosition().y < rightPad.getPosition().y)
			{
				rightPadSpeed = -5;
			}

			if (ball.getPosition().y > rightPad.getPosition().y)
			{
				rightPadSpeed = 5;
			}
			rightPad.move(0, rightPadSpeed);
			if (rightPad.getPosition().y < 77)
			{
				rightPad.setPosition(750, 85);
			}
			if (rightPad.getPosition().y > 523)
			{
				rightPad.setPosition(750, 517);
			}


			// Мяч
			ball.move(xBallSpeed, yBallSpeed);

			if (ball.getPosition().y < 10)
			{
				yBallSpeed = -yBallSpeed;
			}

			if (ball.getPosition().y > 590)
			{
				yBallSpeed = -yBallSpeed;
			}


			// Счет
			if (ball.getPosition().x < -50)
			{
				rightScore++;
				ball.setPosition(300, 200);
				rightPad.setPosition(750, 200);
				leftPad.setPosition(50, 300);
			}

			if (ball.getPosition().x > 800)
			{
				leftScore++;
				ball.setPosition(300, 200);
				rightPad.setPosition(750, 200);
				leftPad.setPosition(50, 300);
			}

			// Отражение мяча от левой ракетки
			if (ball.getGlobalBounds().intersects(leftPad.getGlobalBounds()) == true && ball.getPosition().x > 70)
			{
				xBallSpeed = -xBallSpeed;
			}

			// Отражение мяча от правой ракетки
			if (ball.getGlobalBounds().intersects(rightPad.getGlobalBounds()) == true && ball.getPosition().x < 720)
			{
				xBallSpeed = -xBallSpeed;
			}

			window.clear();


			if (leftScore > 7 || rightScore > 7)
			{
				std::cout << "End Game";

				if (leftScore > 7)
				{
					std::cout << "Blue wins";
				}
				if (rightScore > 7)
				{
					std::cout << "Red wins";
				}

				endGame = true;
			}

			window.draw(background);
			window.draw(leftPad);
			window.draw(rightPad);
			window.draw(ball);
			std::stringstream res;
			res << leftScore << "    " << rightScore;
			score.setString(res.str());
			window.draw(score);
			window.display();
		}

		if (endGame == true)
		{ 
			window.close();
			RenderWindow winner(VideoMode(800, 600), "Pong Game!");
			window.setFramerateLimit(60);

			Texture blueWinsBackground;
			blueWinsBackground.loadFromFile("blueWins.png");

			RectangleShape blueWins;
			blueWins.setSize(Vector2f(800, 600));
			blueWins.setPosition(0, 0);
			blueWins.setTexture(&blueWinsBackground);

			Texture redWinsBackground;
			redWinsBackground.loadFromFile("redWins.png");

			RectangleShape redWins;
			redWins.setSize(Vector2f(800, 600));
			redWins.setPosition(0, 0);
			redWins.setTexture(&redWinsBackground);

			while (winner.isOpen())
			{
				while (winner.pollEvent(event))
				{
					if (event.type == Event::Closed)
					{
						winner.close();
					}
				}


				if (leftScore > 7)
				{
					winner.clear();
					winner.draw(blueWins);
					winner.display();
				}
				if (rightScore > 7)
				{
					winner.clear();
					winner.draw(redWins);
					winner.display();
				}
			}
		}



		
	}
	
	window.close();

	return 0;
}
