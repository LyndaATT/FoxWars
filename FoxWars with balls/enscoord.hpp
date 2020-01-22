#ifndef ENSCOORD_HPP_INCLUDED
#define ENSCOORD_HPP_INCLUDED


#include "coord.hpp"
enum Espece { Renard, Lapin, Vide };

struct EnsCoord{
	Coord tab[400];
	int nbElts;
};
/////////////////////////////////////////////////////////////////////////////////
//                    Fonction du type abstrait : affichages                   //
/////////////////////////////////////////////////////////////////////////////////

/** Renvoyer un ensemble de coordonnées
  * @param[in/out] ec : ensemble de coordonnées
  **/
void creerEC(EnsCoord &ec);


/** Ajouter une coordonnée à un ensemble de coordonnées
  * @param[in/out] e : ensemble de coordonnées
  * @param[in] c : coordonnée
  **/
void ajouteEC(EnsCoord &e, Coord c);


/** Renvoyer le cardinal d'un ensemble
  * @param[in/out] e : ensemble de coordonnées
  * @return le cardinal de l'ensemble
  **/
int carEC(EnsCoord e);


/** Renvoyer une coordonnée d'un ensemble au hasard
  * @param[in] e : ensemble de coordonnées
  * @return la une coordonnée au hasard
  **/
Coord randomEC(EnsCoord e);


/** Renvoyer l'ensemble des voisins d'une coordonnée
  * @param[in] c : coordonnée
  * @return ensemble de coordonnées (voisins de la coordonnée donnée)
 **/
EnsCoord trouverVoisins(Coord c);

/** Supprimer une coordonnée d'un ensemble de coordonnées
  * @param[in] c : coordonnée
  * @param[in] e : ensemble de coordonnées
  **/
void supprimerEC(EnsCoord &e,Coord c);


/** Afficher un ensemble de coordonnées
  * @param[in] e : ensemble de coordonnées
  **/
void afficheEC(EnsCoord e);

/*
void testSupprimeEC();
void testAffiche();
void testTrouverVoisins();*/



#endif // ENSCOORD_HPP_INCLUDED
