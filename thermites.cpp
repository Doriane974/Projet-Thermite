
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//grille : vector<vector<element>>

struct Coord{
	int abs;
	int ord;
}

enum Direction{N,NO,O,SO,S,SE,E,NE};

const int LIGNE=10;
const int COLONNE=10;

//enum Elements{thermite,brindille,vide};

//vide = -1
//

struct Termite{
	int idT;
	Coord c;
	int sablier;
	bool brindille;
	Direction dir;
	bool tourneSurPlace;
}

struct Case{
	Termite termite; // 0;1;2;3...
	bool brindille;//0 pas de bridille ; 1 oui
	
	
	
}

struct Grille{
	vector<vector<Case>> grille;
	int ligne;
	int colonne;
	
}



void initialiseGrilleVide(Grille &G){
	cout<<"combien de lignes?"<<endl;
	cin>>G.ligne;
	cout<<"Combien de colonne?"<<endl;
	cin>>G.colonne;
	//vector<vector<string>> grille;
	G.grille=vector<vector<Case>>(G.colonne-1);
	for(int i = 0; i<colonne; i++){
		G.grille[i]=vector<Case>(ligne-1);
	}
	
	
}


bool estVide(Grille G, Coord c){
	bool abscisse = true;
	bool ordonnee=true;
	if (c.abs>=G.colonne && c.abs<0 ){
		abscisse=false;
	}
	if (c.ord>=G.ligne && c.ord<0 ){
		ordonnee=false;
	}
	if(ordonnee==true && abscisse==true){
		if(G.grille[c.abs][c.ord].termite==0 && G.grille[c.abs][c.ord].brindille==0){
			cout<<"la case est vide"<<endl;
			return true;
		} 
		else{
			cout<<"il y a quelque chose cans cette case"<<endl;
			return false;
		}
	}
	else{
		cout<<"Ces coordonnées ne correspondent a aucune cases"<<endl;
		exit(EXIT_FAILURE);
	}
}


bool dansGrille( Grille G, Coord c){
	if (c.abs>=G.colonne && c.abs<0 ){
		abscisse=false;
	}
	if (c.ord>=G.ligne && c.ord<0 ){
		ordonnee=false;
	}
	if(ordonnee==true && abscisse==true){
		return true;
	}
	else{
		return false;
	}	
}

bool contientBrindille( Grille G, Coord c){
	if (dansGrille(G, c)==true){
		if(G.grille[c.abs][c.ord].brindille==0){
			return false;
		}
		else{
			return true;
		}
	}
	else{
		exit(EXIT_FAILURE);
	}
	
}

int numeroTermite(Grille G, coord c){
	if( dansGrille==true ){
		if(G.grille[c.abs][c.ord].termite.idT>=0){
			return G.grille[c.abs][c.ord].termite.idT;
		}
		else{
			return -1;
		}
	}
	else{
		cout<<"pas dans la grille"<<endl;
		return -1
	}
}


bool laVoieEstLibre(Grille G, Termite T){
	on regarde la les coordonées de la case dont laquelle il y ala thermite
	on regarde la direction de la termite
	on calcule les coordonnées de la case devant elle
	on regarde si cette case est vide
	
	int abscisse =T.c.abs;
	int ordonnee = T.c.ord;
	
	//il faut d'abord regarder si on est pas sur un coté 
	//de la grille
	
	if(T.c.abs!=0 && T.c.abs!=colonne-1 && T.C.ord!=0 && T.C.ord!= ligne-1){
	
		switch (T.dir)
		{
			case N:
				ordonnee=ordonee-1;
				break;
			case NO:
				ordonnee=ordonnee-1;
				abscisse=abscisse-1;
				break;
			case O:
				abscisse=abscisse-1;
				break;
			case SO:
				ordonnee=ordonnee+1;
				abscisse=abscisse-1;
				break;
			case S:
				ordonnee=ordonnee+1;
				break;
			case SE:
				abscisse=abscisse+1;
				ordonnee=ordonne+1;
				break;
			case E:
				abscisse=abscisse+1;
				break;
			default://NE
				abscisse=abscisse+1;
				ordonnee=ordonnee-1;
				break;
		}	
	}
	else if(
	
	
	
	
	
	
	
}

















