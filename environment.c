#include "environment.h"


void initializeEnvironment(GMU *gmu){

	
	//initialize map array to all sidewalk
	//load the tiles
	loadBackground(gmu->enviro);
	loadEnviroTypes(gmu);
	
	//loading map items
	initializeGrass(gmu->enviro);
	initializeBuildings(gmu->enviro);

	//start position TODO remove
	gmu->enviro->map[START_ROW][START_COL] = 4;
	gmu->enviro->map[440][995] = 4;
	gmu->enviro->map[440][1005] = 4;
	gmu->enviro->map[450][1005] = 4;
	gmu->enviro->map[450][995] = 4;


	drawCircle(gmu->enviro, START_ROW, START_COL, 10, 4);
}

void loadBackground(Environment* enviro){
	int row, col;
	for (row = 0; row<MAP_ROW; ++row){
		for (col = 0; col<MAP_COL; ++col){
			enviro->map[row][col] = 0; 	
		}
	}

}

void loadEnviroTypes(GMU* gmu){
	gmu->enviro->enviro_types[1] = IMG_LoadTexture(gmu->game->renderer, "E_textures/grass.png");
	gmu->enviro->enviro_types[2] = IMG_LoadTexture(gmu->game->renderer, "E_textures/water.png");
	gmu->enviro->enviro_types[3] = IMG_LoadTexture(gmu->game->renderer, "E_textures/building.png");
	gmu->enviro->enviro_types[4] = IMG_LoadTexture(gmu->game->renderer, "E_textures/street.png");
	gmu->enviro->enviro_types[5] = IMG_LoadTexture(gmu->game->renderer, "E_textures/stairs.png");
}


void initializeGrass(Environment* enviro){
	drawRec(enviro, 951, 401, 1002, 428, GRASS);
	drawRec(enviro, 1009, 401, 1057, 428, GRASS);
}

void initializeBuildings(Environment* enviro){
	johnsonCenter(enviro);


}

void displayEnvironment(GMU* gmu){
	int row, col;

	for (row = gmu->renderOffset.y; row<(REND_ROW+gmu->renderOffset.y); ++row){
		for (col = gmu->renderOffset.x; col<(REND_COL+gmu->renderOffset.x); ++col){
			switch (gmu->enviro->map[row][col]){
				case GRASS:
					show(gmu, GRASS, row, col);
					break;
				case WATER:
					show(gmu, WATER, row, col);
					break;
				case BUILDING:
					show(gmu, BUILDING, row, col);
					break;
				case STREET:
					show(gmu, STREET, row, col);
					break;
				case STAIRS:
					show(gmu, STAIRS, row, col);
					break;

			}
		}
	}

}

void show(GMU* gmu, int type, int row, int col){
	SDL_Rect destination;
	SDL_QueryTexture(	gmu->enviro->enviro_types[type], 
				NULL, 
				NULL, 
				&destination.w, 
				&destination.h);

	destination.x = col*8 - gmu->renderOffset.x*8;
	destination.y = row*8 - gmu->renderOffset.y*8;


	SDL_RenderCopy(		gmu->game->renderer, 
				gmu->enviro->enviro_types[type], 
				NULL, 
				&destination);

}

void johnsonCenter(Environment* enviro){
	drawRec(enviro, 877, 458, 1089, 565, BUILDING);
	drawRec(enviro, 997, 451, 1015, 460, BUILDING);
	drawRec(enviro, 998, 558, 1013, 570, BUILDING);


}

void drawRec(Environment* enviro, int x1, int y1, int x2, int y2, int type){
	int i,j;
	for(i=y1; i<y2; ++i){
		for(j=x1; j<x2; ++j){
			enviro->map[i][j] = type;
		}

	}

}

void drawCircle(Environment* enviro, int Cx, int Cy, int r, int type){
	int x1, x2, y1, y2; 
	x1 = Cx -r;
	x2 = Cx + r;
	y1 = Cy + r;
	y2 = Cy + r;

	int i,j;
	for(i=y1; i<y2; ++i){
		for(j=x1; j<x2; ++j){

			if( (sqrt( ( pow((j-Cx),2) ) + (pow(( i-Cy),2) ) ) ) <= r){ //FIXME not working fix
				enviro->map[i][j] = type;
			}
		}

	}



}
