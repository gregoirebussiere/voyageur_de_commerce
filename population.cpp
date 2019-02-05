#include "population.hpp"
#include "chemin.hpp"

#include <iostream>
using namespace std;

population::population()
{
    card = 0;
    *individus = [];
    prop_mut = 0;
    prop_cons = 0;
    prop_cross = 0;
}

population::population(float len,int len_ind,float mut,float cons,float cross)
{
    card = len;
    *individus = [];
    prop_mut = mut;
    prop_cons = cons;
    prop_cross = cross;
    for (i=0;i<card;i++){
        next = chemin(len_ind);
    }
    *individus
}
