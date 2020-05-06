#ifndef COORD_HPP_INCLUDED
#define COORD_HPP_INCLUDED
/*
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>


#include "coord.cpp"
*/
#define ASSERT(test)                                                           \
    if (!(test))                                                               \
    cout << "Test failed in file " << __FILE__ << " line " << __LINE__         \
         << ": " #test << endl

#include <iostream>
#include <cstdlib>
#include <ctime>
#define couleur(param) printf("\033[%sm",param)


using namespace std;


struct Coord{
	int ligne; //anciennement abs
	int colonne; //anciennement ord
};

enum Direction{N,NO,O,SO,S,SE,E,NE};

/////////////////////////////////////////////////////////////////////////////////
//                    Documentation des fonctions du type abstrait             //
/////////////////////////////////////////////////////////////////////////////////


/** retourne une coordonée à partir d'un numero de ligne et de colonne
@param[in] lig : le numero de ligne
@param[in] col : le numero de colonne

**/
Coord creeCoord(int col, int lig);


/** affiche les coordonnée sous la forme (lig,col)
@param[in] coordonee : des coordonnées de type Coord
**/
void afficheCoord(Coord C);



/** retourne l'abscisse(le numero de colonne) d'une coordonéée donnée
@param[in] coordonnee : un Coord dont on veut obtenir l'abscisse
**/
int getLigne(Coord C);


/** retourne l'ordonnée(le numero de ligne) d'une coordonéée donnée
@param[in] coordonnee : un Coord dont on veut obtenir l'ordonnée
**/
int getColonne(Coord C);



/** retourne vrai si deux coordonnées sont egales, faux sinon
@param[in] c1: premier Coord a tester
@param[in] c2 : deuxieme Coord a tester
**/
bool egalCoord(Coord c1, Coord c2);


/**teste la foncion egalCoord
**/
void testEgalCoord();

/**Afiche la direction d'un type Dirercion
@param[in] dir : la direction que on veut afficher
**/
void afficheDirection(Direction dir);


/**retourne la direction a Gauche d'une Direction donnée(un quart de tour a gauche)
@param[in] dir: la direction dont on veut la gauche
**/
Direction aGauche(Direction dir);

/**retourne la direction a droite d'une Direction donnée(un quart de tours a droite)
@param[in] dir: la direction dont on veut la droite
**/
Direction aDroite(Direction dir);



/**Retourne les coordonnées de la case devant la case donnée dans une direction donnée:
@param[in] dir: direction vers laquelle on veut les coooredonées de la case de devant
@param[in] c: la case dans laquelle on se place pour avoir les coordonnées devant 
**/
Coord devantCoord(Direction dir, Coord c);



#endif

