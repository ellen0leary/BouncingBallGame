#include "Movement.h"


Movement::Movement() {

};

Movement::Movement(float x, float y, bool ifContolled) :
	xPos(x), yPos(y), playerControllered(ifContolled) {

};
void Movement::enemyMovement() {

};

void Movement::playerMovement() {
	yPos -= 1;
};

float Movement::getXPosition() {
	return xPos;
}

void Movement::gravity()
{
	yPos += 0.09;
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
		xPos -=0.5;
	}
};
void Movement::moveRight() {
	if (xPos >= 360) {
		return;
	}
	else {
		xPos +=0.5;
	}
};