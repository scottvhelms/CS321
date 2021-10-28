/*Jed Alcantara
 *G00846927
 *interactables.h
 */

enum interactables {
	pickup = 1,
	dropoff = 2
};

/*The purpose of this class is to
 * define the interactable 
 * Movement behaviors
 */
typedef struct {
	//Map map;
} Movement;

/*The purpose of this class is to
 * define the interactable 
 * Action behaviors
 */
typedef struct {
	enum interactables typeOfAction;
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

/*Interactable Methods*/
void move(Interactable interactable, int newPX, int newPY);
void act(Interactable interactable);
