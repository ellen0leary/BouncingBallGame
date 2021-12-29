
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platform.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 900), "Bouncing Ball");

	//Player class and sprite
	sf::RectangleShape circle(sf::Vector2f(40,40));
	circle.setFillColor(sf::Color::Color(206,137,100));
	circle.setPosition(160, 800);

	Player player;
	player.move.setPos(160, 800);

	//Platforms
	sf::RectangleShape rect(sf::Vector2f(60, 20));
	rect.setFillColor(sf::Color::Green);
	rect.setPosition(100, 600);

	Platform platform;
	platform.move.setPos(100, 600);


	sf::RectangleShape rect1(sf::Vector2f(60, 20));
	rect1.setFillColor(sf::Color::Color(155,126,70));
	rect1.setPosition(400, 700);

	Platform platform1;
	platform1.move.setPos(400, 700);


	bool spacePressed = false;
	int movementTime = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) {
				std::cout << "Key Pressed" << std::endl;
				if (event.key.code == sf::Keyboard::Space) {
					std::cout << "space Pressed" << std::endl;
					movementTime = 200;
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			//move left
			player.move.moveLeft();
			if (player.collide.checkCollision(player.move.getXPosition(), player.move.getYPosition(), platform.move.getXPosition(), platform.move.getYPosition(), 60, 20)) {
				player.move.moveRight();
				player.move.moveRight();
				player.move.moveRight();
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			//move right
			player.move.moveRight();
			if (player.collide.checkCollision(player.move.getXPosition(), player.move.getYPosition(), platform.move.getXPosition(), platform.move.getYPosition(), 60, 20)) {
				player.move.moveLeft();
				player.move.moveLeft();
				player.move.moveLeft();
			}
		}


		if (movementTime > 0 ) {
			player.move.move();
			circle.setPosition(player.move.getXPosition(), player.move.getYPosition());
			if (player.collide.checkCollision(player.move.getXPosition(), player.move.getYPosition(), platform.move.getXPosition(), platform.move.getYPosition(), 60, 20)) {
				player.move.gravity();
				circle.setPosition(player.move.getXPosition(), player.move.getYPosition());
			}
			platform.move.gravity();
			rect.setPosition(platform.move.getXPosition(), platform.move.getYPosition());
			movementTime--;
		}
		if (!player.collide.checkCollision(player.move.getXPosition(), player.move.getYPosition(), platform.move.getXPosition(), platform.move.getYPosition(), 60, 20)) {
			player.move.gravity();
			circle.setPosition(player.move.getXPosition(), player.move.getYPosition());
		}
		

		window.clear();
		window.draw(circle);
		window.draw(rect);
		window.draw(rect1);
		window.display();
	}

	return 0;
}


//player
//enemy
//plateforms
	//static
	// falling
	//boost
//items

//poisisitoin - movement
// collider