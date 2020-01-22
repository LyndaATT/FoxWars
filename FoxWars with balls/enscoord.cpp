#include "enscoord.hpp"

using namespace std;

const int taille=20;


void creerEC(EnsCoord &ec){
	ec.nbElts=0;
}

void ajouteEC(EnsCoord &e, Coord c){
	e.tab[e.nbElts]=c;
	e.nbElts++;
}



void afficheEC(EnsCoord &e){
     for(int i=0; i<e.nbElts;i++){
        afficheCoord(e.tab[i]);
     }
}

int carEC(EnsCoord e){
     return e.nbElts;
}

Coord randomEC(EnsCoord e){
	srand (time(NULL));
	int indice = rand() % (e.nbElts);
	return e.tab[indice];
}


EnsCoord trouverVoisins(Coord c){
    EnsCoord voisins;
    creerEC(voisins);
    int x=getX(c); int y=getY(c);
    int minX,maxX,minY,maxY;
    if(x+1>19){ maxX=19;}else{ maxX=x+1;}
    if(x-1<0){ minX=0;}else{ minX=x-1;}
    if(y+1>19){ maxY=19;}else{ maxY=y+1;}
    if(y-1<0){ minY=0;}else{ minY=y-1;}
    for(int i=minX ; i<=maxX ; i++){
        for(int j=minY ; j<=maxY ; j++){
            Coord c2 = creerCoord(i,j);
	    if(not egalCoord(c2,c)){
            ajouteEC(voisins, c2);}
        }
    }
    return voisins;
}

void supprimerEC(EnsCoord &e,Coord c){
    for (int i = 0; i<e.nbElts; i++){
        if(egalCoord(e.tab[i],c)){
           for(int j=i; j<e.nbElts-1 ; j++){
               e.tab[j] = e.tab[j+1];}
           e.nbElts--;
        }
  }
}
