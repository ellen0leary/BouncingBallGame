#pragma once

#include "Movement.h"
#include "Collider.h"
#include <SFML/Graphics.hpp>

#include <iostream>
class Enemy : public sf::Drawable
{
public:
	Enemy();
	Enemy(float startX, float startY, bool ifControlled, float width, float height);
	//Enemy::Enemy(float startX, float startY, bool ifControlled, float width, float height);
	virtual ~Enemy();
	Movement move;
	Collider collide;

private:
	virtual void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const;
	sf::RectangleShape m_rect;
};

