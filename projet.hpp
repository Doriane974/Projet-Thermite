#ifndef PROJET_HPP_INCLUDED
#define PROJET_HPP_INCLUDED
#include "termite.cpp"

const int NOMBRETERMITE=40;
const int NOMBREBRINDILLE=80;

//dans le tableau, pour acceders aux informations de la termite
//on pourra demander son indice
struct Armoire{
	Termite nom[500];
};


/**Place les termites aléatoirement dans une grille
@param[in/out] G : la grille dans laquelle on va placer les termites
@param[in/out] A : l'armoire dans laquelle on place les infos sur les termites déposées
**/
void placeTermite(Grille &G, Armoire &A);


/**Place les brindilles aléatoirement dans une grille
@param[in/out] G : la grille dans laquelle on va placer les brindilles
**/
void placeBrindille(Grille &G);


/**affiche une Grille
@param[in] G: la grille que l'on veut afficher
**/
void afficheGrille(Grille G);


/**fait effectuer une action a un termite
@param[in/out] G : la grille dans laquelle on se place
@param[in/out] A : l'armoire dans laquelle est contenue le termite choisi
@param[in/out] i : l'entier qui permettra d'acceder au termite choisi grace a son indice dans l'armoire.
**/
void action(Grille &G,Armoire &A, int i);

/**teste la cohérence termite-termite?
@param[in] G: la grille dans laquelle on se place 
@param[in] A: l'armoie dans laquelle sont stockées les termites
**/
void testCoherenceTermiteTermite(Grille G, Armoire A);

/**teste la cohérence termite-grille?;
@param[in] G: la grille dans laquelle on se place; 
@param[in] A: l'armoie dans laquelle sont stockées les termites
**/
void testCoherenceTermiteGrille(Grille G, Armoire A);

/**teste la cohérence grille-termite?;
@param[in] G: la grille dans laquelle on se place; 
@param[in] A: l'armoie dans laquelle sont stockées les termites
**/
void testCoherenceGrilleTermite(Grille G,Armoire A);

/**fais effectuer une action a charque termite de la grille (avancer et deposer/prendre une brindille)
@param[in/out] G : la grille dans laquelle on se place
@param[in/out] A : l'armoire contenant les termites que l'on va actionner.
**/
void unTour(Grille &G, Armoire &A);






























#endif

