#include "projet.hpp"


void placeTermite(Grille &G, Armoire &A){
	Coord cr;
	int direct;
	for(int i =0; i<NOMBRETERMITE; i++){
		cr.ligne=rand()%TAILLE;
		cr.colonne=rand()%TAILLE;
		if(estVide(G, cr) && dansGrille(G, cr)){
			
			direct=rand()%8;
			switch(direct)
			{
				case 0:
					A.nom[i].dir=N;
					break;
				case 1:
					A.nom[i].dir=NO;
					break;
				case 2:
					A.nom[i].dir=O;
					break;
				case 3:
					A.nom[i].dir=SO;
					break;
				case 4:
					A.nom[i].dir=S;
					break;
				case 5:
					A.nom[i].dir=SE;
					break;
				case 6:
					A.nom[i].dir=E;
					break;
				default:
					A.nom[i].dir=NE;
					break;
			}
			
			A.nom[i].brindille=false;
			A.nom[i].sablier=0;
			A.nom[i].numeroT=i;
			A.nom[i].tourneSurPlace=false;
			A.nom[i].c=cr;
			
			G.grille[cr.ligne][cr.colonne].termite=i;
		}
		else{
			i--;
		}		
	}
}



void placeBrindille(Grille &G){
	Coord cr;
	for (int i=0; i<NOMBREBRINDILLE; i++){
		cr.ligne=rand()%TAILLE;
		cr.colonne=rand()%TAILLE;
		if(estVide(G, cr) && dansGrille(G, cr)){
			G.grille[cr.ligne][cr.colonne].brindille=true;
		}
		else{
			i--;
		}		
	}	
}

//ATTENTION: des fois ya des brindilles/termites qui apparaissent 
//en dehors de la grille...



void afficheGrille(Grille G){
	for (int i = 0; i<TAILLE; i++){
		cout<<"---";
	}
	for(int i=0; i<TAILLE;i++){
		for(int j = 0; j<TAILLE; j++){
			if(G.grille[i][j].brindille){
				couleur("33");
				cout<<" | ";
				couleur("0");
			}
			else if (G.grille[i][j].termite==-1){
				cout<<"   ";// toutes les cases ont des termites egales a 0;
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

void action(Grille &G,Armoire &A, int i){
	chargeTermite(G,A.nom[i]);
	dechargeBrindille(G, A.nom[i]);
}

void unTour(Grille &G, Armoire &A){
	for(int i=0; i<NOMBRETERMITE; i++){
		marcheAleatoire(G,A.nom[i]);
		action(G,A,i);
	}	
	afficheGrille(G);
	cout<<endl<<endl;
}


int main(){
	srand(time(NULL));
	Grille G;
	Armoire A;
	G=initialiseGrilleVide(G,TAILLE);
	placeTermite(G,A);
	placeBrindille(G);
	afficheGrille(G);
	for(int j=0; j<500; j++){
		unTour(G,A);
	}
	
	//des fois ca bloque
	cout<<endl;
	return 0;
}

