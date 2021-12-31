#include "Enemy.h"


Enemy::Enemy(): m_rect(sf::Vector2f(20,20)), collide(20,20) , move(200,400,false) {
	m_rect.setFillColor(sf::Color::Color(131, 34, 50));
	m_rect.setPosition(200, 400);

}

Enemy::Enemy(float startX, float startY, bool ifControlled, float width, float height) :
 move(startX,startY,ifControlled) , collide(20,20) {

}

Enemy::~Enemy() {

}

void Enemy::updatePosition()
{
	move.move();
	float x = move.getXPosition();
	float y = move.getYPosition();

	m_rect.setPosition(sf::Vector2f(x, y));
}

void Enemy::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const {
	renderTarget.draw(m_rect);
}

sf::FloatRect Enemy::getPosition()
{
	return m_rect.getGlobalBounds();
}