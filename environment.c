#include "environment.h"


void initializeEnvironment(Environment* enviro){
	//initialize map array to all sidewalk
	//load the tiles
	//loadBackground(gmu->enviro){

	loadEnviroTypes(enviro->enviro_types);
	//loadEnviroTypes(gmu);

	initializeBuildings(enviro);

//two buildings

}
/*
void loadBackground(Environment* enviro){
	memset(enviro->map, SIDEWALK, (MAP_ROW*MAP_COL));


}
*/
void loadEnviroTypes(SDL_Texture* enviro_types[AMOUNT_OF_ENVIRO_TYPES]){
//	gmu->enviro->enviro_types[0] = IMG_LoadTexture(
	

}





void initializeBuildings(Environment* enviro){



}
