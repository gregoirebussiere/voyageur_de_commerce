#ifndef MatriceH
#define MatriceH

#include <iostream>

//fichiers entête systeme

using namespace std;

//class Matrice definition

class Matrice
{
    protected:
    int dim_; //dimension de la Matrice
    double * val_; //tableau des valeurs

    public:
    Matrice(): dim_(0), val_(NULL) {} //constructeur par défaut
    Matrice(int , double v=-1.); //constructeur dimensions et val. intiale
    Matrice(const Matrice &); //constructeur par copie
    ~Matrice(); //destructeur


    bool operator==(const Matrice &); //test d'égalité
    bool operator !=(const Matrice &); //test de différence

    int dim() const; //acces a la dimension
    double & operator()(int, int) const;
};


ostream & operator<<(ostream &, const Matrice &); //sortie
istream & operator>>(istream &, Matrice &); //entree


#endif
