#pragma once

#include "Movement.h"
#include "Collider.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Player : public sf::Drawable
{
public:
	Player();
	Movement move;
	Collider collide;
	

private:
	virtual void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const;
	sf::CircleShape m_circle;
};

