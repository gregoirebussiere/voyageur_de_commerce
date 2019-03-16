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
    /*
    tronque(prop_cons);
    mutation_pop(prop_mutation);
    crossover_pop(prop_cross);
    */
};
#endif
