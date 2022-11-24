#include "pch.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}


void Player::initialise(Sprite* playerSprite, float initX, float initY, float initHealth) {
	//the initialisation is different for each class, 
	x = initX;
	y = initY;

	this->playerSprite = playerSprite;

	// Recipe 5 - to define bounding box we need size of sprite in game world!
	w = 128.0f;
	h = 128.0f;

	// Temp variables to calculate the centre point of the sprite given (x, y) are the top left
	float cx = x + (w / 2.0f);
	float cy = y + (h / 2.0f);
	
	boundingBox = AABB(cx, cy, w / 2.0f, h / 2.0f); // Store half w, h in the bounding box!

	// Recipe 7 - Points
	points = 0;

	// Recipe 8 - Health
	health = initHealth;
}


void Player::update() {
}


void Player::draw(SDL_Renderer* renderer) {

	SDL_Rect targetRect;

	targetRect.x = int(x);
	targetRect.y = int(y);
	targetRect.w = int(w); // Recipe 5 - get size from attributes!
	targetRect.h = int(h);

	playerSprite->draw(renderer, &targetRect, orientation);

	// Recipe 5 - Draw AABB to show collision boundary
	boundingBox.draw(renderer);
}
/* initialise would be simply assign the attributes
	   given the parameter values passed in while draw would
	   just setup the target rectangle based on the players
	   (x, y) position and call draw on the playerSprite object */

Float2 Player::getPosition() {

	return Float2(x, y);
}


void Player::move(float xMovement, float yMovement) {

	x += xMovement;
	y += yMovement;

	// Recipe 5 - need to move bounding volume too!
	boundingBox.move(xMovement, yMovement);			//the player sprite, and the bounding box are "moved" by being drawn in different places
}														//the object uses its co-ords to tell the sprite where to be drawn. 
															//if I want player to jump this is fine


// Recipe 4 - Add ability to rotate the player
void Player::rotate(float dTheta) {

	orientation += dTheta;

	// Note: Don't change AABB - this is ALWAYS axis aligned!
}


// Recipe 5 - AABB accessor
AABB Player::getBoundingBox() {

	return boundingBox;
}


// Recipe 7 - Update player's points / score by amountToAdd
void Player::addPoints(int amountToAdd) {

	points += amountToAdd;
}


// Recipe 8 - Update health by amountToAdd (if amountToAdd is negative the player's health goes down!)
void Player::addHealth(float amountToAdd) {

	health += amountToAdd;
	printf("health = %f\n", health);
}


float Player::getHealth() {

	return health;
}