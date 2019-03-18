#include "population.hpp"
#include <algorithm>
#include <iostream>
#include<vector>


using namespace std;



Population::Population(int len,int nb,float mut,float cons,float cross, const Matrice &M)
{
    card = len;

    individus_ = vector<Individu>(len);
    len_ind=nb;
    prop_mut = mut;
    prop_cons = cons;
    prop_cross = cross;
    for (int i=0;i<card;i++){
       Individu I=Individu(len_ind,M);
       individus_[i]=I.rand_perm(M);
    }


}

Individu Population::acces(int ind) const
{
    return(individus_[ind]);
}

int Population::acces_taille() const
{
    return((individus_.size()));
}

void Population::set_Individu(int i, Individu I)
{
    individus_[i]=I;
}



void Population::mutation_pop(const Matrice &M)
{
  float taille_de_boucle_f=card*prop_mut;//nombre de personnes a muter
  int taille_de_boucle=floor(taille_de_boucle_f);
  for(int i=0; i<taille_de_boucle;i++)
  {
    int ind_personne=rand()%card;
   Individu I=individus_[ind_personne];
    Individu I_mut=I.mutation(M);
    individus_.push_back(I_mut);
  }
}

void Population::crossover_pop(const Matrice &M)
{
 float taille_de_boucle_f=card*prop_cross;//nombre de personnes a croiser
  int taille_de_boucle=floor(taille_de_boucle_f);
  for(int i=0; i<taille_de_boucle;i++)
  {
    int ind_personne1=rand()%card;
    int ind_personne2=rand()%card;
    Individu I1=individus_[ind_personne1];
    Individu I2=individus_[ind_personne2];
    Individu I_cross=crossover(I1,I2,M);
    individus_.push_back(I_cross);
  }
}

void Population::tri()
{
  std::sort(individus_.begin(),individus_.end());
}


ostream & operator<<(ostream &os, const Population &P)
{
    int taille=P.acces_taille();
    for(int i=0; i<taille;i++)
    {
        os<<" "<<"Individu numéro "<<i<<"     "<<P.acces(i)<<endl;
    }
    os<<endl;
    return os;
}

void Population::add_alea(const Matrice &M)
{
     float depart_de_boucle_f=card*prop_cons;//nombre de personnes a garder
     int depart_de_boucle=floor(depart_de_boucle_f);

     for(int i=depart_de_boucle; i<card;i++)
     {
       Individu I=Individu(len_ind,M);
       individus_[i]=I.rand_perm(M);

     }

}

void Population::tronque()
{
  int fin=individus_.size();
  while (fin!=card)
  {
   individus_.pop_back();
   fin=fin-1;
  }
}



