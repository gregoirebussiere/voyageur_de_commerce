#ifndef population_H
#define population_H
#include<vector>
#include <cstdlib>
#include <iostream>
#include "chemin.hpp"
#include "individu.hpp"



using namespace std;

class Population
{
    private:
    int card;
    int len_ind;
    vector<Individu> individus_;
    float prop_mut;
    float prop_cross;
    float prop_cons;


    public:

    Population(){card=0;len_ind=0;prop_mut=0; prop_cross=0;};
    Population(int len,int len_ind,float mut,float cons,float cross, const Matrice &);
    Individu acces(int ind) const;

    void tri();



    void mutation_pop(const Matrice &M);

    void crossover_pop(const Matrice &M);
    int acces_taille() const;
    void set_Individu(int i, Individu I);

    void add_alea(const Matrice &M);

    void tronque();


};


ostream & operator<<(ostream &os, const Population &P);
#endif
