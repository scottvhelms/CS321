//Author Scott Helms


/*** Include ***/
#include "libraries.h"
//#include "main.h"


/*** Define ***/

#define MAP_ROW 10000 //default map size TODO figure out actual size needed
#define MAP_COL 10000

/*** Extern ***/
//extern GMU gmu;

/*** Struct ***/
typedef struct{
	int map[MAP_ROW][MAP_COL];
} Environment;





/*** Declarations ***/
void initializeEnvironment(Environment* envion);


