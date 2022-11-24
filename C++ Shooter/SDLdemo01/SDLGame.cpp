#include "pch.h"
#include "SDLGame.h"


SDLGame::SDLGame(){
}


SDLGame::~SDLGame(){
}


void SDLGame::initialise() {

	const int SDL_OKAY = 0;

	int sdlStatus = SDL_Init(SDL_INIT_EVERYTHING);

	if (sdlStatus != SDL_OKAY)
		throw "SDL init error";

	gameWindow = SDL_CreateWindow(
		"don't worry, it's in beta",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,		//window dimensions
		1000,
		700,
		SDL_WINDOW_SHOWN);

	// Enumerate render drivers
	int n = SDL_GetNumRenderDrivers();

	printf("Number of renderers = %d\n", n);

	for (int i = 0; i < n; ++i) {

		SDL_RendererInfo renderInfo;

		if (SDL_GetRenderDriverInfo(i, &renderInfo) == 0) { // 0 means success

			printf("Renderer %d : %s\n", i, renderInfo.name);
		}
	}

	// Use first (Default) renderer - this is usually Direct3D based 
	
	gameRenderer = SDL_CreateRenderer(gameWindow, 0, 0); //makes a new renderer that takes up the window. 
	
	// -----------------------


	playerSprite = new Sprite();
	playerSprite->initialise(gameRenderer, "Assets\\Images\\player.png");

	//background
	backgroundSprite = new Sprite();
	backgroundSprite->initialise(gameRenderer, "Assets\\Images\\background.png");


	enemySprite = new Sprite();
	enemySprite->initialise(gameRenderer, "Assets\\Images\\enemy.png");

	mainPlayer = new Player();
	mainPlayer->initialise(playerSprite, 50, 400, 100.0f);

	// Recipe 5 & 9 - instantiate something to collide with and shoot
	theOtherOne = new Enemy();		
	theOtherOne->initialise(enemySprite, 250, 400); 

	FBIGuy = (Enemy*)malloc(MAX_ENEMIES * sizeof(Enemy));	//would use an array of pointers if using subclasses.

	//Enemy FBIGuy[2]; //could make a static array, but malloc works better

	 //making multiple instances of FBIGuy
	FBIGuy[0] = Enemy();
	FBIGuy[0].initialise(enemySprite, 400, 400);

	FBIGuy[1] = Enemy();
	FBIGuy[1].initialise(enemySprite, 600, 400); //initilaise all enemies, have to do it indivisually to set location. New class to
											     //manage enemy location?  
	FBIGuy[2] = Enemy();
	FBIGuy[2].initialise(enemySprite, 800, 400);


//INITALISE solid ground. 

	floor = new SolidGround();
	floor->initialise(0, 535);


	// Recipe 9 - Bullets
	bulletSprite = new Sprite();
	bulletSprite->initialise(gameRenderer, "Assets\\Images\\projectile01.png");	//making bullet sprites
	
	bulletType = new ProjectileType();
	bulletType->initialise(bulletSprite, 30, 600, 32, 32);		//sprite, damage, range, width, height.(upped damage)

	for (int i = 0; i < MAX_BULLETS; i++) {
		
		bullets[i] = nullptr;
	}

	// Add other initialisation code here...

}

void SDLGame::runGameLoop() {

	gameRunning = true;

	while (gameRunning) {

		// Recipe 3 - Update timing / clock
		
		// Calculate time elapsed
		currentTimeIndex = SDL_GetTicks();
		timeDelta = currentTimeIndex - prevTimeIndex;		//ensures the game runs at the same pace for everyone as is bound to real time.
		timeDeltaInSeconds = float(timeDelta) / 1000.0f;

		// Store current time index into prevTimeIndex for next frame
		prevTimeIndex = currentTimeIndex;

		// --------------------

		handleEvents();
		update();
		draw();
	}
}

void SDLGame::handleEvents() {

	SDL_Event event;

	// Recipe 4 - device and instance id variables for controller connections / removal
	Sint32 deviceID;
	Sint32 instanceID;

	// Check for next event
	while (SDL_PollEvent(&event)) {
		
		switch (event.type) {

		// Check if window closed
		case SDL_QUIT:
			gameRunning = false;
			break;

		// Key pressed event
		case SDL_KEYDOWN:

			// Toggle key states based on key pressed
			switch (event.key.keysym.sym) {

			case SDLK_UP:
				keyState |= Keys::Up;
				break;

			case SDLK_DOWN:
				keyState |= Keys::Down;
				break;

			case SDLK_LEFT:
				keyState |= Keys::Left;		//assigining the keys
				break;

			case SDLK_RIGHT:
				keyState |= Keys::Right;
				break;

			case SDLK_SPACE:
				keyState |= Keys::Fire;
				break;

			case SDLK_ESCAPE:
				gameRunning = false;
				break;
			}
			break;

		// Key released event
		case SDL_KEYUP:

			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				keyState &= (~Keys::Up);
				break;

			case SDLK_DOWN:
				keyState &= (~Keys::Down);
				break;

			case SDLK_LEFT:
				keyState &= (~Keys::Left);
				break;

			case SDLK_RIGHT:
				keyState &= (~Keys::Right);
				break;

			case SDLK_SPACE:
				keyState &= (~Keys::Fire);

				// Find first "free" bullet
				if (1) {

					int i = 0;
					while (bullets[i] != nullptr && i < MAX_BULLETS) {
						i++;
					}			//sets to null, gives each bullet a instance of the projectile bullet

					if (i < MAX_BULLETS) {

						bullets[i] = new BulletInstance();
						bullets[i]->initialise(bulletType, mainPlayer->getPosition(), Float2(200.0f, 0.0f));
					}
				}

				break;
			}

			break;


		//
		// Recipe 4 - Controller input
		//

		case SDL_CONTROLLERDEVICEADDED:

			deviceID = event.cdevice.which;
			printf("Controller device %d added to system\n", deviceID);
		
			// Setup UP TO 4 controllers for this game!
			if (deviceID >= 0 && deviceID < 4) {

				// Open controller for processing - deviceID indexes the ith controller on the system
				controllers[deviceID] = SDL_GameControllerOpen(deviceID);
			}
			break;

		case SDL_CONTROLLERDEVICEREMOVED:

			instanceID = event.cdevice.which;

			printf("Controller instance_id %d removed\n", instanceID);
		
			if (1) {

				SDL_GameController *controller = SDL_GameControllerFromInstanceID(instanceID);

				if (controller != nullptr) {

					SDL_GameControllerClose(controller);
				}
			}
		
			break;


		case SDL_CONTROLLERAXISMOTION:

			instanceID = event.caxis.which;

			if (instanceID == 0) {

				// mainPlayer only updated by controller with instanceID = 0
				Uint8 axisID = event.caxis.axis;

				// Implement "Dead Zone" of 7849 to avoid analogue noise creating suprious movement
				const Sint16 deadZone = 7849;

				switch (axisID) {

					
				case SDL_CONTROLLER_AXIS_LEFTX:
					lx = (abs(event.caxis.value) < deadZone) ? 0 : event.caxis.value;
					break;

				case SDL_CONTROLLER_AXIS_LEFTY:
					ly = (abs(event.caxis.value) < deadZone) ? 0 : event.caxis.value;
					break;

				case SDL_CONTROLLER_AXIS_RIGHTX:
					rx = (abs(event.caxis.value) < deadZone) ? 0 : event.caxis.value;
					break;
				}
			}
			break;

		case SDL_CONTROLLERBUTTONDOWN:

			instanceID = event.cbutton.which;

			if (instanceID == 0) {

				// Find first "free" bullet
				int i = 0;
				while (bullets[i] != nullptr && i < MAX_BULLETS) {
					i++;
				}

				if (i < MAX_BULLETS) {

					bullets[i] = new BulletInstance();
					bullets[i]->initialise(bulletType, mainPlayer->getPosition(), Float2(200.0f, 0.0f));
				}
			}

			break;

		case SDL_CONTROLLERBUTTONUP:

			instanceID = event.cbutton.which;

			if (instanceID == 0) {

				printf("id:%d button:%d status:%d\n", instanceID, event.cbutton.button, event.cbutton.state);
			}

			break;
		}
	}

	
}

void SDLGame::update() {

		// FOR NOW USE timeDeltaInSeconds DIRECTLY - NOT IDEAL AS ERROR CAN ACCUMULATE AS DISCUSSED IN THE LECTURE!

		//this is where the big shits happen

		// Move mainPlayer based on key flags
		float xMovement = 0.0f;
		float yMovement = 0.0f;
		float rotation = 0.0f;

		// Recipe 4 - Check if controller state updated - if not default to keyboard
		if (lx != 0 || ly != 0 || rx != 0) {

			xMovement = float(lx) / 32768.0f * 100.0f;
			yMovement = float(ly) / 32768.0f * 100.0f;
			rotation = float(rx) / 32768.0f * (360.0f / 60.0f);

		}
		else {		//moving player based on key flags as otherwise action woudl repeat too quick

			if (keyState & Keys::Left)
				xMovement = -100.0f;

			if (keyState & Keys::Right)
				xMovement = 100.0f;			//the player being moved, every second/frama is when the move occurs

			if (keyState & Keys::Up)
				yMovement = -100.0f;
			else { yMovement = 80.00f; }	//moving down when not touching floor, but you can go up

											/*else if (keyState & ~Keys::Up)	//when key is released player "falls" to ground. DOES NOT WORK!
											yMovement = 100.0f;*/

											//want to make him jump, up and then down.
											//while (jumping = true) { yMovement = -100.0f; };


											/*
											if (keyState & Keys::Down)
											yMovement = 100.00f; //we dont need this yet, maybe for climbing down a ladder or something
											//it doesnt matter how

											//falling
											while (onGround && Keys::Up == false){  //if the player is not pressing up and the player is not on the ground

											yMovement = -300.0f; //the player will fall until they hit the ground

											}			//dont need down movement delibaretly anymore, use gravity instead.

											*/


											// Ensure length of direction vector is consistent for axis-aligned and diagonal movement
			float dx = float(xMovement);
			float dy = float(yMovement);

			float dLength = sqrtf(dx * dx + dy * dy);

			if (dLength > 0.0f) {

				dx = dx / dLength;
				dy = dy / dLength;

				dx *= 100.0f;
				dy *= 100.0f;

				xMovement = dx;
				yMovement = dy;
			}
		}


		//PLAYER CHECK ON FLOOR

		if (AABB::intersectAABB(mainPlayer->getBoundingBox(), floor->getBoundingBox())) {

			//printf_s("PLAYER IS ON FLOOR\n");		//works, game knows when player is touching ground.
			yMovement = -800.00f;	//too jittery? maybe make faster //faster means less noticable sorta

		}
		//else if when pressing up key 



		//IF PLAYER IS NOT ON GROUND THEY FALL
		/*
		if (AABB::intersectAABB  (mainPlayer->getBoundingBox(), floor->getBoundingBox()   )       ); {


		yMovement = 80.00f;

		}
		*/
		//DO EVERYTHING YOU NEED TO DO BEFORE YOU CALL THE METHOD. 
		mainPlayer->move(xMovement * timeDeltaInSeconds, yMovement * timeDeltaInSeconds);	//applying movement based on clock.


		mainPlayer->rotate(rotation * timeDeltaInSeconds); // Recipe 4 - rotate player based on joystick input


														   //moving enemy

														   //assuming on Patrol here, 
		float xEnemyMovement = 0.0f;
		float yEnemyMovement = 0.0f;
		//expand this

		xEnemyMovement = 10.0f;
		//this amount is how much is added or subtracted to the co-ords for the draw function.
		xEnemyMovement = -10.0f;		//trying to make them mvoe back and forth   have to call draw twice to make them move that way, so move while a timer ticks then it calls another move


		for (int i = 0; i < MAX_ENEMIES; i++) {

			FBIGuy[i].move(xEnemyMovement * timeDeltaInSeconds, yEnemyMovement * timeDeltaInSeconds);
			//calling move function on All FBIGuy enemies
		}

		/*
		if (FBIGuy[0].getHealth() < 0.0f) {

		printf_s("ENEMY DESTROYED\n");

		}
		*/

		// Recipe 9 - Update bullets
		for (int i = 0; i < MAX_BULLETS; i++) {

			if (bullets[i]) {
				bullets[i]->update(timeDeltaInSeconds);
			}
		}


		// Recipe 5 - Check collisions

		// Simple check between two objects
		if (AABB::intersectAABB(mainPlayer->getBoundingBox(), theOtherOne->getBoundingBox())) { //DONT KNOW how to add array objects with this, change AABB files later

			if (theOtherOne->getHealth() > 0.0f) {		//only deducts health if enemy is alive


														//method just to set alive to false, to check for drawing. Shoukldnt draw if they have more health 
														// A hit!
				mainPlayer->addHealth(-0.1f);

				if (mainPlayer->getHealth() <= 0.0f) {	//should only do this once, then wont accesss this again. 

					printf_s("GAME OVER!!!\n");
					gameRunning = false;
				}
			}
		}



		//first one checks for that one enemy. now this one will check for FBIGuy array

		if (AABB::intersectAABB(mainPlayer->getBoundingBox(), FBIGuy[0].getBoundingBox())) { //DONT KNOW how to add array objects with this, change AABB files later


			if (FBIGuy[0].getHealth() > 0.0f) {
				// A hit!
				mainPlayer->addHealth(-0.1f);
				//really unoptmised to do it one by one, but for loops dont work
				if (mainPlayer->getHealth() <= 0.0f) {

					printf_s("GAME OVER!!!\n");
					gameRunning = false;
				}
			}
		}

		if (AABB::intersectAABB(mainPlayer->getBoundingBox(), FBIGuy[1].getBoundingBox())) { //DONT KNOW how to add array objects with this, change AABB files later

			if (FBIGuy[1].getHealth() > 0.0f) {
				// A hit!
				mainPlayer->addHealth(-0.1f);

				if (mainPlayer->getHealth() <= 0.0f) {

					printf_s("GAME OVER!!!\n");
					gameRunning = false;
				}
			}
		}

		if (AABB::intersectAABB(mainPlayer->getBoundingBox(), FBIGuy[2].getBoundingBox())) { //DONT KNOW how to add array objects with this, change AABB files later

			if (FBIGuy[2].getHealth() > 0.0f) {

				// A hit!
				mainPlayer->addHealth(-1.5f);

				if (mainPlayer->getHealth() <= 0.0f) { //if player health is 0, end game

					printf_s("GAME OVER!!!\n");
					gameRunning = false;
				}
			}
		}	//now enemies will move toward player and kill'em


			

			// Recipe 9 - Check for bullet collisions with 'theOtherOne' Enemy object
		for (int i = 0; i < MAX_BULLETS; i++) {
			if (bullets[i]) {
				//dont do this if dead, this is getting messsy now. must be better way to do this but I dont know
				//if (theOtherOne != nullptr)		//its just one line but uhhh


				if (theOtherOne->getHealth() > 0.0f) {//only checks bullets if they're alive

					if (AABB::intersectAABB(bullets[i]->getBoundingBox(), theOtherOne->getBoundingBox())) {//if a bullet hits it

						printf_s("Hit!\n");
						bullets[i]->hit(theOtherOne);
						if (theOtherOne->getHealth() < 0.0f) {

							printf_s("ENEMY DESTROYED\n");
							//theOtherOne->changeStatus(false);
						}
					}

				}

				if (FBIGuy[0].getHealth() > 0.0f) {

					if (AABB::intersectAABB(bullets[i]->getBoundingBox(), FBIGuy[0].getBoundingBox())) {

						printf_s("Hit!\n");


						bullets[i]->hit(FBIGuy);	//hit specific enemy not just one.	//time for crab. 



						if (FBIGuy[0].getHealth() < 0.0f) {

							printf_s("ENEMY DESTROYED\n");
							//FBIGuy[0].changeStatus(false);
						}
					}
				}

				/////////////////////
				/*
				for (int j = 0; j < MAX_ENEMIES; j++) {

				if (FBIGuy[j].getHealth() > 0.0f) {

				if (AABB::intersectAABB(bullets[j]->getBoundingBox(), FBIGuy[j].getBoundingBox())) {

				printf_s("Hit!\n");
				bullets[j]->hit(FBIGuy);	//hit specific enemy not just one.
				if (FBIGuy[j].getHealth() < 0.0f) {	//doesnt work and I dont know why. access villation at bullet return bounding box.

				printf_s("ENEMY DESTROYED\n");

				}
				}
				}		//pork scratchings
				}		//////////////////////
				*/
				if (AABB::intersectAABB(bullets[i]->getBoundingBox(), FBIGuy[1].getBoundingBox())) {

					if (FBIGuy[1].getHealth() > 0.0f) {
						printf_s("Hit!\n");
						bullets[i]->hit(FBIGuy);
						if (FBIGuy[1].getHealth() <= 0.0f) {

							printf_s("ENEMY DESTROYED\n");
							//FBIGuy[1].changeStatus(false);		//method just to set alive to false, to check for drawing. DONT FORGET TO CLEAR 
						}

					}

				}
				if (AABB::intersectAABB(bullets[i]->getBoundingBox(), FBIGuy[2].getBoundingBox())) {
					if (FBIGuy[2].getHealth() > 0.0f) {

						printf_s("Hit!\n");

						bullets[i]->hit(FBIGuy);
						//the hit function comes from bullet instance, which gets it from projectile type, and simply calls the add health function doing 'damage
						if (FBIGuy[2].getHealth() <= 0.0f) {

							printf_s("ENEMY DESTROYED\n");
							//FBIGuy[2].changeStatus(false);
						}

					}

					//turns out I was right, adding a bounding box check to every instance of the enemy fixed that error. 

				}

				// Recipe 9 - Check for bullets out of range - delete when found
				for (int i = 0; i < MAX_BULLETS; i++) {

					if (bullets[i] && bullets[i]->exceededRange()) {

						printf("eol!\n");
						delete bullets[i];
						bullets[i] = nullptr;
					}
				}

			}
	    }
}


void SDLGame::draw() {

		// 1. Clear the screen
		SDL_RenderClear(gameRenderer);
		SDL_SetRenderDrawColor(gameRenderer, 0, 0, 0, 150); // Colour provided as red, green, blue and alpha (transparency) values (ie. RGBA)

		// 2. Draw the scene...

		SDL_Rect targetRect;
		targetRect.x = 0;
		targetRect.y = 0;
		targetRect.w = 1000;
		targetRect.h = 700;

		backgroundSprite->draw(gameRenderer, &targetRect, 0.0f);

		// Draw the main player
		mainPlayer->draw(gameRenderer);

		//drawing the floor
		floor->draw(gameRenderer);

		// Recipe 5 - instantiate something to collide against
		//if (theOtherOne != nullptr)   //if it is nullptr(e.g. dead), do not draw it



		//if (alive = true)	//put draw check on the actual thing you fucking spazmoid or not I dont know

		if (theOtherOne->getHealth() > 0.0f) {

			theOtherOne->draw(gameRenderer);
			//method just to set alive to false, to check for drawing. Shoukldnt draw if they have more health 
		}


		for (int i = 0; i < MAX_ENEMIES; i++) {

			if (FBIGuy[i].getHealth() > 0.0f) {

				FBIGuy[i].draw(gameRenderer);
				//calling on FBI guy array
			}
		}

			//draw, dont draew if alive, use get method




			// Recipe 9 - Draw bullets
			for (int i = 0; i < MAX_BULLETS; i++) {

				if (bullets[i]) {
					bullets[i]->draw(gameRenderer);
				}
			}


			// 3. Present the current frame to the screen
			SDL_RenderPresent(gameRenderer);
		
	}

