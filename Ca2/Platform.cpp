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

void Platform::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
	renderTarget.draw(m_rect);
}
