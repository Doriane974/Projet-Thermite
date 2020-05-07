#include "coord.cpp"

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
	Coord c1 = creeCoord(1, 1);
	Direction dir1=Direction::S;
	Coord c2 = creeCoord(2, 1);
	ASSERT(egalCoord(devantCoord(c1, dir1),c2));
	Coord c3;
	c3.ligne=rand()%20;
	c3.colonne=rand()%20;
	int direct3=rand()%8+1;
	Direction dir3;
	
	switch(direct3)
	{
		case 1:
			dir3 =Direction::N;
			break;
		case 2:
			dir3 =Direction::NO;
			break;
		case 3:
			dir3 =Direction::O;
			break;
		case 4:
			dir3 =Direction::SO;
			break;
		case 5:
			dir3 =Direction::S;
			break;
		case 6:
			dir3 =Direction::SE;
			break;
		case 7:
			dir3 =Direction::E;
			break;
		default://NE
			dir3 =Direction::NE;
			break;
	}
	
	Direction dir4=dir3;
	Coord c4;
	c4=devantCoord(c3, dir3);
	
	for(int i=0;i<4;i++){
		tourneDroiteDir(dir4);
	}
	
	c4=devantCoord(c4, dir4);
	//Comme j'ai mis en aleartoire les coordonées+directions
	//choisies, ce test ne marche pas tout le temps
	//je ne comprend pas pourquoi
	ASSERT(egalCoord(c3,c4));
	
	
	
}



int main(){
	srand(time(NULL));
	testEgalCoord();
	testdirGaucheetDroite();
	testdevantCoord();
	return 0;
}

