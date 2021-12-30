#include "Player.h"


Player::Player():collide(40,40), m_circle(20.0f) {
	m_circle.setFillColor(sf::Color::Color(206, 137, 100));
	m_circle.setPosition(160, 800);
};


void Player::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const {
	renderTarget.draw(m_circle);
}

void Player::updatePosition() {
	float x = move.getXPosition();
	float y = move.getYPosition();

	m_circle.setPosition(sf::Vector2f(x, y));
}