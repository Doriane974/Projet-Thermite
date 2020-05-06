#include "grille.cpp"


struct Termite{
	int numeroT;
	Coord c;
	int sablier;
	bool brindille;
	Direction dir;
	bool tourneSurPlace;	
};


int main(){
	Grille G;
	G=initialiseGrilleVide(G, TAILLE);
	
	Coord c;
	c.ligne=1;
	c.colonne=2;
	if(estVide(G,c)==false){
		cout<<"aie, probleme dans le estVide"<<endl;
	}
	Coord c1;
	c1.ligne=20;
	c1.colonne=2;
	
	Coord c2;
	c2.ligne=3;
	c2.colonne=5;
	if(dansGrille(G,c1)){
		cout<<"aie, probleme dans le dansGrille, 1"<<endl;
	}
	if(!dansGrille(G,c2)){
		cout<<"aie, probleme dans le dansGrille, 2"<<endl;
	}
	if(contientBrindille(G,c)){
		cout<<"aie, probleme dans le contientBrindille, 1"<<endl;
	}
	G.grille[c2.ligne][c2.colonne].brindille=true;
	if(!contientBrindille(G,c2)){
		cout<<"aie, probleme dans le contientBrindille, 2"<<endl;
	}
	
	G.grille[c.ligne][c.colonne].termite=2;
	
	numeroTermite(G,c);
	
	
	//numeroTermite(G,c1);   ce test ci a fonctionner
	
	//afficheGrille(G);
	//cout<<endl<<endl;
	
	Coord c3;
	c3.ligne=18;
	c3.colonne=14;
	
	poseBrindille(G,c3);
	
	
	poseBrindille(G,c1);// ca fait rien donc ca a l'air bon
	
	Coord c4;
	c4.ligne=17;
	c4.colonne=9;
	
	
	poseTermite(G, c4,4);
	poseTermite(G, c1,4);
	
	
	//enleveTermite(G, c4);
	
	afficheGrille(G);
	cout<<endl<<endl;
	
	
	return 0;
}


