#include <iomanip>
#include "coord.hpp"

using namespace std;

float hasard(){
  return float(rand())/float(RAND_MAX);
}

Coord creerCoord(int x, int y){
	Coord c;
	c.lig = x;	c.col = y;
	return c;
}

void afficheCoord(Coord c){
     cout << " ("<< c.lig <<", "<<c.col<<")"<< endl;
}

int getX(Coord c){
	return c.lig;
}

int getY(Coord c){
	return c.col;
}

bool egalCoord(Coord c1, Coord c2){
	int lig1 = getX(c1);	int col1 = getY(c1);
	int lig2 = getX(c2);	int col2 = getY(c2);
	if((lig1==lig2)&&(col1 == col2)){ return true;}
	else{ return false;}
}


