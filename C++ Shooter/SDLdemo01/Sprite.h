#pragma once


class Sprite  //this class handles making all sprites for all things in game
{
	SDL_Texture * texture = nullptr; //setting up texture object
	SDL_Rect sourceRectangle; //setting up source rectangle

	

public:
	Sprite();
	virtual ~Sprite(); //virtual as it will be used by subclasses and overridden

	void initialise(SDL_Renderer* renderer, const char *pathToImage); //feeds chosen image as the arguments in constructor
	void draw(SDL_Renderer* renderer, SDL_Rect* targetRect, float renderOrientation); //feeds arguments as to what shape sprite cutout will be

	//initialise would be called to load the sprite and setup the texture while draw would call the SDL draw function
};


