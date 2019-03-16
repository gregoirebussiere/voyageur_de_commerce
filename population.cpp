#include "population.hpp"
#include <algorithm>
#include <iostream>
using namespace std;



Population::Population(int len,int len_ind,float mut,float cons,float cross, const Matrice &M)
{
    card = len;

    individus_ = vector<Individu>(len);
    prop_mut = mut;
    prop_cons = cons;
    prop_cross = cross;
    for (int i=0;i<card;i++){
       Individu I=Individu(len_ind,M);
       individus_[i]=I;
    }

    for (int i=0;i<card;i++)
    {
        cout<< i<< " "<<individus_[i]<<endl;
    }
}

Individu Population::acces(int ind) const
{
    return(individus_[ind]);
}

void Population::tri()
{
  std::sort(individus_.begin(),individus_.end());
}

