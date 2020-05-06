#ifndef PROJET_HPP_INCLUDED
#define PROJET_HPP_INCLUDED
#include "termite.hpp"

const int NOMBRETERMITE=20;
const int NOMBREBRINDILLE=40;

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

/**fais effectuer une action a charque termite de la grille (avancer et deposer/prendre une brindille)
@param[in/out] G : la grille dans laquelle on se place
@param[in/out] A : l'armoire contenant les termites que l'on va actionner.
**/
void unTour(Grille &G, Armoire &A);






























#endif

