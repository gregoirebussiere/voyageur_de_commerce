#ifndef cheminH
#define cheminH
#include "matrice_g.hpp"
#include "individu.hpp"

#include <iostream>


using namespace std;

class Chemin: public Individu
{
    public:

    Chemin(){dim_=0;val_= NULL;fit_=0;}
    Chemin(int, const Matrice &); //constructeur dimensions et Matrice le Chemin choisi est 0,1,2,...,n
    Chemin(const Chemin &); //constructeur par copie



    bool operator==(const Chemin &); //test d'égalité
    bool operator !=(const Chemin &); //test de différence

    double fitness(const Matrice &);

    int dim() const; //acces a la dimension
    double fit() const;
    int & operator()(int) const;
    void set(int i, int k, const Matrice &); // modifie la valuer i du Chemin qui prend la valuer k

    bool admissible(); //fonction qui vérifie que l'on passe une et une seule fois par chauqe ville

    Chemin mutation();


};

Chemin operator *(const Chemin &Chemin1, const Chemin &Chemin2);

ostream & operator<<(ostream &, const Chemin &); //sortie
istream & operator>>(istream &, Chemin &); //entree

#endif



