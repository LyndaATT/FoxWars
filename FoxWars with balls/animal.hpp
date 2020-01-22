#ifndef ANIMAL_HPP_INCLUDED
#define ANIMAL_HPP_INCLUDED

#include "coord.hpp"
#include "enscoord.hpp"


struct Animal{
	Coord c;
	Espece e;
	int miam;
	int age;
};
/************ Constantes ************/
const int MaxFood = 10;		const float ProbBirthRenard = 0.05;
const int FoodInit = 5;		const float ProbBirthLapin = 0.30;
const int FoodReprod = 5;	const int MinFreeBirthLapin = 4;
const int FoodLapin = 5;      



/////////////////////////////////////////////////////////////////////////////////
//                    Fonction du type abstrait : affichages                   //
/////////////////////////////////////////////////////////////////////////////////



/** Creer un animal
  * @param[in] c : coordonnée
  * @param[in] e : espece
  * @return animal
  **/
Animal creerAnimal(Coord c, Espece e);

/** Renvoyer la coordonnée correpondante à un animal 
  * @param[in] a : animal
  * @return coordonnée
  **/ 
Coord coordAnimal(Animal a);

/** Renvoyer l'espece d'un animal
  * @param[in] a : animal
  * @return espece
  **/ 
Espece especeAnimal(Animal a);

/** Renvoyer la quantité de nourriture d'un renard
  * @param[in] a : animal
  * @return entier
  **/ 
int nourritureRenard(Animal a);

/** Renvoyer l'age de l'animal
  * @param[in] a : animal
  * @return entier
  **/
int ageAnimal(Animal a);

/** Renvoyer vrai s'il n'y a pas d'animal faux sinon
  * @param[in] a : animal
  * @return vrai/faux
  **/ 
bool estVide(Animal a);

/** Changer les coordonnées d'un animal
  * @param[in/out] a : animal
  * @param[in] c : coordonnée
  **/ 
void changeCoordAnimal(Animal &a, Coord c);

/** Augmenter le niveau de nourriture du renard quand il mange un lapin
  * @param[in/out] a : animal
  **/ 
void mangeRenard(Animal &a);
/** Diminuer d’une unité le niveau de nourriture du renard
  * @param[in/out] a : animal
  **/   
void faimRenard(Animal &a);

/** Renvoyer vrai si l’animal meurt
  * @param[in] a : animal
  * @return vrai/faux
  **/   
bool mortAnimal(Animal a);

/** Renvoyer vrai si l’animal se reproduit, connaissant le nombre de cases voisines libres
  * @param[in] a : animal
  * @param[in] e : ensemble de coordonnées
  * @return vrai/faux
  **/   
bool seReproduitAnimal(Animal a, EnsCoord e);

#endif
