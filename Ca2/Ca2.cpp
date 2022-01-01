
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h> //for random
#include <time.h> // for random seed

//custom classes
#include "Player.h"
#include "Platform.h"
#include "Enemy.h"

int main()
{
	enum class State { MENU, PLAYING, GAMMEOVER };
	State state = State::MENU;
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
	int score = 0;

	//scoreFont
	sf::Font font;
	if (!font.loadFromFile("fonts/Shizuru.ttf")) {
		return -1;
	}
	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setString("Score- " + std::to_string(score));
	scoreText.setCharacterSize(30);
	scoreText.setFillColor(sf::Color::White);

	sf::Text gameNameText;
	gameNameText.setFont(font);
	gameNameText.setString("Flyier");
	gameNameText.setCharacterSize(60);
	gameNameText.setPosition((screenWidth / 2)-60, (screenHeight / 2)-60);
	gameNameText.setFillColor(sf::Color::White);

	sf::Text subText;
	subText.setFont(font);
	subText.setString("Press Space to Start");
	subText.setCharacterSize(30);
	subText.setPosition(30, (screenHeight / 2)+20 );
	subText.setFillColor(sf::Color::White);

	sf::Text gameOverText;
	gameOverText.setFont(font);
	gameOverText.setString("Game Over!");
	gameOverText.setCharacterSize(60);
	gameOverText.setPosition(40, (screenHeight / 2) - 100);
	gameOverText.setFillColor(sf::Color::White);
	//sound
	//	background
	sf::SoundBuffer loopBuffer;
	if (!loopBuffer.loadFromFile("sounds/loop.wav")) {
		return -1;
	}
	sf::Sound loopSound;
	loopSound.setBuffer(loopBuffer);
	loopSound.play();
	loopSound.setLoop(true);
	//	jumping
	sf::SoundBuffer jumpBuffer;
	if (!jumpBuffer.loadFromFile("sounds/jumping.wav")) {
		return -1;
	}
	sf::Sound jumpSound;
	jumpSound.setBuffer(jumpBuffer);
	//	death
	sf::SoundBuffer deathBuffer;
	if (!deathBuffer.loadFromFile("sounds/death.wav")) {
		return -1;
	}
	sf::Sound deathSound;
	deathSound.setBuffer(deathBuffer);

	srand(time(0));

	while (platforms.size() <= 30) {
		//add new vector
		int random = rand() % 2;
		if (random) random = rand() % 2; //25%
		Platform newPlat(random);
		//randomise x value 
		float randomY = rand() % 20 + 50;
		currentY -= randomY;
		float randomX = rand() % (screenWidth)+30;
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

	while (enemies.size() <= 4) {
		float randomY = rand() % 50 + 130;
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

				if (event.key.code == sf::Keyboard::Space) {
					if (state == State::PLAYING) {
						std::cout << "space Pressed" << std::endl;
						movementTime = 400;
						score += 10;
						jumpSound.play();
					}
					else if (state == State::MENU) {
						state = State::PLAYING;
					}
					else {
						state = State::MENU;
						player.reset();
					}
				}
			}

		}
		if (state == State::PLAYING) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				//move left
				player.move.moveLeft();
				for (auto plate : platforms) {
					if (player.checkForCollision(plate.getPosition())
						/*player.collide.checkCollision(player.move.getXPosition(), player.move.getYPosition(), platform.move.getXPosition(), platform.move.getYPosition(), 60, platformHeight)*/) {
						/*player.move.moveRight();
						player.move.moveRight();
						player.move.moveRight();*/
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
						/*player.move.moveLeft();
						player.move.moveLeft();
						player.move.moveLeft();*/
					}
				}
				player.updatePosition();
			}
		}

		//	//updating scene
		if (state == State::PLAYING) {
			bool ifHit = false;
			for (auto& plat : platforms) {
				plat.moving();
				if (player.checkForCollision(plat.getPosition())) {
					ifHit = true;
				}
			}
			for (auto& enem : enemies) {
				if (player.checkForCollision(enem.getPosition())) {
					ifHit = true;
					deathSound.play();
					state = State::GAMMEOVER;
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
						float lastY = -400;
						float randomY = rand() % 20 + 50;
						float randomX = rand() % (screenWidth)+1;
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

			for (auto& ene : enemies) {
				ene.updatePosition();
				if (ene.move.getYPosition() > screenHeight) {
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


			scoreText.setString("Score- " + std::to_string(score));
		} 
		//drawing
		window.clear(sf::Color::Color(129, 96, 247));
		if (state == State::MENU) {
			window.draw(gameNameText);
			window.draw(subText);
		}else if (state == State::PLAYING) {
			window.draw(player);
			for (auto plate : platforms) {
				window.draw(plate);
			}
			for (auto ene : enemies) {
				window.draw(ene);
			}
			window.draw(scoreText);
		}
		else {
			window.draw(gameOverText);
			window.draw(subText);

		}
		window.display();
	}

	return 0;
}


/* to do
* - keep spawning in items~1 hour - done
* - scoring ~ 1 hour - done
* - sounds ~ 1 hour - done
* - text - .5 hour - done
* - menu - 1 hour - done
*  - plateform moves
*  - coins
*/