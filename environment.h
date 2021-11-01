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
void drawCircle(Environment* enviro, int center_x, int center_y, int radius, int type);
void drawTriangle(Environment* envior, double x1, double y1, double x2, double y2, double x3, double y3, int type); 
void drawQuad(Environment* envior, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, int type); 
int withinLine(double x1, double y1, double x2, double y2, double x3, double y3, double point_x, double point_y); 
int findMin(int a, int b, int c, int d);
int findMax(int a, int b, int c, int d);

void johnsonCenter(Environment* enviro);


