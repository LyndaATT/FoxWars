#include "animal.hpp"


using namespace std;


Animal creerAnimal(Coord c, Espece e){
	Animal a;
	a.c = c;	a.e = e;
	a.age=0;
	if (e==Renard) a.miam=FoodInit;
	return a;
}

Coord coordAnimal(Animal a){
	return a.c;
}

Espece especeAnimal(Animal a){
	return a.e;
}

int nourritureRenard(Animal a){
	return a.miam;
}

int ageAnimal(Animal a){
    return a.age;
}

bool estVide(Animal a){
	return (a.e==2);
}


void changeCoordAnimal(Animal &a, Coord c){
	a.c = c;
}

void mangeRenard(Animal &a){
	a.miam+=FoodLapin;
	if(a.miam>MaxFood){ a.miam = MaxFood;}
}

void faimRenard(Animal &a){
	a.miam--;
	if(a.miam<0){ a.miam = 0;}
}

bool mortAnimal(Animal a){
     int death;
	switch(especeAnimal(a)){
		case 0 : {death = rand()%4+2; return ((nourritureRenard(a)<=0) || ((ageAnimal(a)) >= death)) ; }
		case 1 : {death = rand()%2+1; return ((ageAnimal(a)) >=  death) ;}
		default : return false;
	};
}

bool seReproduitAnimal(Animal a, EnsCoord e){
	float f=hasard();
	float r=hasard();
	if(estVide(a)) return false;
	else if (especeAnimal(a)==1){
			int car_v = carEC(e);
      if((car_v >=MinFreeBirthLapin)&& (f<=ProbBirthLapin)){ return true;} else{ return false;}
			}else{
          if ((a.miam >= FoodReprod)&&(r<=ProbBirthRenard)){ return true;}
					else { return false;}
				}
}

