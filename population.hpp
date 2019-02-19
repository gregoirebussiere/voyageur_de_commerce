#ifndef population_H
#define population_H

#include <cstdlib>
#include <iostream>
#include "chemin.hpp" 


using namespace std;

class population
{
    private:
    int card;
    int len_ind;
    individu *individus;
    float prop_mut;
    float prop_cross;
    float prop_cons;


    public:
    
    population();
    population(int len,int len_ind,float mut,float cons,float cross);
    tri();
    tronque(prop_cons);
    mutation_pop(prop_mutation);
    crossover_pop(prop_cross);
}
