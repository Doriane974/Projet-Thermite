#include "termite.hpp"

/*

int main(){
/*
	srand(time(NULL));
	Grille G;
	initialiseGrilleVide(G,TAILLE);
	
	Termite t1;
	t1.dir=N;
	cout<<directionTermite(t1)<<endl;
	t1.numeroT=1;
	
	Coord c1;
	c1=creeCoord(9,15);
	afficheCoord(c1);
	
	t1.c.ligne=c1.ligne;
	t1.c.colonne=c1.colonne;
	
	G.grille[c1.ligne][c1.colonne].termite=t1.numeroT;
	
	Coord c2;
	c2=devantTermite(t1);
	afficheCoord(c2);
	
	poseBrindille(G,c2);
	
	t1.brindille=false;
	if(porteBrindille(t1)){
		cout<<"Aie! erreur dans porteBrindille, 1"<<endl;
	}
	Termite t2;
	
	t2.brindille=true;
	if(!porteBrindille(t2)){
		cout<<"Aie! erreur dans porteBrindille, 2"<<endl;
	}
	
	tourneADroite(t1);
	afficheDirection(t1.dir);
	tourneAGauche(t1);
	afficheDirection(t1.dir);
	tourneAleat(t1);
	afficheDirection(t1.dir);
	tourneAleat(t1);
	afficheDirection(t1.dir);
	tourneAleat(t1);
	afficheDirection(t1.dir);
	tourneAleat(t1);
	afficheDirection(t1.dir);
	tourneAleat(t1);
	afficheDirection(t1.dir);
	tourneAleat(t1);
	afficheDirection(t1.dir);
	
	t1.dir=N;
	if(laVoieEstLibre(G,t1)){
		cout<<"Aie! erreur dans laVoieEstLibre, 1"<<endl;
	}
	
	Coord c3;
	c3=creeCoord(4,6);
	t2.c=c3;
	t2.numeroT=2;
	G.grille[c3.ligne][c3.colonne].termite=t2.numeroT;
	t2.dir=NE;
	if(!laVoieEstLibre(G,t2)){
		cout<<"Aie! erreur dans laVoieEstLibre, 2"<<endl;
	}
	poseBrindille(G,devantTermite(t2));
	if(laVoieEstLibre(G,t2)==true){
		cout<<"Aie! erreur dans laVoieEstLibre, 3"<<endl;
	}
	
	Termite t4;
	Coord c4=creeCoord(13,8);
	t4.numeroT=4;
	t4.c=c4;
	t4.dir=SO;
	G.grille[t4.c.ligne][t4.c.colonne].termite=t4.numeroT;
	G.grille[t4.c.ligne][t4.c.colonne+1].brindille=true;
	G.grille[t4.c.ligne][t4.c.colonne-1].brindille=true;
	G.grille[t4.c.ligne+1][t4.c.colonne].brindille=true;
	G.grille[t4.c.ligne-1][t4.c.colonne].brindille=true;
	G.grille[t4.c.ligne+1][t4.c.colonne+1].brindille=true;
	G.grille[t4.c.ligne-1][t4.c.colonne+1].brindille=true;
	G.grille[t4.c.ligne-1][t4.c.colonne-1].brindille=true;
	G.grille[t4.c.ligne+1][t4.c.colonne-1].brindille=true;
	int i=0;
	while(i<8){
		tourneADroite(t2);
		i++;
	}
	cout<<endl<<endl;
	afficheDirection(t1.dir);
	
	
	
	afficheGrille(G);
	
	tourneAleat(t2);
	avanceTermite(G,t2);
	cout<<endl<<endl;
	afficheGrille(G);
	
	Termite t5;
	Coord c5=creeCoord(17,3);
	
	t5.brindille=true;
	t5.dir=O;
	t5.sablier=6;
	t5.numeroT=5;
	poseTermite(G,c5,t5);
	
	dechargeBrindille(G,t5);
	
	//c5=creeCoord(
	cout<<endl<<endl;
	
	afficheGrille(G);
	Coord c6=creeCoord(6,6);
	Coord c6bis;
	c6bis=creeCoord(5,6);
	poseBrindille(G,c6bis);
	Termite t6;
	t6.numeroT=6;
	t6.sablier=6;
	t6.brindille=false;
	t6.c=c6;
	t6.dir=Direction::N;
	poseTermite(G,c6,t6);
	cout<<endl<<endl;
	afficheGrille(G);
	cout<<endl<<endl;
	
	chargeTermite(G,t6);
	afficheGrille(G);
	cout<<endl<<endl;
	
	Coord c7=creeCoord(15,13);
	Coord c7bis;
	c7bis=creeCoord(14,13);
	
	Termite t7;
	t7.numeroT=6;
	t7.sablier=6;
	t7.brindille=false;
	t7.c=c7;
	t7.dir=Direction::N;
	poseTermite(G,c7,t7);
	
	for (int i=0; i<5; i++){
		
		marcheAleatoire(G,t7);
		afficheGrille(G);
		cout<<endl<<endl;
	}	
	
	ASSERT(!laVoieEstLibre(G,t4));
	
	/*
	//ATTENTION : il y a une erreur de segmentation dans termiteEstEnferme
	if(termiteEstEnferme(G,t4)==false){
		cout<<"Aie! erreur dans termiteEstEnferme, 1"<<endl;
	}
	
	// IL Y A AUSSI SUREMENT UNE ERREUR DANS LAVOIEESTLIBRE
	
	*/
/*
	return 0;	
}

*/