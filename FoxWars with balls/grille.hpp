#ifndef GRILLE_HPP_INCLUDED
#define GRILLE_HPPINCLUDED


#include "animal.hpp"
#include "coord.hpp"

const int taille = 20;
struct Grille{
  Animal Grille[taille][taille];
};
////////////////////////////////////////////////////////////////////////////////
//                    Fonction du type abstrait : affichages                   //
/////////////////////////////////////////////////////////////////////////////////

/** Creer une grille vide
  * @param[in\out] g : grille
  **/
void grilleVide(Grille &g);

/** Copier une grille dans une autre
  * @param[in] g1 : grille
  * @param[in\out] g2 : grille
  **/
void copieGrille(Grille g1, Grille &g2);

/** Initialiser une grille
  * @param[in\out] g : grille
  **/
void initialiserGrille(Grille &g);

/** Verifier une grille
  * @param[in] g : grille
  **/
void verifieGrille(Grille g);

/** Afficher une grille
  * @param[in] g : grille
  **/
void afficherGrille(const Grille &g);

/** Renvoyer l’ensemble des coordonnées des animaux d'une espèce présents sur une grille
  * @param[in] g : grille 
  * @param[in] es : espece
  * @return ensemble de coordonnées
  **/
EnsCoord toutEspece(Grille g, Espece es);

/** Renvoyer l'animal correspondant à une case
  * @param[in] g : grille 
  * @param[in] c : coordonnée
  * @return animal
  **/
Animal getAnimal(Grille g, Coord c);

/** Ranger des animaux dans une grille
  * @param[in] g : grille 
  * @param[in] a : animal
  **/
void setAnimal(Grille &g, Animal a);

/** Renvoyer les cases vides autour d'une coordonnée
  * @param[in] g : grille 
  * @param[in] c : coordonnée
  * @return ensemble de coordonnées
  **/
EnsCoord voisinsVide(Grille g, Coord c);

/** Renvoyer les voisins d'une espece
  * @param[in] g : grille 
  * @param[in] e : espece
  * @param[in] c : coordonnée
  * @return ensemble de coordonnée
  **/
EnsCoord voisinsEspece(Grille g, Espece e, Coord c);

/** Deplacer un animal
  * @param[in/out] g : grille 
  * @param[in/out] a : animal
  **/
void deplacerAnimal(Grille &g, Animal &a);

/** Deplacer les lapins 
  * @param[in] g1 : grille 
  * @param[in/out] g2 : grille
  **/
void deplaceTousLapins(Grille g1, Grille &g2);

/** Renvoyer vrai si un renard a mangé un lapin faux sinon
  * @param[in/out] g : grille 
  * @param[in/out] r : animal
  **/
bool attaqueRenard(Grille &g, Animal &r);

/** Deplacer les renards 
  * @param[in] g1 : grille 
  * @param[in/out] g2 : grille
  **/
void deplaceTousRenards(Grille g1, Grille &g2);

/*
void testAfficherGrille();
void testInitialiserGrille();
void testCopieGrille();
*/
#endif
