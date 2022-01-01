
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <stdlib.h> //for random
#include <time.h> // for random seed

//custom classes
#include "Player.h"
#include "Platform.h"
#include "Enemy.h"

int main()
{
	int currentY = 600;
	int enemyY = 400;
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
	int difficulty = 10;
	bool changedThisFrame = false;

	srand(time(0));

	while (platforms.size() <= 30) {
		//add new vector
		Platform newPlat;
		//randomise x value 
		float randomY = rand() % 20+50;
		currentY -= randomY;
		float randomX = rand() % (screenWidth) + 30;
		//std::cout << (randomX);
		newPlat.move.setPos(randomX, currentY);
		//randomise length
		float randomLength = rand() % 50 + 21;


		sf::RectangleShape newRect(sf::Vector2f(randomLength, platformHeight));
		newRect.setFillColor(sf::Color::Green);
		newRect.setPosition(randomX, randomY);
		//add to vectors
		platforms.push_back(newPlat);
	}

	while (enemies.size() <= 3) {
		float randomY = rand() % 50 +130;
		enemyY -= randomY;
		float randomX = rand() % (screenWidth - 0) + 30;
		//(float startX, float startY, bool ifControlled, float width, float height) 
		Enemy newEnemy(randomX, enemyY, false, 20, 20);
		enemies.push_back(newEnemy);
	}

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
					movementTime = 300;
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
		for (auto& enem : enemies) {
			if (player.checkForCollision(enem.getPosition())) {
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
				if (plate.move.getYPosition() > 1500) {
					float lastY = platforms.back().move.getYPosition();
					float randomY = rand() % 20 + 50;
					float randomX = rand() % (screenWidth) +1;
					plate.move.setPos(randomX, 0);
					plate.updatePositin();
				}
				changedThisFrame = true;
			}
			for (auto& ene : enemies) {
				ene.move.gravity();
			}

			movementTime--;
		}
		//delete if over 1500
		/*for (auto it = begin(platforms); it != end(platforms); ++it) {
			if (it->move.getYPosition() >= 800) {
				platforms.erase(std::remove(platforms.begin(), platforms.end(),it));
			}
		}*/
		for (auto& ene : enemies) {
			ene.updatePosition();
			if (ene.move.getYPosition() > 600) {
				float lastY = enemies.back().move.getYPosition();
				float randomY = rand() % 70 + 130;
				ene.move.setPos(0, (-(randomY)));
			}
		}
		
		//updating vectors
		if (platforms.size() < difficulty) {
			//add new vector
			Platform newPlat;
			//randomise x value 
			float randomX = rand() % screenHeight + 1;
			//std::cout << (randomX);
			newPlat.move.setPos(randomX, -50);
			//randomise length
			float randomLength = rand() % 50 + 21;
			sf::RectangleShape newRect(sf::Vector2f(randomLength, platformHeight));
			//add to vectors
			platforms.push_back(newPlat);
		}
	 
		

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
*  - fix plateform - fixed for now
*  - add collider to enemy - done
*  - update movement on plateforms - done
*  - update movement on enemies - done
* 
*  - multiple platofrms  - kinda
*  - multiple enemies - kinda
*  
*  - background clouds
* - fix spawning
* 
*  - scoring
*  - first click
*/ 

/* to do 
* - keep spawning in items~1 hour
* - scoring ~ 1 hour
* - sounds ~ 1 hour
* - text - .5 hour
* - menu - 1 hour
* - 
*/