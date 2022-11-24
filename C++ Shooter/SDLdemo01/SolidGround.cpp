#include "pch.h"
#include "SolidGround.h"


SolidGround::SolidGround()
{
}


SolidGround::~SolidGround()
{
}

void SolidGround::initialise(float initX, float initY) {

	x = initX;
	y = initY;

	// Recipe 5 - to define bounding box we need size of sprite in game world!
	w = 1000.0f;
	h = 300.0f;

	// Temp variables to calculate the centre point of the sprite given (x, y) are the top left
	float cx = x + (w / 2.0f);
	float cy = y + (h / 2.0f);

	


	boundingBox = AABB(cx, cy, w / 2.0f, h / 2.0f); // Store half w, h in the bounding box!
}

void update() {

} //not needed?

void SolidGround::draw(SDL_Renderer* renderer) {
	
		SDL_Rect targetRect;

		targetRect.x = int(x);
		targetRect.y = int(y);		//setting size of floor. or something
		targetRect.w = int(w); // Recipe 5 - get size from attributes - no longer hard-coded values!
		targetRect.h = int(h);

		boundingBox.draw(renderer); //bounding box still needs to be drawn
	
}


AABB SolidGround::getBoundingBox() {
	return boundingBox;

}



