#include "coord.hpp"

Coord creeCoord(int lig, int col){
	Coord C;
	C.ligne=lig;
	C.colonne=col;
	return C;
}

void afficheCoord(Coord C){
	cout << "(" << C.ligne << "," << C.colonne << ")" << endl;
	
	
}


//pour avoir le numero de colonne
int getLigne(Coord C){
	return C.ligne;
	
}

//pour avoir le numero de ligne
int getColonne(Coord C){
	return C.colonne;
	
}


bool egalCoord(Coord c1, Coord c2){	
	return(c1.ligne == c2.ligne && c1.colonne == c2.colonne);
}





void afficheDirection(Direction dir){
	string direction;
	
	switch(dir)
	{
		case N:
			direction = "nord";
			break;
		case NO:
			direction = "nord-ouest";
			break;
		case O:
			direction = "ouest";
			break;
		case SO:
			direction = "sud-ouest";
			break;
		case S:
			direction = "sud";
			break;
		case SE:
			direction = "sud-est";
			break;
		case E:
			direction = "est";
			break;
		default://NE
			direction = "nord-est";
			break;
	}
	
	cout<<"la direction est " << direction << endl;
}

void tourneGauche(Direction &dir){
	switch(dir)
	{
		case N:
			dir = NO;
			break;
		case NO:
			dir = O;
			break;
		case O:
			dir = SO;
			break;
		case SO:
			dir = S;
			break;
		case S:
			dir = SE;
			break;
		case SE:
			dir = E;
			break;
		case E:
			dir = NE;
			break;
		case NE:
			dir = NE;
			break;
		default:
			cout << "Direction invalide" << endl;
			break;
	}
	
}

void tourneDroite(Direction &dir){
	switch(dir)
	{
		case N:
			dir = NE;
			break;
		case NO:
			dir = N;
			break;
		case O:
			dir = NO;
			break;
		case SO:
			dir = O;
			break;
		case S:
			dir = SO;
			break;
		case SE:
			dir = S;
			break;
		case E:
			dir = SE;
			break;
		case NE:
			dir = NE;
			break;
		default:
			cout << "Coordonnée invalide" << endl;
			break;
	}
	
}





Coord devantCoord(Coord c, Direction dir){
	
	switch (dir)
	{
		case N:
			c.ligne=c.ligne-1;//
			break;
		case NO:
			c.ligne=c.ligne-1;//
			c.colonne=c.colonne-1;//
			break;
		case O:
			c.colonne=c.colonne-1;//
			break;
		case SO:
			c.ligne=c.ligne+1;
			c.colonne=c.colonne-1;//
			break;
		case S:
			c.ligne=c.ligne+1;
			break;
		case SE:
			c.colonne=c.colonne+1;//
			c.ligne=c.ligne+1;
			break;
		case E:
			c.colonne=c.colonne+1;
			break;
		default://NE
			c.colonne=c.colonne+1;
			c.ligne=c.ligne-1;
			break;
	}	
	
	return c;
		
}

/*
int main(){
	return 0;

}

*/
