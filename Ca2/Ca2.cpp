
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
//#include <stdio.h>
#include <stdlib.h> //for random
#include <time.h> // for random seed

//custom classes
#include "Player.h"
#include "Platform.h"
int main()
{
	const int sreenWidth = 400;
	const int screenHeight = 900;
	const float platformHeight = 20;
	sf::RenderWindow window(sf::VideoMode(sreenWidth, screenHeight), "Bouncing Ball");

	//Player class and sprite
	sf::CircleShape circle(20.0f);
	circle.setFillColor(sf::Color::Color(206, 137, 100));
	circle.setPosition(160, 800);

	Player player;
	player.move.setPos(160, 800);

	////Platforms
	/*Platform plateforms[5];
	sf::RectangleShape rectangles[5];*/
	std::vector<Platform> platforms;
	std::vector<sf::RectangleShape> rectanges;

	sf::RectangleShape rect(sf::Vector2f(60, platformHeight));
	rect.setFillColor(sf::Color::Green);
	rect.setPosition(100, 600);

	Platform platform;
	platform.move.setPos(100, 600);
	platforms.push_back(platform);


	sf::RectangleShape rect1(sf::Vector2f(60, platformHeight));
	rect1.setFillColor(sf::Color::Color(155, 126, 70));
	rect1.setPosition(300, 700);

	Platform platform1;
	platform1.move.setPos(400, 700);


	//values
	bool spacePressed = false;
	int movementTime = 0;
	int difficulty = 5;

	srand(time(0));

	while (window.isOpen())
	{
		//input
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
			for (auto plate: platforms) {
				if (player.collide.checkCollision(player.move.getXPosition(), player.move.getYPosition(), plate.move.getXPosition(), plate.move.getYPosition(), 60, platformHeight)) {
					player.move.moveRight();
					player.move.moveRight();
					player.move.moveRight();
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			//move right
			player.move.moveRight();
			for (auto plate: platforms){
				if (player.collide.checkCollision(player.move.getXPosition(), player.move.getYPosition(), plate.move.getXPosition(), plate.move.getYPosition(), 60, platformHeight)) {
					player.move.moveLeft();
					player.move.moveLeft();
					player.move.moveLeft();
				}
			}
		}

		//	//updating scene

		if (movementTime > 0) {
			player.move.move();
			circle.setPosition(player.move.getXPosition(), player.move.getYPosition());
			for (auto& plate : platforms) {
				if (player.collide.checkCollision(player.move.getXPosition(), player.move.getYPosition(), plate.move.getXPosition(), plate.move.getYPosition(), 60, platformHeight)) {
					player.move.gravity();
					circle.setPosition(player.move.getXPosition(), player.move.getYPosition());
				}
				plate.move.gravity();
				rect.setPosition(plate.move.getXPosition(), plate.move.getYPosition());
				std::cout << plate.move.getYPosition() << std::endl;
			}
			movementTime--;
		}
		//updating vectors
		//if (platforms.size() < difficulty) {
		//	//add new vector
		//	Platform newPlat;
		//	//randomise x value 
		//	float randomX = rand() % screenHeight + 1;
		//	//std::cout << (randomX);
		//	newPlat.move.setPos(randomX, -50);
		//	//randomise length
		//	float randomLength = rand() % 50 + 21;
		//	sf::RectangleShape newRect(sf::Vector2f(randomLength, platformHeight));
		//	//add to vectors
		//	platforms.push_back(newPlat);
		//	rectanges.push_back(newRect);
		//}

		//loop
		for (auto plate : platforms) {
			if (plate.move.getYPosition() >= 1500) {
				std::cout << "remove - " << plate.move.getYPosition() << std::endl;
			}
			else {
				//std::cout << (rect.getPosition().y) << std::endl;
			}
			if (!player.collide.checkCollision(player.move.getXPosition(), player.move.getYPosition(), plate.move.getXPosition(), plate.move.getYPosition(), 60, platformHeight)) {
				player.move.gravity();
				circle.setPosition(player.move.getXPosition(), player.move.getYPosition());
			}
		}
		//if higher than 1200 remove
		// 




		//drawing
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
	//static - done
	// falling
	//boost
//items

//poisisitoin - movement
// collider


/*to do
*	- add multiple plateforms ~1.5 hours
*	- add emeies - 1 hour
*	- multple enemies ~1.5 hours
*	- backgound ~1 hour
*		- blue background
*		- clouds
*  - scoring
*
*
*  - high scores


*/

