
#include "coord.hpp"

/*
struct Coord{
	int abs;
	int ord;
};
*/

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
	
	if (c1.ligne==c2.ligne && c1.colonne==c2.colonne){
		return true;
	}
	return false;
	
	
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

Direction aGauche(Direction dir){
	switch(dir)
	{
		case N:
			return NO;
			break;
		case NO:
			return O;
			break;
		case O:
			return SO;
			break;
		case SO:
			return S;
			break;
		case S:
			return SE;
			break;
		case SE:
			return E;
			break;
		case E:
			return NE;
			break;
		default://NE
			return N;
			break;
	}
	
}

Direction aDroite(Direction dir){
	switch(dir)
	{
		case N:
			return NE;
			break;
		case NO:
			return N;
			break;
		case O:
			return NO;
			break;
		case SO:
			return O;
			break;
		case S:
			return SO;
			break;
		case SE:
			return S;
			break;
		case E:
			return SE;
			break;
		default://NE
			return E;
			break;
	}
	
}





Coord devantCoord(Direction dir, Coord c){
	
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
