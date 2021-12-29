#pragma once

#include "Movement.h"
#include "Collider.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Player 
{
public:
	Player();
	Movement move;
	Collider collide;
	
	sf::CircleShape circle;
private:
	
};

