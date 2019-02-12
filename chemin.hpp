#ifndef cheminH
#define cheminH
#include "matrice_g.hpp"
#include "individu.hpp"

#include <iostream>


using namespace std;

class chemin
{
    public:
    int dim_; //dimension de la matrice
    int * val_; //tableau des valeurs
    double fit_; //longeur totale du chemin


    chemin(): dim_(0), val_(NULL), fit_(0) {}; //constructeur par défaut
    chemin(int, const matrice &M); //constructeur dimensions et matrice le chemin choisi est 0,1,2,...,n
    chemin(const chemin &); //constructeur par copie



    bool operator==(const chemin &); //test d'égalité
    bool operator !=(const chemin &); //test de différence

    double fitness(const matrice &);

    int dim() const; //acces a la dimension
    double fit() const;
    int & operator()(int) const;

    
};

chemin mutation(const chemin &V);
chemin operator *(const chemin &chemin1, const chemin &chemin2);

ostream & operator<<(ostream &, const chemin &); //sortie
istream & operator>>(istream &, chemin &); //entree






#endif
