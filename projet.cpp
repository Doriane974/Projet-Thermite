#include "projet.hpp"


void placeTermite(Grille &G, Armoire &A){
	Coord cr;
	int direct;
	for(int i =0; i<NOMBRETERMITE; i++){
		cr.ligne=rand()%G.hauteur;
		cr.colonne=rand()%G.largeur;
		if(estVide(G, cr) && dansGrille(G, cr)){
			
			direct=rand()%8;
			switch(direct)
			{
				case 0:
					A.nom[i].dir=Direction::N;
					break;
				case 1:
					A.nom[i].dir=Direction::NO;
					break;
				case 2:
					A.nom[i].dir=Direction::O;
					break;
				case 3:
					A.nom[i].dir=Direction::SO;
					break;
				case 4:
					A.nom[i].dir=Direction::S;
					break;
				case 5:
					A.nom[i].dir=Direction::SE;
					break;
				case 6:
					A.nom[i].dir=Direction::E;
					break;
				default:
					A.nom[i].dir=Direction::NE;
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
		cr.ligne=rand()%G.hauteur;
		cr.colonne=rand()%G.largeur;
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



void afficheGrille(Grille G, Armoire A){
	for (int i = 0; i<G.hauteur; i++){
		cout<<"---";
	}
	cout<<endl;
	for(int i=0; i<G.hauteur;i++){
		for(int j = 0; j<G.largeur; j++){
			if(G.grille[i][j].brindille){
				couleur("33");
				cout<<" | ";
				couleur("0");
			}
			else if (G.grille[i][j].termite==-1){
				cout<<"   ";// toutes les cases ont des termites egales a 0;
			}
			else{
				if(A.nom[G.grille[i][j].termite].brindille==true){
					couleur("33");
					cout<<" * ";
					couleur("0");
				}
				else{
					cout<<" * ";
				}
			}
		}
		cout<<endl;
	}
	for (int i = 0; i<G.largeur; i++){
		cout<<"---";
	}
	cout<<endl;
}

void action(Grille &G,Armoire &A, int i){
	chargeTermite(G,A.nom[i]);
	dechargeBrindille(G, A.nom[i]);
}





void testCoherenceTermiteTermite(Grille G, Armoire A){
	for(int i=0; i<G.hauteur ;i++){
		for(int j=0; j<G.largeur; j++){
			if(G.grille[i][j].termite!=-1){
				if(A.nom[G.grille[i][j].termite].c.ligne != i or A.nom[G.grille[i][j].termite].c.colonne!=j){
					cout<<"probleme cohérence termite-termite"<<endl;
				}
			}
		}
	}
}

void testCoherenceTermiteGrille(Grille G, Armoire A){
	for(int i=0; i<NOMBRETERMITE; i++){
		if(G.grille[A.nom[i].c.ligne][A.nom[i].c.colonne].termite!=i){
			cout<<"probleme cohérence termite-grille"<<endl;
		}
	}
}

void testCoherenceGrilleTermite(Grille G,Armoire A){
	for(int i=0; i<G.hauteur;i++){
		for(int j=0; j<G.largeur;j++){
			if(G.grille[i][j].termite!=-1){
				if(G.grille[i][j].termite<0 or G.grille[i][j].termite > NOMBRETERMITE){
					cout<<"probleme cohérence grille-termite, la termite n'existe pas"<<endl;
				}
				if(A.nom[G.grille[i][j].termite].c.ligne!=i or A.nom[G.grille[i][j].termite].c.colonne!=j){
					cout<<"probleme cohérence grille-termite, termite stockée autre part"<<endl;
				}
			}
		}
	}
	
	
}

void unTour(Grille &G, Armoire &A){
	for(int i=0; i<NOMBRETERMITE; i++){
		marcheAleatoire(G,A.nom[i]);
		action(G,A,i);
	}	
	afficheGrille(G, A);
	testCoherenceTermiteTermite(G,A);
	testCoherenceTermiteGrille(G,A);
	testCoherenceGrilleTermite(G,A);
	cout<<endl<<endl;
	
}


int main(){
	srand(time(NULL));
	Grille G;
	Armoire A;
	initialiseGrilleVide(G,20);
	placeTermite(G,A);
	placeBrindille(G);
	afficheGrille(G,A);
	for(int j=0; j<1000; j++){
		unTour(G,A);
	}
	
	//des fois ca bloque
	cout<<endl;
	return 0;
}

