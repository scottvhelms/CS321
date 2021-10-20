/*Jed Alcantara
 *G00846927
 *interactables.h
 */

enum interactables {
	pickup,
	dropoff
};

/*The pupose of this class is to
 * define an interactable (npc)
 */
typedef struct {
	int positionX;
	int positionY;
	Event event;
} Interactable;

/*The purpose of this class is to 
 * define the interactable behavior
 * based on the enum types
 */
typedef struct {
	enum interactables event;
} Event;











