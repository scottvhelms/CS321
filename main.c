/*** INCLUDES ***/

#include <stdlib.h>
#include <SDL2/SDL.h>		// init and shutdown
#include <SDL2/SDL_image.h>	// rendering and graphinc
#include <SDL2/SDL_timer.h>	// delay and timing functions

//libraries built by team 4
#include "environment.h"
#include "interactables.h"
#include "character.h"




int main(){



	// All the following code currently does is open a window and allow for the "x" buttone to close it.

	//opens window
	SDL_Window* win = SDL_CreateWindow("Starship GMU", 
					SDL_WINDOWPOS_CENTERED, 
					SDL_WINDOWPOS_CENTERED, 
					1000, 
					1000, 
					0);
	//close boolean
	int close = 0;

	//loop
	while(!close){
		SDL_Event event;
		//reads events (such as close button being clicked)
		while(SDL_PollEvent(&event)){
			switch(event.type){
				//if close clicked, set clsoe boolean to true
				case SDL_QUIT:
					close = 1;
					break;

			}
		}
	
	}

	// close window
	SDL_DestroyWindow(win);
	//quit program
	SDL_Quit();


	return 0;

}
