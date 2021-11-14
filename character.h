// Author Cayla DeGuzman

#include "libraries.h"
#include "environment.h"

//declarations
void loadFaceTypes(GMU* gmu);
int collisionDetected(GMU* gmu, int direction, int x, int y);
char* getStatus(enum Status currStatus);
void showStatus(GMU* gmu);
void blit_Character(GMU* gmu, SDL_Texture *texture, int x, int y);
void initCharacter(GMU* gmu);



