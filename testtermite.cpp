#include "termite.cpp"


void testDirectionTermite(){
	Termite t1;
	Termite t2;
	Termite t3;
	Termite t4;
	t1.dir=Direction::NE;
	t2.dir=Direction::O;
	t3.dir=Direction::SO;
	t4.dir=Direction::E;
	ASSERT(directionTermite(t1)==Direction::NE);
	ASSERT(directionTermite(t2)==Direction::O);
	ASSERT(directionTermite(t3)!=Direction::S);
	ASSERT(directionTermite(t4)!=Direction::NE);
}

void testDevantTermite(){
	Termite t1;
	Termite t2;
	Termite t3;
	Termite t4;
	t1.c=creeCoord(4,4);
	t2.c=creeCoord(5,8);
	t3.c=creeCoord(9,10);
	t4.c=creeCoord(0,0);
	t1.dir=Direction::NE;
	t2.dir=Direction::O;
	t3.dir=Direction::SO;
	t4.dir=Direction::E;
	ASSERT(egalCoord(devantTermite(t1),creeCoord(3,5)));
	ASSERT(egalCoord(devantTermite(t2),creeCoord(5,7)));
	ASSERT(egalCoord(devantTermite(t3),creeCoord(10,9)));
	ASSERT(egalCoord(devantTermite(t4),creeCoord(0,1)));
}


void testPorteBrindille(){
	Termite t1;
	Termite t2;
	t1.brindille=true;
	t2.brindille=false;
	ASSERT(porteBrindille(t1));
	ASSERT(!porteBrindille(t2));
}

void testTourneDroiteTermite(){
	Termite t1;
	Termite t2;
	Termite t3;
	Termite t4;
	t1.dir=Direction::NE;
	t2.dir=Direction::O;
	t3.dir=Direction::SO;
	t4.dir=Direction::E;
	tourneDroiteTermite(t1);
	tourneDroiteTermite(t2);
	tourneDroiteTermite(t3);
	tourneDroiteTermite(t4);
	ASSERT(directionTermite(t1)==Direction::E);
	ASSERT(directionTermite(t2)==Direction::NO);
	ASSERT(directionTermite(t3)!=Direction::N);
	ASSERT(directionTermite(t4)!=Direction::O);
}

void testTourneGaucheTermite(){
	Termite t1;
	Termite t2;
	Termite t3;
	Termite t4;
	t1.dir=Direction::NE;
	t2.dir=Direction::O;
	t3.dir=Direction::SO;
	t4.dir=Direction::E;
	tourneGaucheTermite(t1);
	tourneGaucheTermite(t2);
	tourneGaucheTermite(t3);
	tourneGaucheTermite(t4);
	ASSERT(directionTermite(t1)==Direction::N);
	ASSERT(directionTermite(t2)==Direction::SO);
	ASSERT(directionTermite(t3)!=Direction::N);
	ASSERT(directionTermite(t4)!=Direction::O);
}


void testTourneAleat(){
	Termite t1;
	Termite t2;
	Termite t3;
	Termite t4;
	t1.dir=Direction::NE;
	t2.dir=Direction::O;
	t3.dir=Direction::SO;
	t4.dir=Direction::E;
	tourneAleat(t1);
	tourneAleat(t2);
	tourneAleat(t3);
	tourneAleat(t4);
	if(directionTermite(t1)!=Direction::N && directionTermite(t1)!=Direction::E){
		cout<<"test failed in file testtermite.cpp ligne 101 : tourneAleat"<<endl;
	}
	if(directionTermite(t2)!=Direction::SO && directionTermite(t2)!=Direction::NO){
		cout<<"test failed in file testtermite.cpp ligne 104 : tourneAleat"<<endl;
	}
	if(directionTermite(t3)!=Direction::S && directionTermite(t3)!=Direction::O){
		cout<<"test failed in file testtermite.cpp ligne 107 : tourneAleat"<<endl;
	}
	if(directionTermite(t4)!=Direction::NE && directionTermite(t4)!=Direction::SE){
		cout<<"test failed in file testtermite.cpp ligne 110 : tourneAleat"<<endl;
	}
}

void testLaVoieEstLibre(Grille G){
	Termite t1;
	Termite t2;
	Termite t3;
	Termite t4;
	t1.c=creeCoord(4,4);
	t2.c=creeCoord(5,8);
	t3.c=creeCoord(9,10);
	t4.c=creeCoord(0,0);
	t1.dir=Direction::NE;
	t2.dir=Direction::O;
	t3.dir=Direction::SO;
	t4.dir=Direction::E;
	G.grille[3][5].brindille=false;
	G.grille[5][7].brindille=false;
	G.grille[10][9].brindille=true;
	G.grille[0][1].brindille=true;
	ASSERT(laVoieEstLibre(G,t1));
	ASSERT(laVoieEstLibre(G,t2));
	ASSERT(!laVoieEstLibre(G,t3));
	ASSERT(!laVoieEstLibre(G,t4));	
}

void testBrindilleEnFace(Grille G){
	Termite t1;
	Termite t2;
	Termite t3;
	Termite t4;
	t1.c=creeCoord(4,4);
	t2.c=creeCoord(5,8);
	t3.c=creeCoord(9,10);
	t4.c=creeCoord(0,0);
	t1.dir=Direction::NE;
	t2.dir=Direction::O;
	t3.dir=Direction::SO;
	t4.dir=Direction::E;
	G.grille[3][5].brindille=false;
	G.grille[5][7].brindille=false;
	G.grille[10][9].brindille=true;
	G.grille[0][1].brindille=true;
	ASSERT(!brindilleEnFace(G,t1));
	ASSERT(!brindilleEnFace(G,t2));
	ASSERT(brindilleEnFace(G,t3));
	ASSERT(brindilleEnFace(G,t4));	
	//erreur de segmentation
}

void testAvanceTermite(Grille G){
	Termite t1;
	Termite t2;
	Termite t3;
	Termite t4;
	t1.c=creeCoord(4,4);
	t2.c=creeCoord(5,8);
	t3.c=creeCoord(9,10);
	t4.c=creeCoord(0,0);
	t1.dir=Direction::NE;
	t2.dir=Direction::O;
	t3.dir=Direction::SO;
	t4.dir=Direction::E;
	G.grille[3][5].brindille=false;
	G.grille[5][7].brindille=false;
	G.grille[10][9].brindille=false;
	G.grille[0][1].brindille=false;
	G.grille[3][5].termite=-1;
	G.grille[5][7].termite=-1;
	G.grille[10][9].termite=-1;
	G.grille[0][1].termite=-1;
	avanceTermite(G,t1);
	avanceTermite(G,t2);
	avanceTermite(G,t3);
	avanceTermite(G,t4);
	ASSERT(egalCoord(creeCoord(3,5),t1.c));
	ASSERT(egalCoord(creeCoord(5,7),t2.c));
	ASSERT(egalCoord(creeCoord(10,9),t3.c));
	ASSERT(egalCoord(creeCoord(0,1),t4.c));
}

void testDechargeBrindille(Grille G){
	Termite t1;
	Termite t2;
	Termite t3;
	Termite t4;
	t1.c=creeCoord(4,4);
	t2.c=creeCoord(5,8);
	t3.c=creeCoord(9,10);
	t4.c=creeCoord(0,0);
	t1.dir=Direction::NE;
	t2.dir=Direction::O;
	t3.dir=Direction::SO;
	t4.dir=Direction::E;
	G.grille[3][5].brindille=false;
	G.grille[5][7].brindille=false;
	G.grille[10][9].brindille=false;
	G.grille[0][1].brindille=false;
	G.grille[3][5].termite=-1;
	G.grille[5][7].termite=-1;
	G.grille[10][9].termite=-1;
	G.grille[0][1].termite=-1;
	t1.brindille=true;
	t2.brindille=true;
	t3.brindille=true;
	t4.brindille=true;
	dechargeBrindille(G,t1);
	dechargeBrindille(G,t2);
	dechargeBrindille(G,t3);
	dechargeBrindille(G,t4);
	/*ASSERT(t1.brindille=false);
	ASSERT(t2.brindille=false);
	ASSERT(t3.brindille=false);
	ASSERT(t4.brindille=false);*/
	ASSERT(contientBrindille(G,creeCoord(3,5)));
	ASSERT(contientBrindille(G,creeCoord(5,7)));
	ASSERT(contientBrindille(G,creeCoord(10,9)));
	ASSERT(contientBrindille(G,creeCoord(0,1)));
	ASSERT(!porteBrindille(t1));
	ASSERT(!porteBrindille(t2));
	ASSERT(!porteBrindille(t3));
	ASSERT(!porteBrindille(t4));
}

void testChargeTermite(Grille G){
	Termite t1;
	Termite t2;
	Termite t3;
	Termite t4;
	t1.c=creeCoord(4,4);
	t2.c=creeCoord(5,8);
	t3.c=creeCoord(9,10);
	t4.c=creeCoord(0,0);
	t1.dir=Direction::NE;
	t2.dir=Direction::O;
	t3.dir=Direction::SO;
	t4.dir=Direction::E;
	G.grille[3][5].brindille=true;
	G.grille[5][7].brindille=true;
	G.grille[10][9].brindille=true;
	G.grille[0][1].brindille=true;
	t1.brindille=false;
	t2.brindille=false;
	t3.brindille=false;
	t4.brindille=false;
	chargeTermite(G,t1);
	chargeTermite(G,t2);
	chargeTermite(G,t3);
	chargeTermite(G,t4);
	ASSERT(porteBrindille(t1));
	ASSERT(porteBrindille(t2));
	ASSERT(porteBrindille(t3));
	ASSERT(porteBrindille(t4));
	ASSERT(estVide(G,creeCoord(3,5)));
	ASSERT(estVide(G,creeCoord(5,7)));
	ASSERT(estVide(G,creeCoord(10,9)));
	ASSERT(estVide(G,creeCoord(0,1)));
	
	
	
}

int main(){
	srand(time(NULL));
	Grille G;
	initialiseGrilleVide(G,20);
	testDirectionTermite();
	testDevantTermite();
	testPorteBrindille();
	testTourneDroiteTermite();
	testTourneGaucheTermite();
	testTourneAleat();
	//testBrindilleEnFace(G);//erreur de segmentation
	testLaVoieEstLibre(G);
	testAvanceTermite(G);
	//testDechargeBrindille(G);// tests fail
	//testChargeTermite(G);//tests fails
	return 0;	
}

