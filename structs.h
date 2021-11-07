#include "libraries.h"
/***DEFINES***/
/*Enviroment*/
#define MAP_ROW 892
#define MAP_COL 1861
#define AMOUNT_OF_ENVIRO_TYPES 60
#define REND_ROW 128
#define REND_COL 128
/*Character*/
#define CENTER 512
#define AMOUNT_OF_FACE_TYPES 4
/*Interactables*/

/*Main*/
#define SCREEN_ROW 1024
#define SCREEN_COL 1024

#define START_COL 1000
#define START_ROW 445


/*** ENUM ***/

/*Enviroment*/
#define SIDEWALK 0
#define GRASS 10
#define STREET 20
#define BUILDING 30 //for collision detection (if x >= 30) will collide
#define WATER 40
#define STAIRS 50
#define NUMBER_OF_BUILDINGS 50
#define BUILDING_NAME_LENGTH 35

/*Character*/
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

/*Interactables*/

/*** Stucts ***/
/*Enviroment*/
typedef struct mapPoint{
	int x;
	int y;
}mapPoint;

typedef struct{
	int map[MAP_ROW][MAP_COL];
	SDL_Texture* enviro_types[AMOUNT_OF_ENVIRO_TYPES];
	char buildingNames[NUMBER_OF_BUILDINGS][BUILDING_NAME_LENGTH];
	struct mapPoint* interactableLocations[NUMBER_OF_BUILDINGS];
}Environment;

/*Character*/
typedef struct{
	int x_pos;
	int y_pos;
	int face;
	SDL_Texture* up;
	SDL_Texture* down;
	SDL_Texture* right;
	SDL_Texture* left;
	SDL_Texture* face_types[AMOUNT_OF_FACE_TYPES];
}Character;

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
	Character* character;
	//TODO add interactable
}GMU;
