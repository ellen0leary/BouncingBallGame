#include "Collider.h"


Collider::Collider(float width, float height) :
	m_width(width), m_height(height) {

};

bool Collider::checkCollision(float currentX, float currentY, float otherX, float otherY, float otherWidth,float otherHeight) {
	//current obj
	float x1 = currentX;
	float x2 = currentX + m_width;
	float y1 = currentY;
	float y2 = currentY + m_height;

	//other obj
	float othX1 = otherX;
	float othX2 = otherX + otherWidth;
	float othY1 = otherY;
	float othY2 = otherY + otherHeight;

	if (x1 <= othX2 && x2 >= othX1 && y1 <= othY2 && y2 >= othY1) {
		return true;
	}
	return false;

}
bool Collider::setActive()
{
	if(m_ifActive)
	//m_ifActive = !m_ifActive;
	return m_ifActive;
};