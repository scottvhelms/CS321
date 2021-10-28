/*
 * Author Cayla DeGuzman
 */

#include "character.h"

void blit_Character(GMU* gmu, SDL_Texture *texture, int x, int y) {
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	
	SDL_RenderCopy(gmu->game->renderer, texture, NULL, &dest);
}

// loads a texture from .png
SDL_Texture *loadTexture(GMU* gmu, char* fileanme) {
	SDL_Texture *texture;
	texture = IMG_LoadTexture(gmu->game->renderer, filename);
	return texture;

void initCharacter(GMU* gmu) {
	// charac begins in the middle of the screen
	gmu->character.x_pos = SCREEN_ROW / 2;
	gmu->character.y_pos = SCREEN_COL / 2;
	gmu->character.texture = loadTexture("C_texture/robot.png");
	blit_Character(GMU* gmu, gmu->character.texture, gmu->character.x_pos, gmu->character.y_pos);
}


