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
	case Direction::N:
			direction = "nord";
			break;
	case Direction::NO:
			direction = "nord-ouest";
			break;
	case Direction::O:
			direction = "ouest";
			break;
	case Direction::SO:
			direction = "sud-ouest";
			break;
	case Direction::S:
			direction = "sud";
			break;
	case Direction::SE:
			direction = "sud-est";
			break;
	case Direction::E:
			direction = "est";
			break;
	case Direction::NE:
			direction = "nord-est";
			break;
	default:
		direction = "NULL";
		break;
	}
	
	cout<<"la direction est " << direction << endl;
}

void tourneGaucheDir(Direction &dir){
	switch(dir)
	{
	case Direction::N:
			dir = Direction::NO;
			break;
	case Direction::NO:
			dir = Direction::O;
			break;
	case Direction::O:
			dir = Direction::SO;
			break;
	case Direction::SO:
			dir = Direction::S;
			break;
	case Direction::S:
			dir = Direction::SE;
			break;
	case Direction::SE:
			dir = Direction::E;
			break;
	case Direction::E:
			dir = Direction::NE;
			break;
	case Direction::NE:
			dir = Direction::NE;
			break;
		default:
			cout << "Direction invalide" << endl;
			break;
	}
	
}

void tourneDroiteDir(Direction &dir){
	switch(dir)
	{
	case Direction::N:
			dir = Direction::NE;
			break;
	case Direction::NO:
			dir = Direction::N;
			break;
	case Direction::O:
			dir = Direction::NO;
			break;
	case Direction::SO:
			dir = Direction::O;
			break;
	case Direction::S:
			dir = Direction::SO;
			break;
	case Direction::SE:
			dir = Direction::S;
			break;
	case Direction::E:
			dir = Direction::SE;
			break;
	case Direction::NE:
			dir = Direction::NE;
			break;
		default:
			cout << "Coordonnée invalide" << endl;
			break;
	}
	
}





Coord devantCoord(Coord c, Direction dir){
	
	switch (dir)
	{
	case Direction::N:
			c.ligne=c.ligne-1;//
			break;
	case Direction::NO:
			c.ligne=c.ligne-1;//
			c.colonne=c.colonne-1;//
			break;
	case Direction::O:
			c.colonne=c.colonne-1;//
			break;
	case Direction::SO:
			c.ligne=c.ligne+1;
			c.colonne=c.colonne-1;//
			break;
	case Direction::S:
			c.ligne=c.ligne+1;
			break;
	case Direction::SE:
			c.colonne=c.colonne+1;//
			c.ligne=c.ligne+1;
			break;
	case Direction::E:
			c.colonne=c.colonne+1;
			break;
	case Direction::NE:
			c.colonne = c.colonne + 1;
			c.ligne = c.ligne - 1;
			break;	
		default:
			cout << "Erreur dans la direction" << endl;
			
	}	
	
	return c;
		
}

/*
int main(){
	return 0;

}

*/
