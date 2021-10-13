#include "environment.h"


void initializeEnvironment(Environment* enviro){
	//initialize map array to all sidewalk
	memset(enviro->map, SIDEWALK, (MAP_ROW*MAP_COL));
	loadEnviroTypes(enviro->enviro_types);
	
	initializeBuildings(enviro);

//two buildings

}


void loadEnviroTypes(SDL_Texture* enviro_types[AMOUNT_OF_ENVIRO_TYPES]){


}





void initializeBuildings(Environment* enviro){



}
