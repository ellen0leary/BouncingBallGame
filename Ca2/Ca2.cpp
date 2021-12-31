
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
//#include <stdio.h>
#include <stdlib.h> //for random
#include <time.h> // for random seed

//custom classes
#include "Player.h"
#include "Platform.h"
#include "Enemy.h"

int main()
{
	const int screenWidth = 400;
	const int screenHeight = 900;
	const float platformHeight = 20;
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Bouncing Ball");

	//Player class and sprite
	Player player;
	player.move.setPos(160, 800);

	////Platforms
	std::vector<Platform> platforms;
	Platform platform;
	platform.move.setPos(100, 600);
	platforms.push_back(platform);


	//enemyies
	std::vector<Enemy> enemies;
	Enemy enemy;
	enemies.push_back(enemy);


	//values
	bool spacePressed = false;
	int movementTime = 0;
	int difficulty = 5;
	bool changedThisFrame = false;


	while (platforms.size() <= 5) {
		//add new vector
		Platform newPlat;
		//randomise x value 
		float randomX = rand() % screenHeight + 1;
		float randomY = rand() % screenWidth + 30;
		//std::cout << (randomX);
		newPlat.move.setPos(randomX, randomY);
		//randomise length
		float randomLength = rand() % 50 + 21;


		sf::RectangleShape newRect(sf::Vector2f(randomLength, platformHeight));
		newRect.setFillColor(sf::Color::Green);
		newRect.setPosition(randomX, randomY);
		//add to vectors
		platforms.push_back(newPlat);
	}

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
			for (auto plate : platforms) {
				if (player.checkForCollision(plate.getPosition())
					/*player.collide.checkCollision(player.move.getXPosition(), player.move.getYPosition(), platform.move.getXPosition(), platform.move.getYPosition(), 60, platformHeight)*/) {
					player.move.moveRight();
					player.move.moveRight();
					player.move.moveRight();
				}
			}
			player.updatePosition();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			//move right
			player.move.moveRight();
			for (auto plate : platforms) {
				if (player.checkForCollision(plate.getPosition())
					/*player.collide.checkCollision(player.move.getXPosition(), player.move.getYPosition(), platform.move.getXPosition(), platform.move.getYPosition(), 60, platformHeight)*/) {
					player.move.moveLeft();
					player.move.moveLeft();
					player.move.moveLeft();
				}
			}
			player.updatePosition();
		}

		//	//updating scene
		bool ifHit = false;
		for (auto& plat : platforms) {
			if (player.checkForCollision(plat.getPosition())) {
				ifHit = true;
			}
		}

		if (!ifHit) {
			player.move.gravity();
			player.updatePosition();
		}
		if (movementTime > 0) {
			player.move.move();
			player.updatePosition();
			for (auto& plate : platforms) {
				plate.move.gravity();
				plate.updatePositin();
				changedThisFrame = true;
			}
			for (auto& ene : enemies) {
				ene.move.gravity();
			}

			movementTime--;
		}
		for (auto& ene : enemies) {
			ene.updatePosition();
		}
		////updating vectors
		////if (platforms.size() < difficulty) {
		////	//add new vector
		////	Platform newPlat;
		////	//randomise x value 
		////	float randomX = rand() % screenHeight + 1;
		////	//std::cout << (randomX);
		////	newPlat.move.setPos(randomX, -50);
		////	//randomise length
		////	float randomLength = rand() % 50 + 21;
		////	sf::RectangleShape newRect(sf::Vector2f(randomLength, platformHeight));
		////	//add to vectors
		////	platforms.push_back(newPlat);
		////	rectanges.push_back(newRect);
		////}

		////loop
		//for (auto plate : platforms) {
		//	if (plate.move.getYPosition() >= 1500) {
		//		std::cout << "remove - " << plate.move.getYPosition() << std::endl;
		//	}
		//	
		//}

		//for (auto& ene : enemies) {
		//	ene.updatePosition();
		//}
		////checking collisions
		//bool ifHit = false;
		//for (auto& ene : enemies) {
		//	if (!player.collide.checkCollision(player.move.getXPosition(), player.move.getYPosition(), ene.move.getXPosition(), ene.move.getYPosition(), 20, 20)) {
		//		ifHit = true;
		//	}
		//}
		//for (auto plat : platforms) {
		//	if (!player.checkForCollision(plat.getPosition())
		//		/*!player.collide.checkCollision(player.move.getXPosition(), player.move.getYPosition(), plat.move.getXPosition(), plat.move.getYPosition(), 60, 20)*/) {
		//		/*player.move.gravity();
		//		player.updatePosition();*/
		//		//std::cout << std::to_string(player.checkForCollision(plat.getPosition())) << std::endl;
		//		ifHit = true;
		//	}
		//}

		//if (!ifHit) {

		//	ifHit = false;
		//} 
		///*if (!player.collide.checkCollision(player.move.getXPosition(), player.move.getYPosition(), platform.move.getXPosition(), platform.move.getYPosition(), 60, 20) && 
		//	(!player.collide.checkCollision(player.move.getXPosition(), player.move.getYPosition(), enemy.move.getXPosition(), enemy.move.getYPosition(), 20, 20))) {
		//	player.move.gravity();
		//	player.updatePosition();
		//}*/
		//player.move.gravity();
		//player.updatePosition();
		//if (!player.checkForCollision(platform.getPosition())) {
		//	//std::cout << std::to_string(player.checkForCollision(platform.getPosition())) << std::endl;
		//}
	

		//drawing
		window.clear(sf::Color::Color(129, 96, 247));
		window.draw(player);
		for (auto plate : platforms) {
			window.draw(plate);
		}
		for (auto ene : enemies) {
			window.draw(ene);
		}
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
*  - player singleton

*/


/*to do
*  - fix plateform - fixed for now
*  - add collider to enemy - done
*  - update movement on plateforms - done
*  - update movement on enemies - done
* 
*  - multiple platofrms 
*  - multiple enemies
*  
*  - background clouds
* 
*  - scoring
*/