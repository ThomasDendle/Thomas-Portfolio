#pragma once

// Enemy type for Recipe 5 (Collision Detection) and Recipe 9 (Bullets)

#include "Sprite.h"
#include "Float2.h"
#include "AABB.h"

class Enemy
{
private:

	// Position
	float			x;
	float			y;

	Sprite*			enemySprite = nullptr;

	//state

	bool Patrol;		//enemy "state". changes one depending on criteria, woudld use a switch statment?
	bool Gaurding;
	bool somethingelse;



	// Bounding box
	float			w;
	float			h;
	AABB			boundingBox;

	// Enemy health
	int				health = 100;
	bool alive = true; //used to define when to draw and update

public:
	Enemy();
	~Enemy();

	void initialise(Sprite* playerSprite, float initX, float initY);
	void update();
	void draw(SDL_Renderer* renderer);

	void move(float xEnemyMovement, float yEnemyMovement);

	void addHealth(int amountToAdd);

	void changeStatus(bool intalive);

	AABB getBoundingBox();

	float getHealth();
};

class Helicopter : public Enemy {

	float height;

public:

	void update();


};
