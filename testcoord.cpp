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
	ASSERT(tourneDroiteDir(tourneGaucheDir(dir_a)) == Direction::N);
	//(b)et(c)
	Direction dir_b = Direction::S;
	Direction dir_c = Direction::S;
	Direction dir_b_2 = Direction::S;
	Direction dir_c_2 = Direction::S;
	for(int i=0; i<8; i++){
		tourneDroiteDir(dir_b_2);
		tourneGaucheDir(dir_c_2);
		
	}
	ASSERT(dir_b_2==dir_b);
	ASSERT(dir_c_2==dir_c);
	
	//(c)
	
	
}


void testdevantCoord(){
	Coord c1 = creeCoord(1, 1);
	Direction dir1=Direction::S;
	Coord c2 = creeCoord(2, 1);
	ASSERT(egalCoord(devantCoord(c1, dir1),c2));
	/*REECRIRE CETTE PARTIE, PAS D'INTERACTION AVEC L'UTILISATEUR DANS LE FICHIER DE TEST
	cout<<"choisir une coordonnée"<< endl;
	Coord c3;
	cin>>c3.ligne;
	cin>>c3.colonne;
	cout<<"choisir une direction 1=nord; 2=nordouest ... 8=nord est"<<endl;
	Direction dir3;
	int direct3;
	cin>>direct3;
	
	switch(direct3)
	{
		case 1:
			dir3 = N;
			break;
		case 2:
			dir3 = NO;
			break;
		case 3:
			dir3 = O;
			break;
		case 4:
			dir3 = SO;
			break;
		case 5:
			dir3 = S;
			break;
		case 6:
			dir3 = SE;
			break;
		case 7:
			dir3 = E;
			break;
		default://NE
			dir3 = NE;
			break;
	}
	
	Direction dir4=dir3;
	Coord c4;
	c4=devantCoord(dir3,c3);
	
	for(int i=0;i<4;i++){
		dir4=aDroite(dir4);
	}
	
	c4=devantCoord(dir4,c4);
	
	ASSERT(egalCoord(c3,c4));
	*/
	
	
}



int main(){
	testEgalCoord();
	testdirGaucheetDroite();
	testdevantCoord();
	return 0;
}

