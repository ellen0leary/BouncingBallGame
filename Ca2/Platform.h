#pragma once

#include "Movement.h"
#include <SFML/Graphics.hpp>

class Platform : public sf::Drawable
{
public:
	Platform();
	Platform(bool ifMoving);
	virtual ~Platform();
	Movement move;
	void updatePositin();
	sf::FloatRect getPosition();
	void moving();


private:
	virtual void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const;
	bool ifMoving;
	sf::RectangleShape m_rect;
};

