#include "pch.h"
#include "Enemy.h"


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}


void Enemy::initialise(Sprite* sprite, float initX, float initY) {

	x = initX;
	y = initY;

	this->enemySprite = sprite;

	Patrol = true;
	

	// Recipe 5 - to define bounding box we need size of sprite in game world!
	w = 128.0f;
	h = 128.0f;

	// Temp variables to calculate the centre point of the sprite given (x, y) are the top left
	float cx = x + (w / 2.0f);
	float cy = y + (h / 2.0f);

	boundingBox = AABB(cx, cy, w / 2.0f, h / 2.0f); // Store half w, h in the bounding box!
}

void Enemy::update() {

	//a swtich case for different states
	/*
	switch(1)
		case 1: onPatrol = true
			break;
	*/



}

void Enemy::draw(SDL_Renderer* renderer) {
	 //not sure if this is instance specific. ask.
	SDL_Rect targetRect;

	targetRect.x = int(x);
	targetRect.y = int(y);
	targetRect.w = int(w); // Recipe 5 - get size from attributes - no longer hard-coded values!
	targetRect.h = int(h);

	
		enemySprite->draw(renderer, &targetRect, 0.0f);
		//draws the enemy sprite and box, shouldnt be called as stopped in main draw

		boundingBox.draw(renderer);
	
}


void Enemy::move(float xEnemyMovement, float yEnemyMovement) {
	if (alive = true) {
		x += xEnemyMovement;
		y += yEnemyMovement;

		// Recipe 5 - move bounding box too!
		boundingBox.move(xEnemyMovement, yEnemyMovement);
	}
}


// Recipe 9 - addHealth called when bullets hit with negative value for amountToAdd parameter
void Enemy::addHealth(int amountToAdd) {


	health += amountToAdd;
	printf("health = %d\n", health); 

		//printf("ENEMY DESTORYED\n");
		//killing them, not drawn when "Dead"
					//can put all alive barriers here since its all called from enemy , or not
}

void Enemy::changeStatus(bool intalive) {

	alive = intalive;

}

// Recipe 5 - Add AABB accessor so Game Object can get this information to test for collisions
// Note: GRASP dictates the Enemy class knows nothing about the Game Object - and it doesn't - but any caller can ask for the bounding box
AABB Enemy::getBoundingBox() {
	
	return boundingBox;		//putting it here to try and stop bugs
}

float Enemy::getHealth() {

	return health;
}






void Helicopter::update()
{
	//not using subclasses right now


}