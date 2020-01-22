#ifndef COORD_HPP_INCLUDED
#define COORD_HPP_INCLUDED

#include <iostream>

struct Coord{
	int lig,col;
};

/////////////////////////////////////////////////////////////////////////////////
//                    Fonction du type abstrait : affichages                   //
/////////////////////////////////////////////////////////////////////////////////

/** Renvoyer un nombre au hasard **/
float hasard();

/** Renvoyer la coordonnée qui correspond à x et y
  * @param[in] x : entier
  * @param[in] y : entier
  * @return la coordonnée correspondante à la ligne et colonne données
  **/
Coord creerCoord(int x, int y);


/** Afficher une coordonnée
  * @param[in] c : coordonnée
  **/
void afficheCoord(Coord c);


/** Renvoyer la ligne de la coordonée
  * @param[in] c : coordonnée
  * @return la ligne correspondante à la coordonnée
  **/
int getX(Coord c);


/** Renvoyer la colonne de la coordonée
  * @param[in] c : coordonnée
  * @return la colonne correspondante à la coordonnée
  **/
int getY(Coord c);


/** Tester si deux coordonnées sont égales
  * @param[in] c1,c2 : coordonnées
  * @return True si les coordonnées sont égales, false sinon
 **/
bool egalCoord(Coord c1, Coord c2);


 /*                                     
void testCreerCoord();
void testGet();
void testEgalCoord() ;
*/
#endif 

