#include <stdexcept>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include<time.h>
#include<iomanip>
#include <chrono>
#include <thread>
#include "grille.hpp"

#include "MLV.h"

using namespace mlv;
using namespace std;
/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << std::endl

MLV_Image *ImageR = MLV_load_Image("renard.png");
MLV_Image *ImageL = MLV_load_Image("lapin.png");
MLV_Image *ImageRL = MLV_load_Image("fond2.jpg");


void afficheLapins(window_t &foxwars, Grille g){
     EnsCoord l = toutEspece(g, Lapin);
     for (int i = 0; i < carEC(l); i++){
          Coord c = l.tab[i];
          int x = getX(c); int y = getY(c);
          foxwars.draw_filled_circle({16+32*y, 16+32*x}, 10, color::blue);
     }
  }
  
void afficheRenards(window_t &foxwars, Grille g){
     EnsCoord r = toutEspece(g, Renard);
     for (int i = 0; i < carEC(r); i++){
          Coord c = r.tab[i];
          int x = getX(c); int y = getY(c);
          foxwars.draw_filled_circle({16+32*y, 16+32*x}, 10, color::red);
     }
  }
  
  
void affichage(window_t &foxwars, Grille g){
	    foxwars.clear(color::black);
	    
	    foxwars.draw_filled_rectangle({0,0},640,640,color::mintcream);
		afficheLapins(foxwars,g);
		afficheRenards(foxwars,g);
		foxwars.update(); // afficher la fenêtre après les dernières modifs
		foxwars.wait_milliseconds(150);
}



int main(){
	srand (time(NULL));
	Grille g,g2;
  window_t foxwars = window_t("Foxwars Project", "Aff", 1200, 800);
	initialiserGrille(g);
	foxwars.draw_filled_rectangle({0,0},640,640,color::mintcream);
	afficherGrille(g);
    afficheLapins(foxwars,g);
    afficheRenards(foxwars,g);
  foxwars.update(); // afficher la fenêtre après les dernières modifs
  foxwars.wait_milliseconds(150);
  while((carEC(toutEspece(g,Renard))!=0) || (carEC(toutEspece(g,Renard)))){
	   
		deplaceTousLapins(g,g2);
		copieGrille(g2,g);
		
		affichage(foxwars,g);
		
		
		
		deplaceTousRenards(g,g2); 
		afficherGrille(g2);
		copieGrille(g2,g);
		
		affichage(foxwars,g);
		
        cout << " Nbr lapins = " << carEC(toutEspece(g,Lapin)) << endl ;
		cout << " Nbr Renard = " << carEC(toutEspece(g,Renard)) << endl ;
		//std::this_thread::sleep_for(std::chrono::milliseconds(700));
    /*if(system("CLS")) system("clear");
		std::this_thread::sleep_for(std::chrono::milliseconds(700));
    if(system("CLS")) system("clear");*/
	  
  }
  foxwars.update(); // afficher la fenêtre après les dernières modifs
		foxwars.wait_seconds(5);
	return 0;
}
