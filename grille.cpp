#include "grille.hpp"


Grille initialiseGrilleVide(Grille G, int n){
	G.largeur=n;
	G.hauteur=n;
	for(int i = 0; i<G.hauteur; i++){
		for(int j = 0; j<G.largeur; j++){
			G.grille[i][j].brindille=false;
			G.grille[i][j].termite = -1;
		}
	}
	return G;
}


bool dansGrille(Grille G, Coord c){
	if (c.ligne>TAILLE-1 or c.ligne<0 ){
		return false;
	}
	if (c.colonne>TAILLE-1 or c.colonne<0 ){
		return false;
	}
	return true;
		
}

bool estVide(Grille G, Coord c){

	if(dansGrille(G,c)==true){
		if(G.grille[c.ligne][c.colonne].termite==-1 && G.grille[c.ligne][c.colonne].brindille==0){
			return true;
		} 
		else{
			return false;
		}
	}
	return false;
}





bool contientBrindille( Grille G, Coord c){
	if (dansGrille(G, c)==true){
		if(G.grille[c.ligne][c.colonne].brindille==0){
			return false;
		}
		else{
			return true;
		}
	}
	return false;
	
}


int numeroTermite(Grille G, Coord c){
	if (dansGrille(G,c)==true){
		return G.grille[c.ligne][c.colonne].termite;
	}
	return -1;
}

void poseBrindille(Grille &G, Coord c){
	if (dansGrille(G,c)==true){
		if(estVide(G,c)==true){
			G.grille[c.ligne][c.colonne].brindille=true;
		}
	}
}


void enleveBrindille(Grille &G, Coord c){
	if (dansGrille(G,c)==true){
		if(contientBrindille(G,c)==true){
			G.grille[c.ligne][c.colonne].brindille=false;
		}
	}
}


void poseTermite(Grille &G, Coord c,Termite t){
	if (dansGrille(G,c)==true){
		if(numeroTermite(G,c)==-1){
			G.grille[c.ligne][c.colonne].termite = t.numeroT;
			t.c=c;
		}
	}
}

void enleveTermite(Grille &G, Coord c){
	if (dansGrille(G,c)==true){
		if( numeroTermite(G,c)!=-1){
			G.grille[c.ligne][c.colonne].termite=-1;
		}
	}	
}

void afficheGrille(Grille G){
	for (int i = 0; i<TAILLE; i++){
		cout<<"---";
	}
	for(int i=0; i<TAILLE;i++){
		for(int j = 0; j<TAILLE; j++){
			if(G.grille[i][j].brindille==true){
				couleur("33");
				cout<<" | ";
				couleur("0");
			}
			else if (G.grille[i][j].termite==-1){
				cout<<"   ";// toutes les cases ont des thermites egales a 0;
			}
			else{
				cout<<" * ";
			}
		}
		cout<<endl;
	}
	for (int i = 0; i<TAILLE; i++){
		cout<<"---";
	}
}

/*
int main(){
	Grille G;
	initialiseGrilleVide(G, 20);
	return 0;
}

*/












