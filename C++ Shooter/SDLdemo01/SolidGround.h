#pragma once
#include "Sprite.h"
#include "Float2.h"
#include "AABB.h"


class SolidGround
{

	//essentially an ememy that does nothing but exist there, just a hitbox.

private:

// Position
		float			x;
		float			y;

		//Sprite*			enemySprite = nullptr; No Sprite?

		//state

		// Bounding box, the only thing that matters here
		float			w;
		float			h;
		AABB			boundingBox;

 public:

		void initialise(float initX, float initY);

		void update();
		
		void draw(SDL_Renderer* renderer);

		AABB getBoundingBox();



	SolidGround();
	~SolidGround();
};

