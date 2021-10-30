/*
 * Author Cayla DeGuzman
 */

#include "character.h"

void blit_Character(GMU* gmu, SDL_Texture *texture, int x, int y) {
	SDL_Rect dest;

//	dest.x = x;
//	dest.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	dest.x = x;
	dest.y = y;

	SDL_RenderCopy(gmu->game->renderer, texture, NULL, &dest);
}
/*
// loads a texture from .png
SDL_Texture *loadTexture(GMU* gmu, char* filename) {
//	printf("\noccuring\n");

	SDL_Texture *texture;
	texture = IMG_LoadTexture(gmu->game->renderer, filename);
	return texture;
}
*/
void loadFaceTypes(GMU* gmu) {
	
	gmu->character->face_types[0] = NULL;

	gmu->character->face_types[0] = IMG_LoadTexture(gmu->game->renderer, "C_textures/robot_up.png");
	gmu->character->face_types[1] = IMG_LoadTexture(gmu->game->renderer, "C_textures/robot_down.png");
	gmu->character->face_types[2] = IMG_LoadTexture(gmu->game->renderer, "C_textures/robot_left.png");
	gmu->character->face_types[3] = IMG_LoadTexture(gmu->game->renderer, "C_textures/robot_right.png");

	if ( gmu->character->face_types[0] == NULL) {printf("text NULL");}	
}

void initCharacter(GMU* gmu) {
	// charac begins in the middle of the screen
	//	printf("\noccuring\n");
	
	
	//gmu->character->face = 6;
	gmu->character->face = 0;
	gmu->character->x_pos = 64*8;
	gmu->character->y_pos = 64*8;
	
	loadFaceTypes(gmu);
	
/*	
	gmu->character->up = NULL;
	
	gmu->character->up = IMG_LoadTexture(gmu->game->renderer, "E_texture/agrass.png");

	gmu->character->down = loadTexture(gmu,"C_texture/robot_down.png");
	gmu->character->left = loadTexture(gmu,"C_texture/robot_left.png");
	gmu->character->right = loadTexture(gmu,"C_texture/robot_right.png");
	

	if (gmu->character->up == NULL) {printf("\nNULL\n");}
*/	

//	blit_Character(gmu, gmu->character->texture, gmu->character->x_pos, gmu->character->y_pos);
}


