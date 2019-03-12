#ifndef MatriceH
#define MatriceH

#include <iostream>

//fichiers entête systeme

using namespace std;

//class matrice definition

class matrice
{
    public:
    int dim_; //dimension de la matrice
    double * val_; //tableau des valeurs


    matrice(): dim_(0), val_(NULL) {} //constructeur par défaut
    matrice(int , double v=-1.); //constructeur dimensions et val. intiale
    matrice(const matrice &); //constructeur par copie
    ~matrice(); //destructeur


    bool operator==(const matrice &); //test d'égalité
    bool operator !=(const matrice &); //test de différence

    int dim() const; //acces a la dimension
    double & operator()(int, int) const;
};


ostream & operator<<(ostream &, const matrice &); //sortie
istream & operator>>(istream &, matrice &); //entree


#endif
