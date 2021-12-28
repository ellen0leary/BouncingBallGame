#pragma once
class Movement
{
private:
	float xPos;
	float yPos;
	bool playerControllered;

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

	void moveLeft();
	void moveRight();
};

