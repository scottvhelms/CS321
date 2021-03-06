
#include "main.h"


//initializes the game elements
void initializeGMU(GMU* gmu){
	//initializes the game window and renderer
	gmu->game = NULL;
	gmu->game = (Game*)malloc(sizeof(Game));
	if(gmu->game == NULL){
		printf("gmu->game  Failed to initialize");
		exit(1);
	}
	initializeSDL(gmu->game);
	


	//initialize environment, character, interactables
	gmu->enviro = NULL;
	gmu->enviro = (Environment*)malloc(sizeof(Environment)); //TODO Malloc error checking
	initializeEnvironment(gmu);

	gmu->character = NULL;
	gmu->character = (Character*)malloc(sizeof(Character));
	initCharacter(gmu);
/*
	gmu->interactables = NULL;
	gmu->interactables = (Interactables*)malloc(sizeof(Interactables));
	initInteractables(gmu);
*/	
	gmu->renderOffset.x = START_COL - REND_COL/2;
	gmu->renderOffset.y = START_ROW - REND_COL/2;	

}

// initializes the game engines settings
void initializeSDL(Game* game){
	//video init and error processing
	if(SDL_Init(SDL_INIT_VIDEO) < 0 ){
		printf("SDL Failed to initialize");
		exit(1);
	}


	//opens window, TODO decide on window name... working title "Starship GMU"
	game->window = SDL_CreateWindow("Starship GMU", 
					SDL_WINDOWPOS_UNDEFINED, 
					SDL_WINDOWPOS_UNDEFINED, 
					SCREEN_COL, 
					SCREEN_ROW, 
					0);
	//window error processing
	if(game->window==NULL){
		printf("Window Failed to initialize");
		exit(1);
	}
	
	//sets linear rendering default
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	//init renderer
	game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);

	//window error processing
	if(!game->renderer){
		printf("Renderer Failed to initialize");
		exit(1);
	}

	//init images to use png and jpg
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	if(TTF_Init() < 0){
		printf("TTF Failed to initialize");
		exit(1);
	}
}

//close, destroys and frees as needed
void endGame(GMU* gmu){
	// close window
	SDL_DestroyWindow(gmu->game->window);
	// close renderer
	SDL_DestroyRenderer(gmu->game->renderer);
	// close TTF
	TTF_Quit();
	//quit program
	SDL_Quit();


	//free and Null GMU
	free(gmu);
	gmu = NULL;
}

// All the following code does is allow for the "x" buttone to close it. TODO add input for player
void getInput(GMU* gmu){
	SDL_Event event;
	//reads events (such as close button being clicked)
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				endGame(gmu);
				exit(0);
				break;
			case SDL_KEYDOWN://:
				switch(event.key.keysym.sym){
					
					case SDLK_UP:
						if(gmu->renderOffset.y != 0){
							if(!collisionDetected(gmu, UP, gmu->character->x_map_pos, gmu->character->y_map_pos)){
								gmu->renderOffset.y = gmu->renderOffset.y - 1 ;	
								gmu->character->y_map_pos -= 1;
							}
						}
		
						gmu->character->face = 0;

						break;
					case SDLK_DOWN:
						if(gmu->renderOffset.y != MAP_ROW-1){
							if(!collisionDetected(gmu, DOWN, gmu->character->x_map_pos, gmu->character->y_map_pos)){
								gmu->renderOffset.y = gmu->renderOffset.y + 1 ;
								gmu->character->y_map_pos += 1;
							}
						}

		
						gmu->character->face = 1;

						break;
					case SDLK_LEFT:
						if(gmu->renderOffset.x != 0){
							if(!collisionDetected(gmu, LEFT, gmu->character->x_map_pos, gmu->character->y_map_pos)){
								gmu->renderOffset.x = gmu->renderOffset.x - 1 ;	
								gmu->character->x_map_pos -= 1;
							}
						}
										
						gmu->character->face = 2;

						break;
					case SDLK_RIGHT:
						if(gmu->renderOffset.x != MAP_COL-1){
							if(!collisionDetected(gmu, RIGHT, gmu->character->x_map_pos, gmu->character->y_map_pos)){
								gmu->renderOffset.x = gmu->renderOffset.x + 1 ;	
								gmu->character->x_map_pos += 1;
							}
						}

						gmu->character->face = 3;
						break;
					//case SDLK_SPACE:
					
				}

		
						
				//gmu->renderOffset.x = 0;
				break;
		}
	}
}

void setUpDisplay(GMU* gmu){
	//sets to gray to represent sidewalk
	SDL_SetRenderDrawColor(gmu->game->renderer, 210, 215, 211, 1);
	SDL_RenderClear(gmu->game->renderer);
}

void display(GMU* gmu){

	displayEnvironment(gmu);


	// char stays in the center while face changes with input
	blit_Character(	gmu, 
			gmu->character->face_types[gmu->character->face],
			CENTER,
			CENTER);

	SDL_RenderPresent(gmu->game->renderer);

}

//binary
int main(){
	//allocate and error processing
	GMU* gmu = (GMU*)malloc(sizeof(GMU));
	if(gmu == NULL){
		printf("\nMalloc GMU failure.\n");
	}

	//initializes the game
	initializeGMU(gmu);






	//game loop
	while(1){

		setUpDisplay(gmu);

		display(gmu);	

		getInput(gmu);		

		SDL_Delay(20);
	}
	
	

	endGame(gmu);
	return 0;

}
