#include "environment.h"


void initializeEnvironment(GMU *gmu){
	//initialize map array to all sidewalk
	//load the tiles
	loadBackground(gmu->enviro);
	loadEnviroTypes(gmu);
	
	//loading map items
	initializeGrass(gmu->enviro);
	initializeBuildings(gmu->enviro);
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
//	drawRec(enviro, 400, 455, 924, 990, GRASS);
//	drawRec(enviro, 400, 455, 1010, 1090, GRASS);
//	drawRec(enviro, 330, 370, 924, 990, GRASS);
//	drawRec(enviro, 330, 370, 1010, 1090, GRASS);
//	drawCircle(enviro, 1005, 434, 14, GRASS);
//	drawTriangle(enviro, 1010, 420, 1000, 440, 1020, 430, GRASS);
//	drawTriangle(enviro, 970, 420, 970, 440, 990, 430, GRASS);
//	drawTriangle(enviro, 1050, 440, 1030, 440, 1040, 420, GRASS);
//	drawQuad(enviro, 1000, 420, 1010, 430, 1020, 420, 1010, 410, GRASS);

//	enviro->map[420][1010] = WATER;
//	enviro->map[440][1000] = WATER;
//	enviro->map[430][1020] = WATER;

	
//	drawTriangle(enviro, 1010, 420, 1000, 440, 1020, 430, GRASS);
//	drawTriangle(enviro, 1010, 420, 1000, 440, 1020, 430, GRASS);


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


void drawRec(Environment* enviro, int x1, int y1, int x2, int y2, int type){
	int i,j;
	for(i=y1; i<y2; ++i){
		for(j=x1; j<x2; ++j){
			enviro->map[i][j] = type;
		}

	}

}


void drawCircle(Environment* enviro, int center_x, int center_y, int radius, int type){
	int x1 = center_x - radius;
	int x2 = center_x + radius;
	int y1 = center_y - radius;
	int y2 = center_y + radius;

	int i,j;
	for(i=y1; i<y2; ++i){
		for(j=x1; j<x2; ++j){
			if( (sqrt( pow( (j - center_x), 2 ) + pow( (i - center_y), 2 ) )) <= radius) {
				enviro->map[i][j] = type;
			}
		}

	}

}

void drawTriangle(Environment* enviro, double x1, double y1, double x2, double y2, double x3, double y3, int type){
	double grid_x1=0, grid_x2=0, grid_y1=0, grid_y2=0;
	
	grid_x1 = findMin(x1, x2, x3, -1);
	grid_x2 = findMax(x1, x2, x3, -1);
	grid_y1 = findMin(y1, y2, y3, -1);
	grid_y2 = findMax(y1, y2, y3, -1);

	int i,j;
	int check_1 = 0, check_2 =  0, check_3 = 0;
	for(i=grid_y1; i<grid_y2; ++i){
		for(j=grid_x1; j<grid_x2; ++j){
			check_1 = withinLine(x1,y1,x2,y2,x3,y3,j,i);
			check_2 = withinLine(x2,y2,x3,y3,x1,y1,j,i);
			check_3 = withinLine(x3,y3,x1,y1,x2,y2,j,i);
			
			if(check_1 && check_2 && check_3){
				enviro->map[i][j] = type;
			} 
		}
	}

}


void drawQuad(Environment* enviro, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, int type){
	double grid_x1=0, grid_x2=0, grid_y1=0, grid_y2=0;
	
	grid_x1 = findMin(x1, x2, x3, x4);
	grid_x2 = findMax(x1, x2, x3, x4);
	grid_y1 = findMin(y1, y2, y3, y4);
	grid_y2 = findMax(y1, y2, y3, y4);

	int i,j;
	int check_1 = 0, check_2 =  0, check_3 = 0, check_4 = 0;
	for(i=grid_y1; i<grid_y2; ++i){
		for(j=grid_x1; j<grid_x2; ++j){
			check_1 = withinLine(x1,y1,x2,y2,x3,y3,j,i);
			check_2 = withinLine(x2,y2,x3,y3,x4,y4,j,i);
			check_3 = withinLine(x3,y3,x4,y4,x1,y1,j,i);
			check_4 = withinLine(x4,y4,x1,y1,x2,y2,j,i);
			
			if(check_1 && check_2 && check_3 && check_4){
				enviro->map[i][j] = type;
			} else {
				enviro->map[i][j] = STREET;

			}

		}
	}

}

int withinLine(double x1, double y1, double x2, double y2, double x3, double y3, double point_x, double point_y){
	if( x1 == x2){
		return 1;
	}	
	if (y1 == y2){
		return 1;
	}

	double line_slope = (y1-y2)/(x1-x2);
	double B = y1-(line_slope*x1);
	double y_at_x_point = (line_slope * point_x) + B;
	double y_at_x_corner = (line_slope * x3) + B;

	if ((y3 >= y_at_x_corner) && (point_y >= y_at_x_point)){
		return 1;
	}
	if ((y3 <= y_at_x_corner) && (point_y <= y_at_x_point)){
		return 1;
	}

	return 0;
}

int findMin(int a, int b, int c, int d){
	int min = a;
	if(a<b){
		min = a;
	}
	if(b < min){
		min = b;
	}
	if (c < min){
		min = c;
	}
	if (d < 0){
		return min;
	} else if (d < min){
		min = d;
	}

	return min;
}

int findMax(int a, int b, int c, int d){
	int max = a;
	if(a>b){
		max = a;
	}
	if(b > max){
		max = b;
	}
	if (c > max){
		max = c;
	}
	if (d < 0){
		return max;
	} else if (d > max){
		max = d;
	}

	return max;
}


void johnsonCenter(Environment* enviro){
	drawRec(enviro, 875, 455, 1090, 565, BUILDING);

}


