/*
 * Author Cayla DeGuzman
 */

#include "character.h"



void loadFaceTypes(GMU* gmu) {
	

	gmu->character->face_types[0] = IMG_LoadTexture(gmu->game->renderer, "C_textures/robot_up_sm.png");
	gmu->character->face_types[1] = IMG_LoadTexture(gmu->game->renderer, "C_textures/robot_down_sm.png");
	gmu->character->face_types[2] = IMG_LoadTexture(gmu->game->renderer, "C_textures/robot_left_sm.png");
	gmu->character->face_types[3] = IMG_LoadTexture(gmu->game->renderer, "C_textures/robot_right_sm.png");

}
//collision detection
int collisionDetected(GMU* gmu, int direction, int x, int y) {
	switch(direction) {
		case UP:
			if(gmu->enviro->map[y-1][x] >= GRASS) {
				return 1;
			}
			break;
		case DOWN:
			if(gmu->enviro->map[y+2][x] >= GRASS){
				return 1;
			}
			break;
		case LEFT:
			if(gmu->enviro->map[y][x-1] >= GRASS) {
				return 1;
			}
			break;
		case RIGHT:
			if(gmu->enviro->map[y][x+2] >= GRASS) {
				return 1;
			}
			break;
	}

	return 0;
}

char* getStatus(enum Status currStatus){
	char *s;

	if(currStatus == Empty) {
		s = "Looking for Food PickUp orders...";
	 }
	else if(currStatus == Delivering) {
		s = "Delivery in Progress.";
	}
	else if(currStatus == Received) {
		s = "Food is Received!";
	}
	return s;	
}	

void showStatus(GMU* gmu) {
	char *txt;
	txt = getStatus(gmu->character->status);
	
	SDL_Rect stat;
	stat.w = 84*4;
	stat.h = 8*4;
	stat.x = CENTER - stat.w/2;
	stat.y = 500;
	
	//fill
	SDL_SetRenderDrawBlendMode(gmu->game->renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(gmu->game->renderer, 236, 236, 236, 150);
	SDL_RenderFillRect(gmu->game->renderer, &stat);
	//border
	SDL_SetRenderDrawBlendMode(gmu->game->renderer, SDL_BLENDMODE_NONE);
	SDL_SetRenderDrawColor(gmu->game->renderer, 0, 0, 0, 150);
	SDL_RenderDrawRect(gmu->game->renderer, &stat);
	//text
	SDL_Color blk = {0,0,0,255};
	SDL_Surface *wrd_surface = TTF_RenderUTF8_Blended(gmu->character->c_Font, txt, blk);
       	SDL_Texture *wrd_texture = SDL_CreateTextureFromSurface(gmu->game->renderer, wrd_surface);
	SDL_FreeSurface(wrd_surface);

	//centering text
	stat.x = CENTER - (strlen(txt)/2)*22;

	SDL_QueryTexture(wrd_texture, NULL, NULL, &stat.w, &stat.h);
	SDL_RenderCopy(gmu->game->renderer, wrd_texture, NULL, &stat);	
}

void blit_Character(GMU* gmu, SDL_Texture *texture, int x, int y) {

	SDL_Rect dest;

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h); 
	dest.x = x;
	dest.y = y;

	SDL_RenderCopy(gmu->game->renderer, texture, NULL, &dest);
	showStatus(gmu);
}

void initCharacter(GMU* gmu) {
	gmu->character->face = 0;
	gmu->character->x_pos = 64*8;
	gmu->character->y_pos = 64*8;
	gmu->character->x_map_pos = START_COL; 
	gmu->character->y_map_pos = START_ROW;

	gmu->character->status = Empty;		
	loadFaceTypes(gmu);

}


