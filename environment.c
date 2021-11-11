//Author Scott Helms

#include "environment.h"

/***INIT and LOAD***/
void initializeEnvironment(GMU *gmu){
	//inti fonts for names
	gmu->enviro->font = TTF_OpenFont("E_textures/EnterCommand.ttf", 64);
	
	//initialize map array to all sidewalk
	//load the tiles
	loadBackground(gmu->enviro);
	loadEnviroTypes(gmu);
	
	//loading map items
	initializeLocations(gmu->enviro);
	initializeNames(gmu->enviro);
	initializeGrass(gmu->enviro);
	initializeBuildings(gmu->enviro);
	initializeStreets(gmu->enviro);

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
	gmu->enviro->enviro_types[10] = IMG_LoadTexture(gmu->game->renderer, "E_textures/grass.png");
	gmu->enviro->enviro_types[20] = IMG_LoadTexture(gmu->game->renderer, "E_textures/street.png");
	gmu->enviro->enviro_types[30] = IMG_LoadTexture(gmu->game->renderer, "E_textures/building.png");
	gmu->enviro->enviro_types[40] = IMG_LoadTexture(gmu->game->renderer, "E_textures/water.png");
	gmu->enviro->enviro_types[50] = IMG_LoadTexture(gmu->game->renderer, "E_textures/stairs.png");
}

void initializeLocations(Environment* enviro){
	int row;
	mapPoint* point = NULL;
	for (row = 0; row<NUMBER_OF_BUILDINGS; ++row){
		point = (mapPoint*)malloc(sizeof(mapPoint)); //TODO free
		if(point == NULL){
			printf("Malloc Failure");
			exit(1);
		}
		point->x = 0;
		point->y = 0;
		point->next = NULL;
		enviro->interactableLocations[row] = point;
	}
}

void initializeNames(Environment* enviro){
	int row, col;
	for (row = 0; row<NUMBER_OF_BUILDINGS; ++row){
		for (col = 0; col<BUILDING_NAME_LENGTH; ++col){
			enviro->buildingNames[row][col] = '\0'; 	
		}
	}

}

void initializeGrass(Environment* enviro){
	drawRec(enviro, 855, 400, 880, 425, GRASS);//1 N JC
	drawRec(enviro, 888, 400, 944, 425, GRASS);//2
	drawRec(enviro, 952, 400, 1000, 425, GRASS);//3
	drawRec(enviro, 1008, 400, 1055, 425, GRASS);//4
	drawRec(enviro, 1063, 400, 1104, 425, GRASS);//5
	drawRec(enviro, 888, 433, 1000, 464, GRASS);//6
	drawRec(enviro, 1008, 433, 1104, 464, GRASS);//7


	drawCircle(enviro, 1004, 429, 9, SIDEWALK);
	drawQuad(enviro, 1056, 407, 1056, 400, 1007, 428, 1011, 432, SIDEWALK);

	drawRec(enviro, 897, 383, 966, 392, GRASS);//8
	drawRec(enviro, 982, 386, 1000, 392, GRASS);//9
	drawRec(enviro, 1008, 386, 1049, 392, GRASS);//10
	drawRec(enviro, 1057, 386, 1075, 392, GRASS);//11
	drawRec(enviro, 1008, 375, 1049, 380, GRASS);//12
	drawRec(enviro, 982, 375, 1000, 380, GRASS);//13

	drawRec(enviro, 1083, 300, 1152, 392, GRASS);//14
	drawRec(enviro, 1112, 400, 1281, 710, GRASS);//15
	drawRec(enviro, 1160, 315, 1172, 392, GRASS);//16
	drawRec(enviro, 1180, 300, 1220, 392, GRASS);//17

	drawRec(enviro, 1148, 300, 1184, 315, SIDEWALK);
	drawRec(enviro, 1114, 300, 1128, 330, SIDEWALK);
	drawQuad(enviro, 1221, 299, 1221, 308, 1134, 398, 1128, 395, SIDEWALK);
	drawQuad(enviro, 1127, 313, 1232, 336, 1231, 341, 1128, 319, SIDEWALK);
	drawQuad(enviro, 1161, 369, 1173, 380, 1173, 384, 1158, 370, SIDEWALK);
	drawRec(enviro, 1203, 384, 1256, 409, SIDEWALK);







}

void initializeBuildings(Environment* enviro){
	johnsonCenter(enviro);
	davidKingHall(enviro);
	planetaryHall(enviro);
	exploratoryHall(enviro);
	enterpriseHall(enviro);
	researchHall(enviro);
	shenandoahParkingDeck(enviro);	
	nguyenEngineeringBuilding(enviro);
	artAndDesignBuilding(enviro);
	libertySquareHousing(enviro);
	aquaticAndFitnessCenter(enviro);
	innovationHall(enviro);
	musicAndTheaterBuilding(enviro);
	collegeHall(enviro);
	buchananHall(enviro);
	performingArtsBuilding(enviro);
	concertHall(enviro);
	masonPondParkingDeck(enviro);
	harrisTheater(enviro);
	horizonHall(enviro);
	fenwickLibrary(enviro);
	theHub(enviro);
	southsideDining(enviro);
	skylineFitnessCenter(enviro);
	theCommons(enviro);
	commonwealthHall(enviro);
	dominionHall(enviro);
	northernNeck(enviro);
	lectureHall(enviro);
	eastBuilding(enviro);
	krugHall(enviro);
	finleyBuilding(enviro);
	westBuilding(enviro);
	studentUnionBuilding(enviro);
	aquiaBuilding(enviro);
	thompsonHall(enviro);
	rappahannockParkingDeck(enviro);
	alanAndSallyHall(enviro);
	petersonHall(enviro);
	rogers(enviro);
	whiteTop(enviro);
	parkingServices(enviro);
}

void initializeStreets(Environment* enviro){
	//roads
	drawQuad(enviro, 84, 0, 112, 0, 0, 323, 0, 241, STREET); //1
	drawQuad(enviro, 0, 155, 239, 242, 233, 276, 0, 186, STREET); //2
	drawQuad(enviro, 178, 0, 346, 64, 339, 75, 135, 0, STREET); //3
	drawQuad(enviro, 285, 185, 794, 191, 794, 200, 279, 195, STREET); //4
	drawQuad(enviro, 433, 646, 683, 640, 684, 655, 438, 656, STREET); //5
	drawQuad(enviro, 885, 845, 1106, 846, 1104, 861, 890, 857, STREET); //6
	drawQuad(enviro, 1217, 842, 1533, 579, 1542, 595, 1227, 840, STREET); //7
	drawQuad(enviro, 1345, 785, 1546, 893, 1514, 893, 1336, 795, STREET); //8

	//parking lots
	drawQuad(enviro, 1428, 811, 1681, 611, 1777, 893, 1573, 893, STREET); //1
}


/***Display***/

void displayEnvironment(GMU* gmu){


	//displaying map
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

	//displaying building name (if Applicable)
	displayBuildingName(gmu);


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

void displayBuildingName(GMU* gmu){
	int row;
	mapPoint* current;
	//32 grid around the robots current pos for interactable detection
	int x_high = gmu->character->x_map_pos + 32;
	int x_low =  gmu->character->x_map_pos - 32;
	int y_high = gmu->character->y_map_pos + 32;
	int y_low =  gmu->character->y_map_pos - 32;
	for (row = 0; row<NUMBER_OF_BUILDINGS; ++row){
		current = gmu->enviro->interactableLocations[row];
		while(current!=NULL){
			if ( 	(x_low <= current->x) &&
				(current->x <= x_high) &&
				(y_low <= current->y) &&
				(current->y <= y_high) ){

				showName(gmu, gmu->enviro->buildingNames[row]);
				return;

			} else {
				current = current->next;
			}
		}
	}

}


void showName(GMU* gmu, char* text){
	SDL_Rect name;
	name.w = 84*8;
	name.h = 8*8;
	name.x = CENTER - name.w/2;
	name.y = 16;
	
	//fill
	SDL_SetRenderDrawBlendMode(gmu->game->renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(gmu->game->renderer, 236, 236, 236, 150);
	SDL_RenderFillRect(gmu->game->renderer, &name);
	//border
	SDL_SetRenderDrawBlendMode(gmu->game->renderer, SDL_BLENDMODE_NONE);
	SDL_SetRenderDrawColor(gmu->game->renderer, 0, 0, 0, 150);
	SDL_RenderDrawRect(gmu->game->renderer, &name);
	//Text
	SDL_Color black = {0,0,0,255};
	SDL_Surface *word_surface = TTF_RenderUTF8_Blended(gmu->enviro->font, text, black);
	SDL_Texture *word_texture = SDL_CreateTextureFromSurface(gmu->game->renderer, word_surface);
	SDL_FreeSurface(word_surface);

	//centering text
	name.x = CENTER - (strlen(text)/2)*22;

	SDL_QueryTexture(word_texture, NULL, NULL, &name.w, &name.h);	
	SDL_RenderCopy(gmu->game->renderer, word_texture, NULL, &name);
}
/***TOOLS***/


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

//TODO free all the locations
void johnsonCenter(Environment* enviro){ //0
	//name
	memcpy (enviro->buildingNames[0], "Johnson Center", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[0]->x = 1004;
	enviro->interactableLocations[0]->y = 448;
	enviro->interactableLocations[0]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[0]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[0]->next->x = 1096;
	enviro->interactableLocations[0]->next->y = 509;
	enviro->interactableLocations[0]->next->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[0]->next->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 3
	enviro->interactableLocations[0]->next->next->x = 1004;
	enviro->interactableLocations[0]->next->next->y = 572;
	enviro->interactableLocations[0]->next->next->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[0]->next->next->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 4
	enviro->interactableLocations[0]->next->next->next->x = 876;
	enviro->interactableLocations[0]->next->next->next->y = 560;
	enviro->interactableLocations[0]->next->next->next->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[0]->next->next->next->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 5
	enviro->interactableLocations[0]->next->next->next->next->x = 876;
	enviro->interactableLocations[0]->next->next->next->next->y = 459;
	enviro->interactableLocations[0]->next->next->next->next->next = NULL;

	//map
	drawRec(enviro, 875, 458, 1090, 562, BUILDING);
	drawTriangle(enviro, 876, 457, 904, 455, 874, 477, SIDEWALK);
	drawTriangle(enviro, 875, 540, 898, 563, 875, 561, SIDEWALK);
	drawCircle(enviro, 884, 464, 11, BUILDING);
	drawCircle(enviro, 1004, 457, 8, BUILDING);
	drawCircle(enviro, 1089, 511, 8, BUILDING);
	drawCircle(enviro, 1006, 564, 8, BUILDING);
	drawCircle(enviro, 883, 554, 9, BUILDING);
}

void davidKingHall(Environment* enviro){//1
	//name
	memcpy (enviro->buildingNames[1], "David King Hall", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[1]->x = 975;
	enviro->interactableLocations[1]->y = 389;
	enviro->interactableLocations[1]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[1]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[1]->next->x = 882;
	enviro->interactableLocations[1]->next->y = 388;
	enviro->interactableLocations[1]->next->next = NULL;

	//map
	drawRec(enviro, 877, 316, 986, 388, BUILDING);
}

void planetaryHall(Environment* enviro){//2
	//name
	memcpy (enviro->buildingNames[2], "Planetary Hall", BUILDING_NAME_LENGTH);
	
	//loc 1
	enviro->interactableLocations[2]->x = 1065;
	enviro->interactableLocations[2]->y = 379;
	enviro->interactableLocations[2]->next = NULL;

	//map
	drawRec(enviro, 1034, 323, 1135, 376, BUILDING);
	drawRec(enviro, 1103, 323, 1136, 380, BUILDING);
	drawRec(enviro, 1053, 269, 1119, 328, BUILDING);
	drawRec(enviro, 1028, 269, 1058, 291, BUILDING);
	drawCircle(enviro, 1028, 280, 11, BUILDING);
}

void exploratoryHall(Environment* enviro){//3
	//name
	memcpy (enviro->buildingNames[3], "Exploratory Hall", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[3]->x = 1165;
	enviro->interactableLocations[3]->y = 310;
	enviro->interactableLocations[3]->next = NULL;


	//map
	drawRec(enviro, 1118, 248, 1214, 306, BUILDING);
	drawRec(enviro, 1113, 255, 1223, 299, BUILDING);
}

void enterpriseHall(Environment* enviro){//4
	//name
	memcpy (enviro->buildingNames[4], "Enterprise Hall", BUILDING_NAME_LENGTH);
	
	//loc 1
	enviro->interactableLocations[4]->x = 1214;
	enviro->interactableLocations[4]->y = 398;
	enviro->interactableLocations[4]->next = NULL;


	//map
	drawRec(enviro, 1203, 347, 1283, 387, BUILDING);
	drawRec(enviro, 1205, 409, 1246, 467, BUILDING);
	drawCircle(enviro, 1226, 455, 16, BUILDING);
}

void researchHall(Environment* enviro){//5
	//name
	memcpy (enviro->buildingNames[5], "Research Hall", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[5]->x = 1401;
	enviro->interactableLocations[5]->y = 390;
	enviro->interactableLocations[5]->next = NULL;


	//map
	drawQuad(enviro, 1316, 352, 1416, 352, 1416, 386, 1316, 392, BUILDING);
	drawQuad(enviro, 1416, 352, 1470, 352, 1470, 394, 1416, 386, BUILDING);
	drawCircle(enviro, 1418, 400, 7, BUILDING); 
}

void shenandoahParkingDeck(Environment* enviro){//6
	//name
	memcpy (enviro->buildingNames[6], "Shenandoah Parking Deck", BUILDING_NAME_LENGTH);
	
	//loc 1
	enviro->interactableLocations[6]->x = 1270;
	enviro->interactableLocations[6]->y = 235;
	enviro->interactableLocations[6]->next = NULL;


	//map
	drawQuad(enviro, 1242, 201, 1400, 318, 1456, 244, 1304, 126, BUILDING);
}

void nguyenEngineeringBuilding(Environment* enviro){//7
	//name
	memcpy (enviro->buildingNames[7], "Nguyen Engineering Building", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[7]->x = 1490;
	enviro->interactableLocations[7]->y = 418;
	enviro->interactableLocations[7]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[7]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[7]->next->x = 1501;
	enviro->interactableLocations[7]->next->y = 526;
	enviro->interactableLocations[7]->next->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[7]->next->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 3
	enviro->interactableLocations[7]->next->next->x = 1572;
	enviro->interactableLocations[7]->next->next->y = 436;
	enviro->interactableLocations[7]->next->next->next = NULL;

	//map
	drawQuad(enviro, 1493, 519, 1515, 402, 1567, 379, 1540, 529, BUILDING);
	drawQuad(enviro, 1577, 373, 1639, 424, 1603, 442, 1539, 392, BUILDING);
	drawQuad(enviro, 1579, 420, 1549, 455, 1533, 432, 1560, 398, BUILDING);
}

void artAndDesignBuilding(Environment* enviro){//8
	//name
	memcpy (enviro->buildingNames[8], "Art and Design Building", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[8]->x = 1324;
	enviro->interactableLocations[8]->y = 520;
	enviro->interactableLocations[8]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[8]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[8]->next->x = 1434;
	enviro->interactableLocations[8]->next->y = 518;
	enviro->interactableLocations[8]->next->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[8]->next->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 3
	enviro->interactableLocations[8]->next->next->x = 1429;
	enviro->interactableLocations[8]->next->next->y = 579;
	enviro->interactableLocations[8]->next->next->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[8]->next->next->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 4
	enviro->interactableLocations[8]->next->next->next->x = 1329;
	enviro->interactableLocations[8]->next->next->next->y = 581;
	enviro->interactableLocations[8]->next->next->next->next = NULL;

	//map
	drawQuad(enviro, 1344, 517, 1433, 518, 1428, 584, 1350, 582, BUILDING);
	drawRec(enviro, 1329, 531, 1352, 568, BUILDING);
	drawRec(enviro, 1427, 526, 1444, 569, BUILDING);
	drawQuad(enviro, 1314, 524, 1335, 528, 1336, 571, 1314, 571, BUILDING);
	drawQuad(enviro, 1441, 522, 1454, 525, 1445, 572, 1431, 569, BUILDING);
	drawRec(enviro, 1323, 558, 1337, 578, BUILDING);
}

void libertySquareHousing(Environment* enviro){//9
	memcpy (enviro->buildingNames[9], "Liberty Square Housing", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[9]->x = 1623;
	enviro->interactableLocations[9]->y = 147;
	enviro->interactableLocations[9]->next = NULL;


	drawQuad(enviro, 1536, 100, 1552, 71, 1616, 153, 1593, 171, BUILDING);
	drawQuad(enviro, 1544, 61, 1612, 9, 1632, 32, 1561, 84, BUILDING);
	drawQuad(enviro, 1630, 15, 1641, 28, 1627, 36, 1620, 20, BUILDING);
	drawQuad(enviro, 1648, 15, 1711, 93, 1687, 111, 1627, 35, BUILDING);
 	drawQuad(enviro, 1691, 116, 1711, 103, 1743, 181, 1713, 188, BUILDING);
	drawQuad(enviro, 1642, 198, 1702, 178, 1715, 205, 1649, 227, BUILDING);
	drawQuad(enviro, 1715, 183, 1729, 183, 1731, 195, 1718, 201, BUILDING);
}

void aquaticAndFitnessCenter(Environment* enviro){//10
	memcpy (enviro->buildingNames[10], "Aquatic and Fitness Center", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[10]->x = 1711;
	enviro->interactableLocations[10]->y = 399;
	enviro->interactableLocations[10]->next = NULL;

	drawQuad(enviro, 1724, 364, 1805, 353, 1813, 416, 1730, 426, BUILDING);
	drawQuad(enviro, 1729, 422, 1838, 410, 1847, 469, 1736, 483, BUILDING);
	drawQuad(enviro, 1717, 484, 1837, 468, 1833, 474, 1721, 507, BUILDING);
	drawQuad(enviro, 1707, 371, 1700, 349, 1749, 326, 1765, 361, BUILDING);
	drawQuad(enviro, 1800, 364, 1825, 362, 1835, 409, 1808, 418, BUILDING);
}
void innovationHall(Environment* enviro){//11
	memcpy (enviro->buildingNames[11], "Innovation Hall", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[11]->x = 1246;
	enviro->interactableLocations[11]->y = 628;
	enviro->interactableLocations[11]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[11]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[11]->next->x = 1212;
	enviro->interactableLocations[11]->next->y = 693;
	enviro->interactableLocations[11]->next->next = NULL;

	drawRec(enviro, 1203, 572, 1239, 684, BUILDING);
	drawRec(enviro, 1236, 639, 1280, 685, BUILDING);
	drawRec(enviro, 1234, 681, 1271, 690, BUILDING);
	drawRec(enviro, 1203, 562, 1218, 572, BUILDING);
}

void musicAndTheaterBuilding(Environment* enviro){//12
	memcpy (enviro->buildingNames[12], "Music and Theater Building", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[12]->x = 1048;
	enviro->interactableLocations[12]->y = 609;
	enviro->interactableLocations[12]->next = NULL;

	drawRec(enviro, 1038, 615, 1083, 668, BUILDING);
	drawRec(enviro, 1038, 615, 1097, 654, BUILDING);
	drawRec(enviro, 1011, 620, 1047, 660, BUILDING);
	drawRec(enviro, 1093, 638, 1112, 648, BUILDING);
}

void collegeHall(Environment* enviro){//13
	memcpy (enviro->buildingNames[13], "College Hall", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[13]->x = 1099;
	enviro->interactableLocations[13]->y = 634;
	enviro->interactableLocations[13]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[13]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[13]->next->x = 1130;
	enviro->interactableLocations[13]->next->y = 699;
	enviro->interactableLocations[13]->next->next = NULL;

	drawRec(enviro, 1110, 629, 1132, 698, BUILDING);
	drawRec(enviro, 1128, 643, 1137, 654, BUILDING);
	drawRec(enviro, 1117, 693, 1126, 709, BUILDING);
}

void buchananHall(Environment* enviro){//14
	memcpy (enviro->buildingNames[14], "Buchanan Hall", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[14]->x = 1061;
	enviro->interactableLocations[14]->y = 773;
	enviro->interactableLocations[14]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[14]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[14]->next->x = 1139;
	enviro->interactableLocations[14]->next->y = 776;
	enviro->interactableLocations[14]->next->next = NULL;

	drawRec(enviro, 1068, 710, 1138, 783, BUILDING);
	drawRec(enviro, 1110, 706, 1138, 721, BUILDING);
}

void performingArtsBuilding(Environment* enviro){//15
	memcpy (enviro->buildingNames[15], "Performing Arts Building", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[15]->x = 977;
	enviro->interactableLocations[15]->y = 732;
	enviro->interactableLocations[15]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[15]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[15]->next->x = 967;
	enviro->interactableLocations[15]->next->y = 643;
	enviro->interactableLocations[15]->next->next = NULL;


	drawRec(enviro, 876, 647, 985, 729, BUILDING);
	drawRec(enviro, 878, 613, 961, 651, BUILDING);
	drawQuad(enviro, 872, 601, 913, 612, 909, 641, 868, 636, BUILDING);
	drawQuad(enviro, 898, 600, 924, 611, 922, 637, 893, 635, BUILDING);
	drawQuad(enviro, 921, 602, 947, 610, 941, 642, 915, 638, BUILDING);
	drawQuad(enviro, 947, 603, 969, 610, 965, 640, 940, 639, BUILDING);
}

void concertHall(Environment* enviro){//16
	memcpy (enviro->buildingNames[16], "Concert Hall", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[16]->x = 976;
	enviro->interactableLocations[16]->y = 756;
	enviro->interactableLocations[16]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[16]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[16]->next->x = 973;
	enviro->interactableLocations[16]->next->y = 830;
	enviro->interactableLocations[16]->next->next = NULL;


	drawRec(enviro, 890, 748, 970, 838, BUILDING);
	drawRec(enviro, 881, 799, 970, 838, BUILDING);
	drawRec(enviro, 877, 734, 970, 758, BUILDING);
}

void masonPondParkingDeck(Environment* enviro){//17
	memcpy (enviro->buildingNames[17], "Mason Pond Parking Deck", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[17]->x = 715;
	enviro->interactableLocations[17]->y = 684;
	enviro->interactableLocations[17]->next = NULL;


	drawRec(enviro, 717, 685, 808, 832, BUILDING);
	drawRec(enviro, 700, 686, 719, 712, BUILDING);
	drawRec(enviro, 709, 823, 723, 837, SIDEWALK);
	drawRec(enviro, 800, 824, 814, 838, SIDEWALK);
	drawRec(enviro, 800, 682, 815, 693, SIDEWALK);
	drawRec(enviro, 714, 682, 721, 694, SIDEWALK);
}

void harrisTheater(Environment* enviro){//18
	memcpy (enviro->buildingNames[18], "Harris Theather", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[18]->x = 766;
	enviro->interactableLocations[18]->y = 614;
	enviro->interactableLocations[18]->next = NULL;


	drawRec(enviro, 696, 545, 720, 600, BUILDING);
	drawRec(enviro, 708, 551, 767, 589, BUILDING);
	drawRec(enviro, 752, 566, 774, 616, BUILDING);
	drawRec(enviro, 754, 455, 816, 570, BUILDING);
}

void horizonHall(Environment* enviro){//19
	memcpy (enviro->buildingNames[19], "Horizon Hall", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[19]->x = 819;
	enviro->interactableLocations[19]->y = 501;
	enviro->interactableLocations[19]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[19]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[19]->next->x = 784;
	enviro->interactableLocations[19]->next->y = 429;
	enviro->interactableLocations[19]->next->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[19]->next->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 3
	enviro->interactableLocations[19]->next->next->x = 663;
	enviro->interactableLocations[19]->next->next->y = 417;
	enviro->interactableLocations[19]->next->next->next = NULL;

	drawRec(enviro, 669, 394, 785, 459, BUILDING);
	drawCircle(enviro, 790, 432, 20, BUILDING);
	drawTriangle(enviro, 783, 405, 815, 455, 764, 462, BUILDING);
	drawRec(enviro, 655, 409, 673, 412, SIDEWALK);
	drawRec(enviro, 655, 425, 673, 428, SIDEWALK);
}

void fenwickLibrary(Environment* enviro){//20
	memcpy (enviro->buildingNames[20], "Fenwick Library", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[20]->x = 745;
	enviro->interactableLocations[20]->y = 211;
	enviro->interactableLocations[20]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[20]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[20]->next->x = 738;
	enviro->interactableLocations[20]->next->y = 354;
	enviro->interactableLocations[20]->next->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[20]->next->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 3
	enviro->interactableLocations[20]->next->next->x = 598;
	enviro->interactableLocations[20]->next->next->y = 322;
	enviro->interactableLocations[20]->next->next->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[20]->next->next->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 4
	enviro->interactableLocations[20]->next->next->next->x = 626;
	enviro->interactableLocations[20]->next->next->next->y = 343;
	enviro->interactableLocations[20]->next->next->next->next = NULL;


	drawRec(enviro, 529, 270, 583, 325, BUILDING);
	drawRec(enviro, 579, 280, 618, 316, BUILDING);
	drawRec(enviro, 591, 273, 618, 316, BUILDING);
	drawRec(enviro, 614, 279, 658, 310, BUILDING);
	drawRec(enviro, 627, 274, 658, 310, BUILDING);
	drawRec(enviro, 651, 208, 734, 344, BUILDING);
	drawRec(enviro, 635, 329, 753, 350, BUILDING);
	drawQuad(enviro, 729, 232, 768, 229, 752, 326, 723, 322, BUILDING);
	drawRec(enviro, 640, 223, 657, 232, BUILDING);
}

void theHub(Environment* enviro){//21
	memcpy (enviro->buildingNames[21], "The Hub", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[21]->x = 1000;
	enviro->interactableLocations[21]->y = 187;
	enviro->interactableLocations[21]->next = NULL;


	drawRec(enviro, 1016, 62, 1122, 141, BUILDING);
	drawRec(enviro, 1016, 62, 1074, 157, BUILDING);
	drawRec(enviro, 996, 76, 1030, 137, BUILDING);
	drawRec(enviro, 1104, 137, 1115, 153, BUILDING);
	drawRec(enviro, 1035, 144, 1073, 156, BUILDING);
	drawQuad(enviro, 1010, 130, 990, 155, 1008, 170, 1025, 151, BUILDING);
	drawQuad(enviro, 988, 146, 1008, 170, 977, 201, 956, 178, BUILDING);
	drawQuad(enviro, 956, 178, 982, 206, 995, 198, 968, 169, BUILDING);
}

void southsideDining(Environment* enviro){//22
	memcpy (enviro->buildingNames[22], "South Side Dining", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[22]->x = 868;
	enviro->interactableLocations[22]->y = 183;
	enviro->interactableLocations[22]->next = NULL;

	drawRec(enviro, 861, 99, 882, 115, BUILDING);
	drawRec(enviro, 856, 114, 923, 175, BUILDING);
	drawRec(enviro, 861, 102, 923, 175, BUILDING);
	drawCircle(enviro, 882, 181, 15, BUILDING);
	drawRec(enviro, 882, 174, 906, 201, SIDEWALK);
	drawRec(enviro, 895, 170, 920, 185, BUILDING);
}

void skylineFitnessCenter(Environment* enviro){//23
	memcpy (enviro->buildingNames[23], "Skyline Fitness Center", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[23]->x = 836;
	enviro->interactableLocations[23]->y = 184;
	enviro->interactableLocations[23]->next = NULL;


	drawRec(enviro, 796, 103, 828, 150, BUILDING);
	drawRec(enviro, 796, 140, 870, 166, BUILDING);
	drawRec(enviro, 790, 150, 870, 174, BUILDING);

}

void theCommons(Environment* enviro){//24
	memcpy (enviro->buildingNames[24], "The Commons", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[24]->x = 740;
	enviro->interactableLocations[24]->y = 174;
	enviro->interactableLocations[24]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[24]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[24]->next->x = 708;
	enviro->interactableLocations[24]->next->y = 173;
	enviro->interactableLocations[24]->next->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[24]->next->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 3
	enviro->interactableLocations[24]->next->next->x = 617;
	enviro->interactableLocations[24]->next->next->y = 172;
	enviro->interactableLocations[24]->next->next->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[24]->next->next->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 4
	enviro->interactableLocations[24]->next->next->next->x = 540;
	enviro->interactableLocations[24]->next->next->next->y = 170;
	enviro->interactableLocations[24]->next->next->next->next = NULL;

	drawRec(enviro, 738, 90, 771, 167, BUILDING);
	drawRec(enviro, 749, 163, 771, 173, BUILDING);
	drawRec(enviro, 771, 109, 792, 132, BUILDING);

	drawRec(enviro, 667, 70, 701, 134, BUILDING);
	drawRec(enviro, 678, 113, 713, 163, BUILDING);
	drawRec(enviro, 678, 158, 705, 170, BUILDING);
	drawRec(enviro, 709, 117, 743, 135, BUILDING);

	drawRec(enviro, 545, 72, 578, 132, BUILDING);
	drawRec(enviro, 531, 106, 566, 162, BUILDING);
	drawRec(enviro, 531, 156, 554, 168, BUILDING);
	drawRec(enviro, 570, 113, 608, 132, BUILDING);

	drawRec(enviro, 600, 72, 635, 132, BUILDING);
	drawRec(enviro, 610, 106, 648, 162, BUILDING);
	drawRec(enviro, 624, 162, 648, 168, BUILDING);

	drawRec(enviro, 708, 24, 720, 42, BUILDING);
	drawRec(enviro, 720, 19, 751, 49, BUILDING);
	drawRec(enviro, 748, 25, 761, 67, BUILDING);
	drawRec(enviro, 762, 44, 792, 73, BUILDING);
	drawRec(enviro, 791, 50, 802, 71, BUILDING);
	drawRec(enviro, 827, 25, 840, 48, BUILDING);
	drawRec(enviro, 833, 43, 840, 60, BUILDING);
	drawRec(enviro, 839, 23, 865, 53, BUILDING);
	drawRec(enviro, 869, 22, 879, 47, BUILDING);
	drawRec(enviro, 873, 19, 898, 30, BUILDING);
	drawRec(enviro, 873, 0, 903, 20, BUILDING);
}

void commonwealthHall(Environment* enviro){//25
	memcpy (enviro->buildingNames[25], "Commonwealth Hall", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[25]->x = 518;
	enviro->interactableLocations[25]->y = 78;
	enviro->interactableLocations[25]->next = NULL;

	drawRec(enviro, 481, 79, 503, 127, BUILDING);
	drawRec(enviro, 488, 125, 503, 133, BUILDING);
	drawRec(enviro, 487, 57, 494, 80, BUILDING);
	drawQuad(enviro, 508, 17, 529, 29, 504, 69, 484, 57, BUILDING);
	drawQuad(enviro, 522, 17, 533, 25, 526, 34, 514, 27, BUILDING);
}

void dominionHall(Environment* enviro){//26
	memcpy (enviro->buildingNames[26], "Dominion Hall", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[26]->x = 556;
	enviro->interactableLocations[26]->y = 16;
	enviro->interactableLocations[26]->next = NULL;

	drawQuad(enviro, 563, 27, 609, 5, 616, 27, 570, 46, BUILDING);
	drawQuad(enviro, 560, 34, 568, 31, 570, 35, 562, 39, BUILDING);
	drawQuad(enviro, 628, 0, 675, 9, 674, 31, 626, 26, BUILDING);
	drawQuad(enviro, 668, 8, 682, 10, 680, 22, 667, 20, BUILDING);
	drawRec(enviro, 610, 18, 633, 23, BUILDING);
}

void northernNeck(Environment* enviro){//27
	memcpy (enviro->buildingNames[27], "Northern Neck", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[27]->x = 409;
	enviro->interactableLocations[27]->y = 169;
	enviro->interactableLocations[27]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[27]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[27]->next->x = 350;
	enviro->interactableLocations[27]->next->y = 105;
	enviro->interactableLocations[27]->next->next = NULL;

	drawQuad(enviro, 403, 14, 449, 43, 430, 69, 388, 42, BUILDING);
	drawQuad(enviro, 397, 39, 427, 58, 384, 125, 360, 94, BUILDING);
	drawQuad(enviro, 355, 115, 449, 120, 448, 156, 351, 145, BUILDING);
	drawQuad(enviro, 360, 94, 350, 145, 380, 151, 394, 110, BUILDING);
	drawRec(enviro, 412, 149, 431, 165, BUILDING);
}

void lectureHall(Environment* enviro){//28
	memcpy (enviro->buildingNames[28], "Lecture Hall", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[28]->x = 459;
	enviro->interactableLocations[28]->y = 235;
	enviro->interactableLocations[28]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[28]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[28]->next->x = 460;
	enviro->interactableLocations[28]->next->y = 270;
	enviro->interactableLocations[28]->next->next = NULL;

	drawRec(enviro, 416, 239, 491, 266, BUILDING);
}

void eastBuilding(Environment* enviro){//29
	memcpy (enviro->buildingNames[29], "East Building", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[29]->x = 424;
	enviro->interactableLocations[29]->y = 318;
	enviro->interactableLocations[29]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[29]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[29]->next->x = 402;
	enviro->interactableLocations[29]->next->y = 379;
	enviro->interactableLocations[29]->next->next = NULL;

	drawRec(enviro, 410, 321, 443, 390, BUILDING);
}

void krugHall(Environment* enviro){//30
	memcpy (enviro->buildingNames[30], "Krug Hall", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[30]->x = 507;
	enviro->interactableLocations[30]->y = 382;
	enviro->interactableLocations[30]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[30]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[30]->next->x = 469;
	enviro->interactableLocations[30]->next->y = 474;
	enviro->interactableLocations[30]->next->next = NULL;

	drawRec(enviro, 478, 385, 515, 489, BUILDING);
}

void finleyBuilding(Environment* enviro){//31
	memcpy (enviro->buildingNames[31], "Finley Building", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[31]->x = 353;
	enviro->interactableLocations[31]->y = 415;
	enviro->interactableLocations[31]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[31]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[31]->next->x = 397;
	enviro->interactableLocations[31]->next->y = 414;
	enviro->interactableLocations[31]->next->next = NULL;

	drawRec(enviro, 359, 385, 391, 489, BUILDING);
}

void westBuilding(Environment* enviro){//32
	memcpy (enviro->buildingNames[32], "West Building", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[32]->x = 451;
	enviro->interactableLocations[32]->y = 477;
	enviro->interactableLocations[32]->next = NULL;

	drawRec(enviro, 428, 484, 459, 540, BUILDING);
	drawRec(enviro, 437, 537, 458, 546, BUILDING);
}

void studentUnionBuilding(Environment* enviro){//33
	memcpy (enviro->buildingNames[33], "Student Union Building", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[33]->x = 616;
	enviro->interactableLocations[33]->y = 634;
	enviro->interactableLocations[33]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[33]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[33]->next->x = 600;
	enviro->interactableLocations[33]->next->y = 493;
	enviro->interactableLocations[33]->next->next = NULL;

	drawRec(enviro, 565, 583, 651, 626, BUILDING);
	drawRec(enviro, 594, 624, 615, 632, BUILDING);
	drawRec(enviro, 558, 503, 662, 566, BUILDING);
	drawRec(enviro, 571, 560, 646, 589, BUILDING);
	drawRec(enviro, 613, 486, 634, 513, BUILDING);
	drawRec(enviro, 633, 490, 662, 513, BUILDING);
	drawTriangle(enviro, 563, 615, 581, 626, 558, 631, SIDEWALK);
	drawRec(enviro, 561, 493, 581, 524, BUILDING);
	drawRec(enviro, 576, 495, 596, 525, BUILDING);
}

void aquiaBuilding(Environment* enviro){//34
	memcpy (enviro->buildingNames[34], "Aquia Building", BUILDING_NAME_LENGTH);


	//loc 1
	enviro->interactableLocations[34]->x = 490;
	enviro->interactableLocations[34]->y = 503;
	enviro->interactableLocations[34]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[34]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[34]->next->x = 516;
	enviro->interactableLocations[34]->next->y = 643;
	enviro->interactableLocations[34]->next->next = NULL;

	drawRec(enviro, 476, 522, 513, 615, BUILDING);
	drawRec(enviro, 482, 510, 499, 528, BUILDING);
	drawRec(enviro, 476, 532, 527, 615, BUILDING);
	drawRec(enviro, 494, 612, 527, 626, BUILDING);
	drawRec(enviro, 506, 621, 522, 640, BUILDING);
}

void thompsonHall(Environment* enviro){//35
	memcpy (enviro->buildingNames[35], "Thompson Hall", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[35]->x = 323;
	enviro->interactableLocations[35]->y = 490;
	enviro->interactableLocations[35]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[35]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[35]->next->x = 294;
	enviro->interactableLocations[35]->next->y = 585;
	enviro->interactableLocations[35]->next->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[35]->next->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 3
	enviro->interactableLocations[35]->next->next->x = 334;
	enviro->interactableLocations[35]->next->next->y = 546;
	enviro->interactableLocations[35]->next->next->next = NULL;


	drawRec(enviro, 300, 558, 396, 611, BUILDING);
	drawRec(enviro, 296, 495, 329, 560, BUILDING);
	drawRec(enviro, 309, 488, 318, 500, BUILDING);
	drawRec(enviro, 394, 574, 410, 602, BUILDING);
}

void rappahannockParkingDeck(Environment* enviro){//36
	memcpy (enviro->buildingNames[36], "Rappahannock Parking Deck", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[36]->x = 332;
	enviro->interactableLocations[36]->y = 55;
	enviro->interactableLocations[36]->next = NULL;

	drawTriangle(enviro, 212, 0, 358, 0, 327, 39, BUILDING);
}

void alanAndSallyHall(Environment* enviro){//37
	memcpy (enviro->buildingNames[37], "Alan and Sally Hall", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[37]->x = 146;
	enviro->interactableLocations[37]->y = 139;
	enviro->interactableLocations[37]->next = NULL;

	drawQuad(enviro, 111, 30, 159, 48, 112, 183, 60, 162, BUILDING);
	drawQuad(enviro, 122, 136, 142, 142, 126, 187, 101, 179, BUILDING);
}

void petersonHall(Environment* enviro){//38
	memcpy (enviro->buildingNames[38], "Peterson Hall", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[38]->x = 207;
	enviro->interactableLocations[38]->y = 434;
	enviro->interactableLocations[38]->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[38]->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 2
	enviro->interactableLocations[38]->next->x = 209;
	enviro->interactableLocations[38]->next->y = 356;
	enviro->interactableLocations[38]->next->next = (mapPoint*)malloc(sizeof(mapPoint));
	if(enviro->interactableLocations[38]->next->next == NULL){
		printf("Malloc Failure");
		exit(1);
	} 

	//loc 3
	enviro->interactableLocations[38]->next->next->x = 140;
	enviro->interactableLocations[38]->next->next->y = 383;
	enviro->interactableLocations[38]->next->next->next = NULL;

	drawQuad(enviro, 27, 418, 96, 317, 149, 316, 64, 445, BUILDING);
	drawQuad(enviro, 147, 316, 195, 319, 195, 370, 107, 372, BUILDING);
	drawTriangle(enviro, 138, 308, 150, 317, 130, 318, BUILDING);
	drawRec(enviro, 171, 383, 195, 440, BUILDING);
	drawRec(enviro, 176, 367, 183, 387, BUILDING);
}

void rogers(Environment* enviro){//39
	memcpy (enviro->buildingNames[39], "Rogers", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[39]->x = 53;
	enviro->interactableLocations[39]->y = 552;
	enviro->interactableLocations[39]->next = NULL;

	drawQuad(enviro, 0, 537, 43, 563, 32, 589, 0, 569, BUILDING);

}

void whiteTop(Environment* enviro){//40
	memcpy (enviro->buildingNames[40], "White Top", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[40]->x = 88;
	enviro->interactableLocations[40]->y = 680;
	enviro->interactableLocations[40]->next = NULL;

	drawQuad(enviro, 53, 648, 80, 664, 62, 697, 37, 679, BUILDING);
	drawQuad(enviro, 0, 703, 37, 679, 63, 695, 0, 743, BUILDING);
}

void parkingServices(Environment* enviro){//41
	memcpy (enviro->buildingNames[41], "Parking Services", BUILDING_NAME_LENGTH);

	//loc 1
	enviro->interactableLocations[41]->x = 1285;
	enviro->interactableLocations[41]->y = 303;
	enviro->interactableLocations[41]->next = NULL;

	drawRec(enviro, 1291, 292, 1316, 317, BUILDING);
	drawQuad(enviro, 1308, 292, 1322, 289, 1336, 299, 1312, 315, BUILDING);

}
