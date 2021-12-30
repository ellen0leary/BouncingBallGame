#pragma once

#include "Movement.h"
#include <SFML/Graphics.hpp>

class Platform : public sf::Drawable
{
public:
	Platform();
	virtual ~Platform();
	Movement move;

private:
	virtual void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const;

	sf::RectangleShape m_rect;
};

