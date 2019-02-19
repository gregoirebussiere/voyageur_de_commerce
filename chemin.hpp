#ifndef cheminH
#define cheminH
#include "matrice_g.hpp"

#include <iostream>


using namespace std;

class chemin
{
    public:
    int dim_; //dimension de la matrice
    int * val_; //tableau des valeurs
    double fit_; //longeur totale du chemin


    chemin(): dim_(0), val_(NULL), fit_(0) {} //constructeur par défaut
    chemin(int, const matrice &); //constructeur dimensions et matrice le chemin choisi est 0,1,2,...,n
    chemin(const chemin &, const matrice &); //constructeur par copie
    ~chemin(); //destructeur


    bool operator==(const chemin &); //test d'égalité
    bool operator !=(const chemin &); //test de différence

    double fitness(const matrice &);

    int dim() const; //acces a la dimension
    double fit() const;
    int & operator()(int) const;
    void set(int i, int k, const matrice &); // modifie la valuer i du chemin qui prend la valuer k

    bool admissible(); //fonction qui vérifie que l'on passe une et une seule fois par chauqe ville

};


ostream & operator<<(ostream &, const chemin &); //sortie
istream & operator>>(istream &, chemin &); //entree






#endif
