#include "Enemy.h"


Enemy::Enemy(): m_rect(sf::Vector2f(20,20)) {
	m_rect.setFillColor(sf::Color::Color(131, 34, 50));
	m_rect.setPosition(200, 400);
}

Enemy::Enemy(float startX, float startY, bool ifControlled, float width, float height) :
 move(startX,startY,ifControlled) {

}

Enemy::~Enemy() {

}

void Enemy::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const {
	renderTarget.draw(m_rect);
}