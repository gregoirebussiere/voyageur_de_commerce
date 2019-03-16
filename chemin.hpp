#ifndef cheminH
#define cheminH
#include "matrice_g.hpp"
#include "individu.hpp"




using namespace std;

class Chemin: public Individu
{
    public:

    Chemin(){}
    Chemin(int, const Matrice &); //constructeur dimensions et Matrice le Chemin choisi est 0,1,2,...,n

    int  operator()(int) const;
    void set(int i, int k,const Matrice &M); // modifie la valuer i du Chemin qui prend la valuer k

    bool admissible(); //fonction qui vérifie que l'on passe une et une seule fois par chauqe ville
    Chemin rand_perm(const Matrice &);
    Chemin mutation(const Matrice &);



};


Chemin crossover(const Chemin &Chemin1, const Chemin &Chemin2, const Matrice &);
ostream & operator<<(ostream &, const Chemin &); //sortie
istream & operator>>(istream &, Chemin &); //entree

#endif



