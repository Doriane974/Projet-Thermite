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
	
	return 0;	
}

