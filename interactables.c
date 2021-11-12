/*Jed Alcantara
 *G00846927
 *interactables
 */

#define N 2

/*Interactable Methods*/
/*
void initInteractable(Interactable *interactable) {
	//TODO Define starting positions
	interactable.positionX = 0;
	interactable.positionY = 0;
	interactable.action = malloc(sizeof(Action));
	interactable.movement = malloc(sizeof(Movement));
}

void initInteractables(GMU *gmu) {
	int i;
	gmu->Interactables = malloc(N * sizeof(Interactable));
	for (i = 0; i < N; i++) {
		gmu->Interactables[i] = malloc(sizeof(Interactable));
		initInteractable(gmu->Interactables[i]);
	}
}

void blitInteractables(GMU *gmu, SDL_Texture *texture, int x, int y) {

}

void move(Interactable *interactable, int newPX, int newPY) {

}

void act(Interactable *interactable) {

}
*/
