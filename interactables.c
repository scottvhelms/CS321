/*Jed Alcantara
 *G00846927
 *interactables
 */

#include "interactables.h"
#include <time.h>
//N Determines how many interactables
#define N 2
#define SEED (6927 + time(NULL))


/*Interactable Methods*/
/*void initInteractable(Interactable *interactable, int x, int y) {
	interactable.positionX = x;
	interactable.positionY = y;
	interactable.action = malloc(sizeof(Action));
	interactable.movement = malloc(sizeof(Movement));
}
*/

/*void initInteractables(GMU *gmu) {
	int i, j, positionX, positionY;
	srand(SEED);
	gmu->Interactables = malloc(N * sizeof(Interactable));
	for (i = 0; i < N; i++) {
		gmu->Interactables[i] = malloc(sizeof(Interactable));
		/* access ENVIRIO for VALID (x,y) 
		 * eg Johnson Center (1004, 448)
		 */
/*		j = (rand() % 41);
		positionX = gmu->enviro->interactableLocations[j].x;
		positionY = gmu->enviro->interactableLocations[j].y;
		// TODO Action

		Action action = {i;}
		initInteractable(gmu->Interactables[i], positionX, positionY, action);
	}
}

void blitInteractables(GMU *gmu, SDL_Texture *texture, int x, int y) {
	
}

void move(Interactable *interactable, int newPX, int newPY) {

}

void act(Interactable *interactable) {

}
*/
