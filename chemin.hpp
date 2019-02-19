#ifndef cheminH
#define cheminH
#include "matrice_g.hpp"
#include "individu.hpp"

#include <iostream>


using namespace std;

class chemin: public individu
{
    public:
    int dim_;
    int *val_;
    int fit_;

    chemin(): dim_(0), val_(NULL),fit_(0) {} //constructeur par défaut
    chemin(int, const matrice &); //constructeur dimensions et matrice le chemin choisi est 0,1,2,...,n
    chemin(const chemin &); //constructeur par copie
    ~chemin(); //destructeur


    bool operator==(const chemin &); //test d'égalité
    bool operator !=(const chemin &); //test de différence

    double fitness(const matrice &);

    int dim() const; //acces a la dimension
    double fit() const;
    int & operator()(int) const;
    void set(int i, int k, const matrice &); // modifie la valuer i du chemin qui prend la valuer k

    bool admissible(); //fonction qui vérifie que l'on passe une et une seule fois par chauqe ville

    chemin* mutation();


};

chemin operator *(const chemin &chemin1, const chemin &chemin2);

ostream & operator<<(ostream &, const chemin &); //sortie
istream & operator>>(istream &, chemin &); //entree






#endif
