#include "coord.cpp"

void testEgalCoord(){
	Coord c1 = creeCoord(2,1);
	
	Coord c2 = creeCoord(3,1);
	Coord c3 = creeCoord(2,1);
	
	ASSERT(egalCoord(c1,c2)==false);
	ASSERT(egalCoord(c1,c3)==true);
	
		
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
	Direction dir_a=N;
	ASSERT(aDroite(aGauche(dir_a))==N);
	//(b)et(c)
	Direction dir_b=S;
	Direction dir_c=S;
	Direction dir_b_2=S;
	Direction dir_c_2=S;
	for(int i=0;i<8;i++){
		dir_b_2=aDroite(dir_b_2);
		dir_c_2=aGauche(dir_c_2);
		
	}
	ASSERT(dir_b_2==dir_b);
	ASSERT(dir_c_2==dir_c);
	
	//(c)
	
	
}


void testdevantCoord(){
	Coord c1;
	c1.ligne=1;
	c1.colonne=1;
	Direction dir1=S;
	Coord c2;
	c2.ligne=2;
	c2.colonne=1;
	ASSERT(egalCoord(devantCoord(dir1,c1),c2));
	cout<<"choisir une coordonée"<<endl;
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
	
	
	
}



int main(){
	couleur("33");
	Coord c1 = creeCoord(2,1);
	afficheCoord(c1);
	
	cout << endl;
	cout<<getLigne(c1)<<endl;
	cout<<getColonne(c1)<<endl;
	
	testEgalCoord();

	testdirGaucheetDroite();
	
	Direction dirt=NE;
	afficheDirection(dirt);
	
	
	testdevantCoord();
	
	return 0;
}

