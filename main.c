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
	gmu->enviro = (Environment*)malloc(sizeof(Environment));
	initializeEnvironment(gmu->enviro);
	//TODO add function for initializing character
	//TODO add function for initializing interactables

	//initialize render offeset TODO currently 0(top lefthand corner), find resonable offset.
	gmu->renderOffset.x = 0;
	gmu->renderOffset.y = 0;	

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
	
	
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	//init renderer
	game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);

	//window error processing
	if(!game->renderer){
		printf("Renderer Failed to initialize");
		exit(1);
	}

}

//close, destroys and frees as needed
void endGame(GMU* gmu){
	// close window
	SDL_DestroyWindow(gmu->game->window);
	// close renderer
	SDL_DestroyRenderer(gmu->game->renderer);
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
		}
	}
}

void setUpDisplay(GMU* gmu){
	//sets to gray to represent sidewalk
	SDL_SetRenderDrawColor(gmu->game->renderer, 210, 215, 211, 1);
	SDL_RenderClear(gmu->game->renderer);
}

void display(GMU* gmu){
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

		getInput(gmu);		

		display(gmu);	

		SDL_Delay(20);
	}
	
	

	endGame(gmu);
	return 0;

}
