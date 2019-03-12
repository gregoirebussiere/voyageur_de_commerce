#ifndef population_H
#define population_H

#include <cstdlib>
#include <iostream>
#include "chemin.hpp"


using namespace std;

class population
{
    protected:
    int card;
    int len_ind;
    Individu *individus;
    float prop_mut;
    float prop_cross;
    float prop_cons;


    public:

    population(){card=0;len_ind=0;individus=NULL;prop_mut=0;prop_cross=0;prop_cons=0};
    population(int len,int len_ind,float mut,float cons,float cross);
    tri();
    tronque(prop_cons);
    mutation_pop(prop_mutation);
    crossover_pop(prop_cross);
}
#endif
