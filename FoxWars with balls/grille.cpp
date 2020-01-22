#include "grille.hpp"
#include "animal.hpp"

using namespace std;





void grilleVide(Grille &g){
	for (int i = 0; i < taille; i++)
	{
		for (int j = 0; j < taille; j++)
		{
			Coord c = creerCoord(i,j);
			g.Grille[i][j]= creerAnimal(c,Vide);
		}
	}
}

void copieGrille(Grille g1, Grille &g2){
	for (int i = 0; i < taille; i++)
	{
		for (int j = 0; j < taille; j++)
		{
			g2.Grille[i][j] = g1.Grille[i][j];
		}
	}
	//Pas la peine d'initialiser la grille g2 !
}
void initialiserGrille(Grille &g){
	Coord c;
	for (int i = 0; i < taille; i++)
	{
		for (int j = 0; j < taille; j++)
		{
			c = creerCoord(i,j);
			float r = hasard();
			if (r<=0.07) { g.Grille[i][j]= creerAnimal(c,Renard) ;}
			else if ((r<=0.27)&&(r>0.07)) { g.Grille[i][j]= creerAnimal(c,Lapin);}
			else { g.Grille[i][j]= creerAnimal(c,Vide);}
		}
	}
}

void verifieGrille(Grille g){
	for (int i = 0; i < taille; i++)
	{
		for (int j = 0; j < taille; j++)
		{
			Coord c = creerCoord(i,j);
			Animal a = getAnimal(g,c);
			Coord ca = coordAnimal(a);
			if(not egalCoord(c,ca)){ cout << "Erreur ! Dans la coordonnées (" << i << ", " << j<< ")" << endl;}
		}
	}
}

void afficherGrille(const Grille &g){
    for(int i = 0 ; i<taille ; i++){
        for(int j = 0 ; j<taille ; j++){
            switch(g.Grille[i][j].e){
							case 0 : cout <<"\033[;31m" << "R  " ; break;
							case 1 : cout <<"\033[1;34m" << "L  " ; break;
							case 2 : cout << "\033[1;37m" << ".  " ; break;
						};
        }
    cout << endl;
    }
		cout << "\033[1;37m" << endl;
}

EnsCoord toutEspece(Grille g, Espece es){
    EnsCoord ec; Coord c; creerEC(ec);
    for(int i=0; i<taille; i++){
        for (int j=0; j<taille; j++){
             c.lig=i; c.col=j;
             if(g.Grille[i][j].e==es){
                 ajouteEC(ec,c);
             }
        }
    } return ec;
}
Animal getAnimal(Grille g, Coord c){
	int lig = getX(c);	int col = getY(c);
	return g.Grille[lig][col];
}

void setAnimal(Grille &g, Animal a){ //Utile car on changera seulement la copie d'un animal de la grille
	Coord c = coordAnimal(a);
	int x = getX(c);	int y = getY(c);
	g.Grille[x][y] = a;
}

EnsCoord voisinsVide(Grille g, Coord c){
	EnsCoord voisins = trouverVoisins(c);
	EnsCoord ec ;	creerEC(ec);
	for (int i = 0; i < carEC(voisins); i++)
	{
		Coord c2 = voisins.tab[i];
		Animal a = getAnimal(g,c2);
		if(estVide(a)){ ajouteEC(ec,c2);}
	}
	if(carEC(ec)!=0) { return ec;}
	else { ajouteEC(ec,c); return ec;}
}


EnsCoord voisinsEspece(Grille g, Espece e, Coord c){
	EnsCoord voisins = trouverVoisins(c);
	EnsCoord ec ; creerEC(ec);
	for (int i = 0; i < carEC(voisins); i++)
	{
		Coord c2 = voisins.tab[i];
		Animal a = getAnimal(g,c2);
		if(especeAnimal(a)==e){ ajouteEC(ec,c2);}
	}
	return ec;
}

void deplacerAnimal(Grille &g, Animal &a){
     a.age++;
	if(not estVide(a)){
		Coord c = coordAnimal(a);
		EnsCoord v_libres = voisinsVide(g,c);
		Coord nouv_c = randomEC(v_libres);
		//modifier les coords de l'animal !
		a.c = nouv_c;
		//Le ranger dans la grille !
		setAnimal(g,a);
	}
}

void deplaceTousLapins(Grille g1, Grille &g2){
	  copieGrille(g1,g2);
		EnsCoord coordLapins = toutEspece(g1,Lapin);
		for(int i = 0; i < carEC(coordLapins); i++){
			Coord c = coordLapins.tab[i];
		  Animal a = getAnimal(g1,c);
			deplacerAnimal(g2,a);
			EnsCoord v_libres = voisinsVide(g1,c);
			int nbrcVides = carEC(v_libres);
			if (nbrcVides!=0){
			if (not seReproduitAnimal(a,v_libres)){
				setAnimal(g2,creerAnimal(c,Vide));
			}
			else {
				setAnimal(g2,creerAnimal(c,Lapin));
			}
		}
	}
}

bool attaqueRenard(Grille &g, Animal &r){
	Coord c = coordAnimal(r);
	EnsCoord v_lapins = voisinsEspece(g,Lapin,c);
	if(carEC(v_lapins)==0){return false;}
	else {
		Coord c2 = randomEC(v_lapins);
	     mangeRenard(r);
		changeCoordAnimal(r,c2);
		setAnimal(g,creerAnimal(c,Vide));
		setAnimal(g,r);
		return true;
	}
}

void deplaceTousRenards(Grille g1, Grille &g2){
	EnsCoord coordRenards = toutEspece(g1,Renard);
	for(int i = 0; i < carEC(coordRenards); i++){
		Coord c = coordRenards.tab[i];
		Animal a = getAnimal(g1,c);
		faimRenard(a); // On diminue son miam en chaque début de tour !
		if(not mortAnimal(a)){ //On s'assure que notre renard n'est pas encore mort !
			bool deplace;
			deplace = attaqueRenard(g2,a);
			if(deplace == false){
				deplacerAnimal(g2,a);
				EnsCoord v_libres = voisinsVide(g1,c);
				if (not seReproduitAnimal(a,v_libres)){
					setAnimal(g2,creerAnimal(c,Vide));
				}
				else{
					setAnimal(g2,creerAnimal(c,Renard));
				}
			}
		}
		else{ setAnimal(g2,creerAnimal(c,Vide));}
	}
}
