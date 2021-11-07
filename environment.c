#include "environment.h"

/***INIT and LOAD***/
void initializeEnvironment(GMU *gmu){
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
	mapPoint* point;
	for (row = 0; row<NUMBER_OF_BUILDINGS; ++row){
		point = (mapPoint*)malloc(sizeof(mapPoint));
		point->x = 0;
		point->y = 0;
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


void johnsonCenter(Environment* enviro){ //0
	memcpy (enviro->buildingNames[0], "Johnson Center", BUILDING_NAME_LENGTH);


	drawRec(enviro, 875, 458, 1090, 562, BUILDING);
	drawTriangle(enviro, 876, 457, 904, 455, 874, 477, SIDEWALK);
	drawTriangle(enviro, 875, 540, 898, 563, 875, 561, SIDEWALK);
	drawCircle(enviro, 884, 464, 11, BUILDING);
	drawCircle(enviro, 1007, 457, 8, BUILDING);
	drawCircle(enviro, 1089, 511, 8, BUILDING);
	drawCircle(enviro, 1006, 564, 8, BUILDING);
	drawCircle(enviro, 883, 554, 9, BUILDING);
}

void davidKingHall(Environment* enviro){
	drawRec(enviro, 877, 316, 986, 388, BUILDING);
}

void planetaryHall(Environment* enviro){
	drawRec(enviro, 1034, 323, 1135, 376, BUILDING);
	drawRec(enviro, 1103, 323, 1136, 380, BUILDING);
	drawRec(enviro, 1053, 269, 1119, 328, BUILDING);
	drawRec(enviro, 1028, 269, 1058, 291, BUILDING);
	drawCircle(enviro, 1028, 280, 11, BUILDING);
}

void exploratoryHall(Environment* enviro){
	drawRec(enviro, 1118, 248, 1214, 306, BUILDING);
	drawRec(enviro, 1113, 255, 1223, 299, BUILDING);
}

void enterpriseHall(Environment* enviro){
	drawRec(enviro, 1203, 347, 1283, 387, BUILDING);
	drawRec(enviro, 1205, 409, 1246, 467, BUILDING);
	drawCircle(enviro, 1226, 455, 16, BUILDING);
}

void researchHall(Environment* enviro){
	drawQuad(enviro, 1316, 352, 1416, 352, 1416, 386, 1316, 392, BUILDING);
	drawQuad(enviro, 1416, 352, 1470, 352, 1470, 394, 1416, 386, BUILDING);
	drawCircle(enviro, 1418, 400, 7, BUILDING); 
}

void shenandoahParkingDeck(Environment* enviro){
	drawQuad(enviro, 1242, 201, 1400, 318, 1456, 244, 1304, 126, BUILDING);
}

void nguyenEngineeringBuilding(Environment* enviro){
	drawQuad(enviro, 1493, 519, 1515, 402, 1567, 379, 1540, 529, BUILDING);
	drawQuad(enviro, 1577, 373, 1639, 424, 1603, 442, 1539, 392, BUILDING);
	drawQuad(enviro, 1579, 420, 1549, 455, 1533, 432, 1560, 398, BUILDING);
}

void artAndDesignBuilding(Environment* enviro){
	drawQuad(enviro, 1344, 517, 1433, 518, 1428, 584, 1350, 582, BUILDING);
	drawRec(enviro, 1329, 531, 1352, 568, BUILDING);
	drawRec(enviro, 1427, 526, 1444, 569, BUILDING);
	drawQuad(enviro, 1314, 524, 1335, 528, 1336, 571, 1314, 571, BUILDING);
	drawQuad(enviro, 1441, 522, 1454, 525, 1445, 572, 1431, 569, BUILDING);
	drawRec(enviro, 1323, 558, 1337, 578, BUILDING);
}

void libertySquareHousing(Environment* enviro){
	drawQuad(enviro, 1536, 100, 1552, 71, 1616, 153, 1593, 171, BUILDING);
	drawQuad(enviro, 1544, 61, 1612, 9, 1632, 32, 1561, 84, BUILDING);
	drawQuad(enviro, 1630, 15, 1641, 28, 1627, 36, 1620, 20, BUILDING);
	drawQuad(enviro, 1648, 15, 1711, 93, 1687, 111, 1627, 35, BUILDING);
 	drawQuad(enviro, 1691, 116, 1711, 103, 1743, 181, 1713, 188, BUILDING);
	drawQuad(enviro, 1642, 198, 1702, 178, 1715, 205, 1649, 227, BUILDING);
	drawQuad(enviro, 1715, 183, 1729, 183, 1731, 195, 1718, 201, BUILDING);
}

void aquaticAndFitnessCenter(Environment* enviro){
	drawQuad(enviro, 1724, 364, 1805, 353, 1813, 416, 1730, 426, BUILDING);
	drawQuad(enviro, 1729, 422, 1838, 410, 1847, 469, 1736, 483, BUILDING);
	drawQuad(enviro, 1717, 484, 1837, 468, 1833, 474, 1721, 507, BUILDING);
	drawQuad(enviro, 1707, 371, 1700, 349, 1749, 326, 1765, 361, BUILDING);
	drawQuad(enviro, 1800, 364, 1825, 362, 1835, 409, 1808, 418, BUILDING);
}
void innovationHall(Environment* enviro){
	drawRec(enviro, 1203, 572, 1239, 684, BUILDING);
	drawRec(enviro, 1236, 639, 1280, 685, BUILDING);
	drawRec(enviro, 1234, 681, 1271, 690, BUILDING);
	drawRec(enviro, 1203, 562, 1218, 572, BUILDING);
}

void musicAndTheaterBuilding(Environment* enviro){
	drawRec(enviro, 1038, 615, 1083, 668, BUILDING);
	drawRec(enviro, 1038, 615, 1097, 654, BUILDING);
	drawRec(enviro, 1011, 620, 1047, 660, BUILDING);
	drawRec(enviro, 1093, 638, 1112, 648, BUILDING);
}

void collegeHall(Environment* enviro){
	drawRec(enviro, 1110, 629, 1132, 698, BUILDING);
	drawRec(enviro, 1128, 643, 1137, 654, BUILDING);
	drawRec(enviro, 1117, 693, 1126, 709, BUILDING);
}

void buchananHall(Environment* enviro){
	drawRec(enviro, 1068, 710, 1138, 783, BUILDING);
	drawRec(enviro, 1110, 706, 1138, 721, BUILDING);
}

void performingArtsBuilding(Environment* enviro){
	drawRec(enviro, 876, 647, 985, 729, BUILDING);
	drawRec(enviro, 878, 613, 961, 651, BUILDING);
	drawQuad(enviro, 872, 601, 913, 612, 909, 641, 868, 636, BUILDING);
	drawQuad(enviro, 898, 600, 924, 611, 922, 637, 893, 635, BUILDING);
	drawQuad(enviro, 921, 602, 947, 610, 941, 642, 915, 638, BUILDING);
	drawQuad(enviro, 947, 603, 969, 610, 965, 640, 940, 639, BUILDING);
}

void concertHall(Environment* enviro){
	drawRec(enviro, 890, 748, 970, 838, BUILDING);
	drawRec(enviro, 881, 799, 970, 838, BUILDING);
	drawRec(enviro, 877, 734, 970, 758, BUILDING);
}

void masonPondParkingDeck(Environment* enviro){
	drawRec(enviro, 717, 685, 808, 832, BUILDING);
	drawRec(enviro, 700, 686, 719, 712, BUILDING);
	drawRec(enviro, 709, 823, 723, 837, SIDEWALK);
	drawRec(enviro, 800, 824, 814, 838, SIDEWALK);
	drawRec(enviro, 800, 682, 815, 693, SIDEWALK);
	drawRec(enviro, 714, 682, 721, 694, SIDEWALK);
}

void harrisTheater(Environment* enviro){
	drawRec(enviro, 696, 545, 720, 600, BUILDING);
	drawRec(enviro, 708, 551, 767, 589, BUILDING);
	drawRec(enviro, 752, 566, 774, 616, BUILDING);
	drawRec(enviro, 754, 455, 816, 570, BUILDING);
}

void horizonHall(Environment* enviro){
	drawRec(enviro, 669, 394, 785, 459, BUILDING);
	drawCircle(enviro, 790, 432, 20, BUILDING);
	drawTriangle(enviro, 783, 405, 815, 455, 764, 462, BUILDING);
	drawRec(enviro, 655, 409, 673, 412, SIDEWALK);
	drawRec(enviro, 655, 425, 673, 428, SIDEWALK);
}

void fenwickLibrary(Environment* enviro){
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

void theHub(Environment* enviro){
	drawRec(enviro, 1016, 62, 1122, 141, BUILDING);
	drawRec(enviro, 1016, 62, 1074, 157, BUILDING);
	drawRec(enviro, 996, 76, 1030, 137, BUILDING);
	drawRec(enviro, 1104, 137, 1115, 153, BUILDING);
	drawRec(enviro, 1035, 144, 1073, 156, BUILDING);
	drawQuad(enviro, 1010, 130, 990, 155, 1008, 170, 1025, 151, BUILDING);
	drawQuad(enviro, 988, 146, 1008, 170, 977, 201, 956, 178, BUILDING);
	drawQuad(enviro, 956, 178, 982, 206, 995, 198, 968, 169, BUILDING);
}

void southsideDining(Environment* enviro){
	drawRec(enviro, 861, 99, 882, 115, BUILDING);
	drawRec(enviro, 856, 114, 923, 175, BUILDING);
	drawRec(enviro, 861, 102, 923, 175, BUILDING);
	drawCircle(enviro, 882, 181, 15, BUILDING);
	drawRec(enviro, 882, 174, 906, 201, SIDEWALK);
	drawRec(enviro, 895, 170, 920, 185, BUILDING);
}

void skylineFitnessCenter(Environment* enviro){
	drawRec(enviro, 796, 103, 828, 150, BUILDING);
	drawRec(enviro, 796, 140, 870, 166, BUILDING);
	drawRec(enviro, 790, 150, 870, 174, BUILDING);

}

void theCommons(Environment* enviro){
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

void commonwealthHall(Environment* enviro){
	drawRec(enviro, 481, 79, 503, 127, BUILDING);
	drawRec(enviro, 488, 125, 503, 133, BUILDING);
	drawRec(enviro, 487, 57, 494, 80, BUILDING);
	drawQuad(enviro, 508, 17, 529, 29, 504, 69, 484, 57, BUILDING);
	drawQuad(enviro, 522, 17, 533, 25, 526, 34, 514, 27, BUILDING);
}

void dominionHall(Environment* enviro){
	drawQuad(enviro, 563, 27, 609, 5, 616, 27, 570, 46, BUILDING);
	drawQuad(enviro, 560, 34, 568, 31, 570, 35, 562, 39, BUILDING);
	drawQuad(enviro, 628, 0, 675, 9, 674, 31, 626, 26, BUILDING);
	drawQuad(enviro, 668, 8, 682, 10, 680, 22, 667, 20, BUILDING);
	drawRec(enviro, 610, 18, 633, 23, BUILDING);
}

void northernNeck(Environment* enviro){
	drawQuad(enviro, 403, 14, 449, 43, 430, 69, 388, 42, BUILDING);
	drawQuad(enviro, 397, 39, 427, 58, 384, 125, 360, 94, BUILDING);
	drawQuad(enviro, 355, 115, 449, 120, 448, 156, 351, 145, BUILDING);
	drawQuad(enviro, 360, 94, 350, 145, 380, 151, 394, 110, BUILDING);
	drawRec(enviro, 412, 149, 431, 165, BUILDING);
}

void lectureHall(Environment* enviro){
	drawRec(enviro, 416, 239, 491, 266, BUILDING);
}

void eastBuilding(Environment* enviro){
	drawRec(enviro, 410, 321, 443, 390, BUILDING);
}

void krugHall(Environment* enviro){
	drawRec(enviro, 478, 385, 515, 489, BUILDING);
}

void finleyBuilding(Environment* enviro){
	drawRec(enviro, 359, 385, 391, 489, BUILDING);
}

void westBuilding(Environment* enviro){
	drawRec(enviro, 428, 484, 459, 540, BUILDING);
	drawRec(enviro, 437, 537, 458, 546, BUILDING);
}

void studentUnionBuilding(Environment* enviro){
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

void aquiaBuilding(Environment* enviro){
	drawRec(enviro, 476, 522, 513, 615, BUILDING);
	drawRec(enviro, 482, 510, 499, 528, BUILDING);
	drawRec(enviro, 476, 532, 527, 615, BUILDING);
	drawRec(enviro, 494, 612, 527, 626, BUILDING);
	drawRec(enviro, 506, 621, 522, 640, BUILDING);
}

void thompsonHall(Environment* enviro){
	drawRec(enviro, 300, 558, 396, 611, BUILDING);
	drawRec(enviro, 296, 495, 329, 560, BUILDING);
	drawRec(enviro, 309, 488, 318, 500, BUILDING);
	drawRec(enviro, 394, 574, 410, 602, BUILDING);
}

void rappahannockParkingDeck(Environment* enviro){
	drawTriangle(enviro, 212, 0, 358, 0, 327, 39, BUILDING);
}

void alanAndSallyHall(Environment* enviro){
	drawQuad(enviro, 111, 30, 159, 48, 112, 183, 60, 162, BUILDING);
	drawQuad(enviro, 122, 136, 142, 142, 126, 187, 101, 179, BUILDING);
}

void petersonHall(Environment* enviro){
	drawQuad(enviro, 27, 418, 96, 317, 149, 316, 64, 445, BUILDING);
	drawQuad(enviro, 147, 316, 195, 319, 195, 370, 107, 372, BUILDING);
	drawTriangle(enviro, 138, 308, 150, 317, 130, 318, BUILDING);
	drawRec(enviro, 171, 383, 195, 440, BUILDING);
	drawRec(enviro, 176, 367, 183, 387, BUILDING);
}

void rogers(Environment* enviro){
	drawQuad(enviro, 0, 537, 43, 563, 32, 589, 0, 569, BUILDING);

}

void whiteTop(Environment* enviro){
	drawQuad(enviro, 53, 648, 80, 664, 62, 697, 37, 679, BUILDING);
	drawQuad(enviro, 0, 703, 37, 679, 63, 695, 0, 743, BUILDING);

}

