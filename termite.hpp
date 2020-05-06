#ifndef TERMITE_HPP_INCLUDED
#define TERMITE_HPP_INCLUDED
#include "grille.hpp"

const int PEUTPOSER=6;

/**retourne la direction d'un termite
@param[in] t : le termite donc on veut acceder la direction; 
**/
Direction directionTermite(Termite t);


/**retourne les Coordonnées de la case devant une termite;
@param[in] t : la termite dont on veut avoir la case devant;
**/
Coord devantTermite(Termite t);



/**retourne vrai si le termite porte une brindille, faux sinon
@param[in] t : le termite dont on veut savoir si il porte une brindille ou non
**/
bool porteBrindille(Termite t);

/**decale la direction de la termite t de 1 huitieme de tout vers la droite
@param[in/out] t :le termite a faire tourner vers la droite;
**/
void tourneADroite(Termite &t);

/**decale la direction de la termite t de 1 huitieme de tout vers la gauche
@param[in/out] t :le termite a faire tourner vers la gauche;
**/
void tourneAGauche(Termite &t);


/**Decale un termite d'un huitieme de tour vers la gauche ou vers la Droite(choisit aleatoirement)
@param[in/out] t: le termite a faire tourner.
**/
void tourneAleat(Termite &t);


/**regarde si la case devant le termite est libre et dans la grille: retourne true si c'est le cas, faux sinon;
@param[in] G: la grille dans laquelle on se place;
@param[in] t: la termite donc on veut savoir si la case devant elle est libre; 
**/
bool laVoieEstLibre(Grille G, Termite t);


/**retourne true si la case en face du termite contient une brindille, faux sinon
@param[in] G : la grille dans laquelle on se place;
@param[in] t : le termite dont on veut savoir si la case devant est libre
**/
bool brindilleEnFace(Grille G, Termite t);

/**Regarde si le termite est enfermé : retourne true si il l'est, false sinon
@param[in] G: la grille dans laquelle on se place;
@param[in/out] t : le termite qui est peut etre enferme, et dont on change le champ tourSurPlace
**/
//bool termiteEstEnferme(Grille G, Termite &t);

/**regarde si le termite peut poser une brindille, si il s'enferme en le faisant : retourne false, sinon retourne tru;
@param[in] G:lagrille dans laquelle on se place
@param[in/] t: la termite qui veut poser une brindille
**/
//bool vasEtreEnferme(Grille G,Termite &t);

//bool estEnferme(Grille G, Termite &t);

/**fais avancer un termite choisi 
@param[in/out] t :le termite a faire avancer;
@param[in/out] G :La grille dans laquelle on se place;
**/
void avanceTermite(Grille &G, Termite &t);

/**décharge une termite de sa brindille et place une brindille devant la termite
@param[in/out] G : La grille dans laquelle on va poser la brindille
@param[in/out] t : Le termite qui va décharger la brindille 
**/
void dechargeBrindille(Grille &G, Termite &t);


/**charge une termite d'une brindille situé dans une case devant lui et vide la case devant du meme coup
@param[in/out] G : La grille dans laquelle on va vider la case contenant la brindille
@param[in/out] t : Le termite qui va se charger de la brindille 
**/
void chargeTermite(Grille &G, Termite &t);


/**Fais avancer un termite aléatoirement a gauche ou a droite
@param[in/out] G : la grille ou on se place;
@param[in/out] t : le termite que l'on veut faire avancer 
**/
void marcheAleatoire(Grille &G, Termite &t);



#endif
