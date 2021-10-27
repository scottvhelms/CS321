#include "libraries.h"
/***DEFINES***/
/*Enviroment*/
#define MAP_ROW 1000
#define MAP_COL 1000
#define AMOUNT_OF_ENVIRO_TYPES 6
#define REND_ROW 128
#define REND_COL 128
/*Character*/

/*Interactables*/

/*Main*/
#define SCREEN_ROW 1024
#define SCREEN_COL 1024

#define START_X 0
#define START_Y 0


/*** ENUM ***/

/*Enviroment*/

enum enviro_types{
	SIDEWALK = 0,
	GRASS = 1,
	WATER = 2,
	BUILDING = 3,
	STREET = 4,
	STAIRS = 5
};

/*Character*/

/*Interactables*/

/*** Stucts ***/
/*Enviroment*/
typedef struct{
	int map[MAP_ROW][MAP_COL];
	SDL_Texture* enviro_types[AMOUNT_OF_ENVIRO_TYPES];
}Environment;

/*Character*/

/*Interactables*/

/*Main*/



typedef struct{
	SDL_Renderer *renderer;
	SDL_Window *window;
}Game;

typedef struct{
	Game* game;
	Environment* enviro;
	SDL_Point renderOffset;
	//TODO add character
	//TODO add interactable
}GMU;
