//Author Scott Helms
#ifndef Enviro
#define Enviro

/*** Include ***/
#include "libraries.h"
#include "structs.h"


/*** Declarations ***/

//init
void initializeEnvironment(GMU* gmu);
void initializeGrass(Environment* enviro);
void initializeBuildings(Environment* enviro);
void initializeStreets(Environment* enviro);
void initializeLocations(Environment* enviro);
void initializeNames(Environment* enviro);


//load and display
void loadEnviroTypes(GMU* gmu);
void loadBackground(Environment* enviro);
//void loadInterLocations(Environment* enviro);
void displayEnvironment(GMU* gmu);
void show(GMU* gmu, int type, int row, int col);
void displayBuildingName(GMU* gmu);
void showName(GMU* gmu, char* text);



//developer tools
void drawRec(Environment* enviro, int x1, int x2, int y1, int y2, int type);
void drawCircle(Environment* enviro, int center_x, int center_y, int radius, int type);
void drawTriangle(Environment* envior, double x1, double y1, double x2, double y2, double x3, double y3, int type); 
void drawQuad(Environment* envior, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, int type); 
int withinLine(double x1, double y1, double x2, double y2, double x3, double y3, double point_x, double point_y); 
int findMin(int a, int b, int c, int d);
int findMax(int a, int b, int c, int d);

//buildings
void johnsonCenter(Environment* enviro);//0
void davidKingHall(Environment* enviro);//1
void planetaryHall(Environment* enviro);//2
void exploratoryHall(Environment* enviro);//3
void enterpriseHall(Environment* enviro);//4
void researchHall(Environment* enviro);//5
void shenandoahParkingDeck(Environment* enviro);//6
void nguyenEngineeringBuilding(Environment* enviro);//7
void artAndDesignBuilding(Environment* enviro);//8
void libertySquareHousing(Environment* enviro);//9
void aquaticAndFitnessCenter(Environment* enviro);//10
void innovationHall(Environment* enviro);//11
void musicAndTheaterBuilding(Environment* enviro);//12
void collegeHall(Environment* enviro);//13
void buchananHall(Environment* enviro);//14
void performingArtsBuilding(Environment* enviro);//15
void concertHall(Environment* enviro);//16
void masonPondParkingDeck(Environment* enviro);//17
void harrisTheater(Environment* enviro);//18
void horizonHall(Environment* enviro);//19
void fenwickLibrary(Environment* enviro);//20
void theHub(Environment* enviro);//21
void southsideDining(Environment* enviro);//22
void skylineFitnessCenter(Environment* enviro);//23
void theCommons(Environment* enviro);//24
void commonwealthHall(Environment* enviro);//25
void dominionHall(Environment* enviro);//26
void northernNeck(Environment* enviro);//27
void lectureHall(Environment* enviro);//28
void eastBuilding(Environment* enviro);//29
void krugHall(Environment* enviro);//30
void finleyBuilding(Environment* enviro);//31
void westBuilding(Environment* enviro);//32
void studentUnionBuilding(Environment* enviro);//33
void aquiaBuilding(Environment* enviro);//34
void thompsonHall(Environment* enviro);//35
void rappahannockParkingDeck(Environment* enviro);//36
void alanAndSallyHall(Environment* enviro);//37
void petersonHall(Environment* enviro);//38
void rogers(Environment* enviro);//39
void whiteTop(Environment* enviro);//40
void parkingServices(Environment* enviro);//41

#endif
