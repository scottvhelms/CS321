/*Jed Alcantara
 *G00846927
 *interactables.h
 */

#include "libraries.h"
#include "environment.h"
/*Determines action
 * 1, 2, 3, ... n
 * */
enum actions {
	pickup,
	dropoff,
	student
};

/*The purpose of this class is to
 * define the interactable 
 * Movement behaviors
 * Such as a student walking to class
 */
typedef struct {
} Movement;

/*The purpose of this class is to
 * define the interactable 
 * Action behaviors
 */
typedef struct {
	enum actions typeOfAction;
} Action;


/*The pupose of this class is to
 * define an interactable (npc)
 */
typedef struct {
	int positionX;
	int positionY;
	Action action;
	Movement movement;
} Interactable;

/*The purpose of this class is to
 * define an array of interactables
 * */
typedef struct {
	Interactable *interactable;
} Interactables;

/*Interactable Methods*/
void initInteractable(Interactable *interactable, int x, int y);
void initInteractables(GMU *gmu);
void blitInteractables(GMU *gmu, SDL_Texture *texture, int x, int y);
void move(Interactable *interactable, int newPX, int newPY);
void act(Interactable *interactable);
