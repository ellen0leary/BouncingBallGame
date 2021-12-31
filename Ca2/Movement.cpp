#include "Movement.h"


Movement::Movement() {

};

Movement::Movement(float x, float y, bool ifContolled) :
	xPos(x), yPos(y), playerControllered(ifContolled) {
	canMoveLeft = true;

};
void Movement::enemyMovement() {
	if (!canMoveLeft) {
		canMoveLeft = moveLeft();
	}
	else {
		canMoveLeft = moveRight();
	}
};

void Movement::playerMovement() {
	yPos -= 1;
};

float Movement::getXPosition() {
	return xPos;
}

void Movement::gravity()
{
	yPos += 0.05;
}

float Movement::getYPosition() {
	return yPos;
}

void Movement::move() {
	if (playerControllered) {
		playerMovement();
	}
	else {
		enemyMovement();
	}
}

void Movement::setPos(float x, float y) {
	xPos = x;
	yPos = y;
}


bool Movement::moveLeft() {
	if (xPos <= 1) {
		return true;
	}
	else {
		xPos -=0.15;
		return false;
	}
};
bool Movement::moveRight() {
	if (xPos >= 360) {
		return false;
	}
	else {
		xPos += 0.15;
		return true;
	}
};