/*
 * Author Cayla DeGuzman
 */

#include "character.h"

void blit_Character(GMU* gmu, SDL_Texture *texture, int x, int y) {
	SDL_Rect dest;

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h); 
	dest.x = x;
	dest.y = y;

	SDL_RenderCopy(gmu->game->renderer, texture, NULL, &dest);
}

void loadFaceTypes(GMU* gmu) {
	

	gmu->character->face_types[0] = IMG_LoadTexture(gmu->game->renderer, "C_textures/robot_up.png");
	gmu->character->face_types[1] = IMG_LoadTexture(gmu->game->renderer, "C_textures/robot_down.png");
	gmu->character->face_types[2] = IMG_LoadTexture(gmu->game->renderer, "C_textures/robot_left.png");
	gmu->character->face_types[3] = IMG_LoadTexture(gmu->game->renderer, "C_textures/robot_right.png");

}

void initCharacter(GMU* gmu) {
	gmu->character->face = 0;
	gmu->character->x_pos = 64*8;
	gmu->character->y_pos = 64*8;
	
	loadFaceTypes(gmu);

}


