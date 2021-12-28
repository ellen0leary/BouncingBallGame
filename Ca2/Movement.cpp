#include "Movement.h"


Movement::Movement() {

};

Movement::Movement(float x, float y, bool ifContolled) :
	xPos(x), yPos(y), playerControllered(ifContolled) {

};
void Movement::enemyMovement() {

};

void Movement::playerMovement() {
};

float Movement::getXPosition() {
	return xPos;
}

void Movement::gravity()
{
}

float Movement::getYPosition() {
	return yPos;
}

void Movement::move() {
	playerMovement();
	/*if (playerControllered) {
		playerMovement();
	}
	else {
		enemyMovement();
	}*/
}

void Movement::setPos(float x, float y) {
	xPos = x;
	yPos = y;
}


void Movement::moveLeft() {
	if (xPos <= 1) {
		return;
	}
	else {
	}
};
void Movement::moveRight() {
	if (xPos >= 360) {
		return;
	}
	else {
	}
};