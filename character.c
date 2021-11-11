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
	

	gmu->character->face_types[0] = IMG_LoadTexture(gmu->game->renderer, "C_textures/robot_up_sm.png");
	gmu->character->face_types[1] = IMG_LoadTexture(gmu->game->renderer, "C_textures/robot_down_sm.png");
	gmu->character->face_types[2] = IMG_LoadTexture(gmu->game->renderer, "C_textures/robot_left_sm.png");
	gmu->character->face_types[3] = IMG_LoadTexture(gmu->game->renderer, "C_textures/robot_right_sm.png");

}
//collision detection
int isNotBlocked(GMU* gmu, int x, int y) {
	if(gmu->enviro->map[x][y] >= 30) {
		return 0;
	}

	return 1;
}
void initCharacter(GMU* gmu) {
	gmu->character->face = 0;
	gmu->character->x_pos = 64*8;
	gmu->character->y_pos = 64*8;
	gmu->character->x_map_pos = START_COL; 
	gmu->character->y_map_pos = START_ROW;

	
	loadFaceTypes(gmu);

}


