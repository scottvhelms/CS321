//Author Scott Helms


/*** Include ***/
#include "libraries.h"
#include "structs.h"


/*** Declarations ***/
//void initializeEnvironment(Environment* envion);
void initializeEnvironment(GMU* gmu);
void initializeGrass(Environment* enviro);
void initializeBuildings(Environment* enviro);
//void loadEnviroTypes(ySDL_Texture* enviro_types[AMOUNT_OF_ENVIRO_TYPES], SDL_Renderer *renderer);
void loadEnviroTypes(GMU* gmu);
void loadBackground(Environment* enviro);

void displayEnvironment(GMU* gmu);
void show(GMU* gmu, int type, int row, int col);
void drawRec(Environment* enviro, int x1, int x2, int y1, int y2, int type);
void johnsonCenter(Environment* enviro);
void drawCircle(Environment* enviro, int Cx, int Cy, int r, int type);
