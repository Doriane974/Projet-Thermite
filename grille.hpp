#ifndef GRILLE_HPP_INCLUDED
#define GRILLE_HPP_INCLUDED

#include "coord.hpp"

const int ETAT=4;
const int TAILLE=20;

struct Case{
	
	int termite;//[ETAT]; // -1(rien);0;1;2;3...
	bool brindille;//0 pas de bridille ; 1 oui
};


struct Grille{
	int hauteur;
	int largeur;
	Case grille[500][500];
};


struct Termite{
	int numeroT;
	Coord c;
	int sablier;
	bool brindille;
	Direction dir;
	bool tourneSurPlace;	
};


/** initialise une grille vide de taille 20*20
@param[out] G: la Grille construite
**/
void initialiseGrilleVide(Grille &G, int n);


/**verfie si des coordonnées sont bien dans la grille, retourne true si c'est le cas, faux sinon
@param[in] G : une grille dans laquelle on verifie si les coordonnées sont
@param[in] c : les coordonnées a verifier 
**/
bool dansGrille( Grille G, Coord c);

/** retourne True si une case est vide,false sinon
@param[in] G : grille de type Grille avec la case a verifier dedans
@param[in] c : les coordonnées de la case a verifier
**/
bool estVide(Grille G, Coord c);

/**retourne true si la case demandé contien une brindille, faux sinon.
@param[in] G : une grille dans laquelle on verifie elle contient une brindille
@param[in] c : les coordonnées de la case a verifier 
**/
bool contientBrindille( Grille G, Coord c);


/**retourne le numéro de la termite contenue dans la case, -1 si il n'y en a pas
@param[in] G : une grille dans laquelle on regarde le numero du termite
@param[in] c : les coordonnées de la case a verifier 
**/
int numeroTermite(Grille G, Coord c);


/**pose une brindille dans une case vide de la grille
@param[in] G: une grille dans laquelle on va poser la brindille
@param[in] c : les coordonnées de la case dans laquelle on veut poser la brindille
@param[out] G: la grille modifiée
**/
void poseBrindille(Grille &G, Coord c);

/**enleve une brindille d'une case en contenant une de la grille
@param[in] G: une grille de laquelle on va enlever la brindille
@param[in] c : les coordonnées de la case de laquelle on va enlever la brindille
@param[out] G: la grille modifiée
**/
void enleveBrindille(Grille &G, Coord c);


/**pose un termite dans une case sans termite de la grille
@param[in] G: une grille dans laquelle on va poser le termite
@param[in] c : les coordonnées de la case dans laquelle on veut poser le termite
@param[in] t : le numéro du termite a poser
@param[out] G: la grille modifiée
**/
void poseTermite(Grille &G, Coord c, Termite t);

/**enleve un termite d'une case en contenant un de la grille
@param[in] G: une grille de laquelle on va enlever le termite
@param[in] c : les coordonnées de la case de laquelle on va enlever le termite
@param[out] G: la grille modifiée
**/
void enleveTermite(Grille &G, Coord c);



#endif

