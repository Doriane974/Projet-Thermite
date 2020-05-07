#include "coord.hpp"

void testEgalCoord(){
	Coord c1 = creeCoord(2,1);
	Coord c2 = creeCoord(3,1);
	Coord c3 = creeCoord(2,1);
	ASSERT(!egalCoord(c1,c2));
	ASSERT(egalCoord(c1,c3));
}




void testdirGaucheetDroite(){
/*(a) si l’on tourne à gauche puis à droite, on doit 
être revenu dans la direction initiale ;
(b) si l’on tourne 8 fois à gauche, on doit 
être revenu dans la direction initiale ;
(c) si l’on tourne 8 fois à droite, on doit 
être revenu dans la direction initiale ;
*/	
	//(a)
	Direction dir_a = Direction::N;
	tourneGaucheDir(dir_a);
	tourneDroiteDir(dir_a);
	ASSERT(dir_a == Direction::N);
	//(b)et(c)
	Direction dir_b = Direction::S;
	Direction dir_c = Direction::S;
	Direction dir_b_2 = Direction::S;
	Direction dir_c_2 = Direction::S;
	for(int i=0; i<8; i++){
		tourneDroiteDir(dir_b_2);
		tourneGaucheDir(dir_c_2);
		
	}
	//CEs deux test fail mais je ne comprend pas pourquoi
	ASSERT(dir_b_2==dir_b);
	ASSERT(dir_c_2==dir_c);
	
	
	
	
}


void testdevantCoord(){
	ASSERT(egalCoord(devantCoord(creeCoord(1, 1), Direction::S), creeCoord(2, 1)));
	Coord myRandCoord = creeCoord(rand()%20, rand()%20);

	int myRandValue = rand()%8+1;	
	Direction myRandDirection;
	switch(myRandValue)
	{
		case 1:
			myRandDirection = Direction::N;
			break;
		case 2:
			myRandDirection = Direction::NO;
			break;
		case 3:
			myRandDirection = Direction::O;
			break;
		case 4:
			myRandDirection = Direction::SO;
			break;
		case 5:
			myRandDirection = Direction::S;
			break;
		case 6:
			myRandDirection = Direction::SE;
			break;
		case 7:
			myRandDirection = Direction::E;
			break;
		case 8:
			myRandDirection = Direction::NE;
			break;
		default :
			cout << "Erreur lors de l'attribution de la direction" << endl;
			myRandDirection = Direction::N;
			break;
	}
	
	Coord inFrontOfMyCoord = devantCoord(myRandCoord, myRandDirection);
	
	for(int i=0; i<4; i++){
		tourneDroiteDir(myRandDirection);
	}
	
	Coord backOnMyTrackCoord = devantCoord(inFrontOfMyCoord, myRandDirection);
	//Comme j'ai mis en aleartoire les coordonées+directions
	//choisies, ce test ne marche pas tout le temps
	//je ne comprend pas pourquoi
	ASSERT(egalCoord(myRandCoord, backOnMyTrackCoord));
	
	
	
}



int main(){
	srand(time(NULL));
	testEgalCoord();
	testdirGaucheetDroite();
	testdevantCoord();
	return 0;
}

