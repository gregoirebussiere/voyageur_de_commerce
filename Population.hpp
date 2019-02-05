#ifndef Population_H
#define Population_H

#include <stdlib>
#include <iostream>
#include "Chemin.hpp" 


using namespace std;

class Population
{
    private:
    int card;
    Individu *Individus;
    float prop_mut;
    float prop_cross;
    float prop_cons;


    public:
    
    Population();
    Population(card);
    tri();
    tronque(prop_cons);
    insere(const Chemin &);
    mutation(prop_mutation);
    crossover(prop_cross);
}