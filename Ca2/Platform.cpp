#include "Platform.h"

Platform::Platform() :m_rect(sf::Vector2f(60, 20))
{
	m_rect.setFillColor(sf::Color::Color(11, 0, 51));
	m_rect.setOutlineThickness(0.2);
	m_rect.setOutlineColor(sf::Color::White);
	m_rect.setPosition(100, 600);
}

Platform::~Platform()
{
}

void Platform::updatePositin() {
	float x = move.getXPosition();
	float y = move.getYPosition();

	m_rect.setPosition(sf::Vector2f(x, y));
}

sf::FloatRect Platform::getPosition()
{
	return m_rect.getGlobalBounds();
}

void Platform::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
	renderTarget.draw(m_rect);
}


//bool Platfom::checkForCollision(sf::FloatRect other) {
//	return collide.checkCollision(m_circle.getGlobalBounds(), other);
//}