#ifndef population_H
#define population_H

#include <stdlib>
#include <iostream>
#include "chemin.hpp" 


using namespace std;

class population
{
    private:
    int card;
    individu *individus;
    float prop_mut;
    float prop_cross;
    float prop_cons;


    public:
    
    population();
    population(int len,float mut,float cons,float cross);
    tri();
    tronque(prop_cons);
    insere(const chemin &);
    mutation(prop_mutation);
    crossover(prop_cross);
}