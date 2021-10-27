/*** Include ***/

#include "libraries.h"
//#include "structs.h"

#include "environment.h"
#include "character.h"
#include "interactables.h"

/*** Define ***/
//#define SCREEN_ROW 1024 //size of the screen, these are test values and can be changed 
//#define SCREEN_COL 1024 //TODO define real screen size

/*** Struct ***/
/*
//structure for the game window and renderer
typedef struct{
	SDL_Renderer *renderer;
	SDL_Window *window;
}Game;

//structure for the elements of the game
typedef struct{
	Game* game;
	Environment* enviro;
	SDL_Point renderOffset;
	//TODO add character
	//TODO add interactables
}GMU;

*/
/*** Declarations ***/
void initializeGMU(GMU* gmu);
void initializeSDL(Game* game);
void endGame(GMU* gmu);
void getInput(GMU* gmu);
void setUpDisplay(GMU* gmu);
void display(GMU* gmu);

