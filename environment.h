//Author Scott Helms


/*** Include ***/
#include "libraries.h"
//#include "main.h"


/*** Define ***/

#define MAP_ROW 10000 //default map size TODO figure out actual size needed
#define MAP_COL 10000

#define AMOUNT_OF_ENVIRO_TYPES 6 



/*** ENUM ***/
enum enviro_types {	SIDEWALK = 0, 
			GRASS = 1, 
			WATER = 2, 
			BUILDING = 3, 
			STREET = 4, 
			STAIRS = 5
};

/*** Struct ***/
typedef struct{
	int map[MAP_ROW][MAP_COL];
	SDL_Texture* enviro_types[AMOUNT_OF_ENVIRO_TYPES];
	
} Environment;



/*** Extern ***/
//extern struct GMU gmu;



/*** Declarations ***/
void initializeEnvironment(Environment* envion);
//void initializeEnvironment(struct GMU* gmu);

void initializeBuildings(Environment* envion);
void loadEnviroTypes(SDL_Texture* enviro_types[AMOUNT_OF_ENVIRO_TYPES]);
//void loadEnviroTypes(struct GMU* gmu);
//void loadBackground(Environment* enviro);




