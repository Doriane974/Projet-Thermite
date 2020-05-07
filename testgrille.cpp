#include "grille.hpp"

void testVide() {
	Grille G;
	Grille F;
	initialiseGrilleVide(G, 10);
	ASSERT(estVide(G, creeCoord(1, 1)));
	initialiseGrilleVide(F, 25);
	ASSERT(estVide(F, creeCoord(22, 12)));
}

void testDansGrille() {
	Grille G;
	initialiseGrilleVide(G, 100);
	ASSERT(dansGrille(G, creeCoord(40, 30)));
	ASSERT(dansGrille(G, creeCoord(0, 0)));
	ASSERT(dansGrille(G, creeCoord(36, 16)));
	ASSERT(dansGrille(G, creeCoord(99, 99)));
	ASSERT(!dansGrille(G, creeCoord(100, 10)));
	ASSERT(!dansGrille(G, creeCoord(-1, 50)));
	ASSERT(!dansGrille(G, creeCoord(-3, 50)));
	ASSERT(!dansGrille(G, creeCoord(120, 120)));
}

void testBrindille() {
	Grille G;
	initialiseGrilleVide(G, 10);
	ASSERT(!contientBrindille(G, creeCoord(0, 0)));
	ASSERT(!contientBrindille(G, creeCoord(20, 0)));
	ASSERT(!contientBrindille(G, creeCoord(5, 5)));
	ASSERT(!contientBrindille(G, creeCoord(10, 24)));
	poseBrindille(G, creeCoord(2, 3));
	ASSERT(contientBrindille(G, creeCoord(2, 3)));
	enleveBrindille(G, creeCoord(2, 3));
	ASSERT(!contientBrindille(G, creeCoord(2, 3)));
	poseBrindille(G, creeCoord(20, 20));
	ASSERT(!contientBrindille(G, creeCoord(20, 20)));
}

void testTermite() {
	Grille G;
	initialiseGrilleVide(G, 10);
	ASSERT(numeroTermite(G, creeCoord(2, 2)) == -1);
	ASSERT(numeroTermite(G, creeCoord(102, 2)) == -1);
	ASSERT(numeroTermite(G, creeCoord(2, 102)) == -1);
	ASSERT(numeroTermite(G, creeCoord(1, 1)) == -1);
	ASSERT(numeroTermite(G, creeCoord(0, 0)) == -1);
	poseTermite(G, creeCoord(2, 3), creeTermite(6));
	ASSERT(numeroTermite(G, creeCoord(2, 3)) == 6);
	enleveTermite(G, creeCoord(2, 3));
	ASSERT(numeroTermite(G, creeCoord(2, 3)) == -1);
	poseTermite(G, creeCoord(100, 100), creeTermite(10));
	ASSERT(numeroTermite(G, creeCoord(100, 100)) == -1);
}

int main() {
	testVide();
	testDansGrille();
	testBrindille();
	testTermite();
	return 0;
}


