#include "pch.h"
#include "Sprite.h"


Sprite::Sprite()
{
}						//default constructor and deconstructor


Sprite::~Sprite()
{
}


void Sprite::initialise(SDL_Renderer* renderer, const char *pathToImage) {



	{ //gives the draw function values to make the sprite,

		//each new instance of the class has different values for this

		SDL_Surface* image = IMG_Load(pathToImage);   //create local variable called image
		texture = SDL_CreateTextureFromSurface(renderer, image);		//creates texture from image
		SDL_FreeSurface(image);		//removes image

		sourceRectangle.x = 0;	//top left corner of sprite image
		sourceRectangle.y = 0;

		SDL_QueryTexture(texture, 0, 0, &(sourceRectangle.w), &(sourceRectangle.h));
		//cuts rectangle out of texture
		/*
		SDL_Rect	targetRectangle;

		targetRectangle.x = 100;   //where on screen from top-left
		targetRectangle.y = 100;
		targetRectangle.w = 64;		//size of sprite
		targetRectangle.h = 64; */
	};

	//acts as a "machine" for preparing new sprites
}

void Sprite::draw(SDL_Renderer* renderer, SDL_Rect* targetRect, float renderOrientation) {

	SDL_RenderCopyEx(
		renderer,     //the object used to draw 
		texture,		//the texture that gets drawn
		&sourceRectangle,	//what part of sprite image gets drawn
		targetRect,			//where on screen is drawn
		0.0f,				//how much we rotate
		0,					//centre of rotation	
		SDL_FLIP_NONE);		//flip the sprite
}
