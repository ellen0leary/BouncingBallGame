#pragma once

#include "Movement.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Player 
{
public:
	Player() {
		std::cout << "Making circle";
		sf::CircleShape circle(20.f);
		circle.setFillColor(sf::Color::Cyan);
		std::cout << std::to_string(circle.getPosition().x);
	}
	Movement move;
	sf::CircleShape circle;
private:
	
};

