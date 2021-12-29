#pragma once

#include <iostream>
class Collider
{
public:
	Collider(float width, float height);
	bool checkCollision(float currentX, float currentY, float otherX, float otherY, float otherWidth, float otherHeight);
	bool setActive();
private:
	float m_width;
	float m_height;
	bool m_ifActive;
};

