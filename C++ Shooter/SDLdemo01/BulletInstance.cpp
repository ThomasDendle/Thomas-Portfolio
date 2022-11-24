#include "pch.h"
#include "BulletInstance.h"


BulletInstance::BulletInstance()
{
}						//a bullet instance is handled like a temporary enemy that is spawned and despawned, like everythig else it needs other functions


BulletInstance::~BulletInstance()
{
}

void BulletInstance::initialise(ProjectileType* type, Float2 initPos, Float2 initVel) {

	this->type = type;

	this->pos = initPos;
	this->vel = initVel;

	// Temp variables to calculate the centre point of the sprite given (x, y) are the top left
	float cx = pos.x + (type->getWidth() / 2.0f);
	float cy = pos.y + (type->getHeight() / 2.0f);

	boundingBox = AABB(cx, cy, type->getWidth() / 2.0f, type->getHeight() / 2.0f); // Store half w, h in the bounding box!
}

void BulletInstance::update(float tDelta) {

	float dx = vel.x * tDelta;
	float dy = vel.y * tDelta;

	float offset = sqrtf(dx * dx + dy * dy);

	pos.x += dx;
	pos.y += dy;

	boundingBox.move(dx, dy);

	distanceTravelled += offset;
}

void BulletInstance::hit(Enemy* target) {	//doing some mad fucking science here
	//that int specifies enemy number. 

	int damageImpact = int(type->getDamage());
	target->addHealth(-damageImpact);//this seems fine, the issue is the target is not specified. 
	distanceTravelled = type->getRange();
}

bool BulletInstance::exceededRange() {

	return distanceTravelled >= type->getRange();
}

AABB BulletInstance::getBoundingBox() {

	 return boundingBox;	//error here. access violation reading location //boudning box data incomplete?
}

void BulletInstance::draw(SDL_Renderer* renderer) {

	type->draw(renderer, pos, 0.0f);
}