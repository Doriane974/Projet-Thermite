#include "termite.hpp"


Direction directionTermite(Termite t){
	return t.dir;	
}

Coord devantTermite(Termite t){
	return devantCoord(t.c, t.dir);
}
	
bool porteBrindille(Termite t){
	return t.brindille;
}

void tourneDroiteTermite(Termite &t){
	tourneDroiteDir(t.dir);
}

void tourneGaucheTermite(Termite &t){
	tourneGaucheDir(t.dir);
}

void tourneAleat(Termite &t){
	int r = rand()%2;
	if(r==0){
		tourneDroiteTermite(t);
	}
	else{
		tourneGaucheTermite(t);
	}
}


bool brindilleEnFace(Grille G, Termite t){
	return contientBrindille(G, devantTermite(t));
}

bool laVoieEstLibre(Grille G, Termite t){
	Coord cd = devantTermite(t);
	return (dansGrille(G, cd) && G.grille[cd.ligne][cd.colonne].termite == -1 && !G.grille[cd.ligne][cd.colonne].brindille);
}


/*

bool estEnferme(Grille G, Termite &t){
	if(t.tourneSurPlace==true){
		return true;
	}	
	int i = 0;
	while(i<8){
		tourneAGauche(t);
		i++;
		// ya un probleme avec l'appel de laVoieEstLibre
		if(laVoieEstLibre(G,t)==true){
			t.tourneSurPlace=false;
		}
	}
	return true;
	
}
*/

/*
bool vaEtreEnferme(Grille G, Termite &t){
	if(t.tourneSurPlace==true){
		return true;
	}	
	else{
		int i=0;
		while(i<8){
			tourneADroite(t);
			i++;
			if(laVoieEstLibre(G,t)==true){
				if(i==7){
					return true;
				}
				return false;
			}
		}
		t.tourneSurPlace=true;
	}
	return true;
}



*/












/*


//il y a une erreur de segementation ici
bool termiteEstEnferme(Grille G, Termite &t){
	if (t.tourneSurPlace==true){
		return true;
	}
	else{
		int i=0;
		while(i<8){
			tourneADroite(t);	
			if (laVoieEstLibre(G,t)==true){
				t.tourneSurPlace=true;
				return true;
			}
			i++;
		}
		
	}
	t.tourneSurPlace=false;
	return false;
}
*/

/*
bool vasEtreEnferme(Grille G, Termite t){
	int i;
	
	if (termiteEstEnferme(G,t)==false){
		while(estVide(G,devantTermite(t))==false){
			tourneADroite(t);
		}
		//la on la termite regarde dans la direction ou il va poser sa brindille
		do{
			tourneADroite(t);
			i++;
			if(i==7){
				return true;
			}
		}while(estVide(G,devantTermite(t))==false);
		return false;
	}
	return true;		
}
*/

void avanceTermite(Grille &G, Termite &t){
	Coord tamp;
	tamp = t.c;
	Coord dev;
	dev = devantTermite(t);
	int i = 0;
	//t.c=devantTermite(t);
	while(!laVoieEstLibre(G, t) && !t.tourneSurPlace){
		tourneAleat(t);
		i++;
		if(i==16){
			t.tourneSurPlace = true;
		}
	}
	if(laVoieEstLibre(G, t)){
		enleveTermite(G, tamp);
		poseTermite(G, dev, t);
		t.c = dev;
		t.sablier++;
	}
}


void dechargeBrindille(Grille &G, Termite &t){
	Coord ct;
	ct=devantTermite(t);
	if(t.sablier>=PEUTPOSER){
		if(porteBrindille(t)==true && contientBrindille(G,ct)==false){
			poseBrindille(G,ct);
			t.brindille=false;
			t.sablier=0;
		}
	}
}

void chargeTermite(Grille &G, Termite &t){
	Coord c=devantTermite(t);
	if(porteBrindille(t)==false && contientBrindille(G,c)==true){
		if (t.sablier>=PEUTPOSER){
			enleveBrindille(G,c);
			t.brindille=true;	
			t.sablier=0;
		}
	}
}


void marcheAleatoire(Grille &G, Termite &t){
	int r = rand()%10;
	if (r==0){
		tourneAleat(t);
	}
	avanceTermite(G,t);
}
/*
void termiteDansCase(Grille G, Coord c, Termite &t){
	if (G.grille[c.ligne][c.colonne].termite!=-1){
		
	
}

int main(){
	return 0;
}
*/












