#pragma once

#include <iostream>
class Movement
{
private:
	float xPos;
	float yPos;
	bool playerControllered;
	bool canMoveLeft;
	void playerMovement();
	void enemyMovement();

public:
	Movement();
	Movement(float x, float y, bool ifContolled);

	float getXPosition();
	float getYPosition();

	void move();
	void setPos(float x, float y);

	void setControlled(bool ifControlled);
	void gravity();

	bool moveLeft();
	bool moveRight();
};

