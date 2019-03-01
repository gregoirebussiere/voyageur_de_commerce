
#include "matrice_g.hpp"
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string>
#include "villes.hpp"



using namespace std;


class Ville
{
    public:
    string nom;
    double x;
    double y;
    string *voisins;

};

double distance_ville(Ville V1, Ville V2)
{
    double d=sqrt((V1.x-V2.x)*(V1.x-V2.x)+(V1.y-V2.y)*(V1.y-V2.y));
    return(d);
}

int indice_ville(Ville *V, string nom) //fonction qui rend l'indice de la ville nommé nom dans la liste de Ville V
{
   int ind=-1;
   for (int i=1;i<=sizeof(V);i++)
   {
       if(V[i].nom==nom) ind=i;
   }
   return(ind);
}

Matrice gener_graphe(Ville * V) //fonction qui genere une matrice à partir d'une liste de Ville
{
    int n=sizeof(V);
    Matrice M(n);
    for(int i=1;i<=n;i++)
    {
      string *vois=V[i].voisins;
      for(int j=1;j<=sizeof(vois);j++)
      {
          int k=indice_ville(V,vois[j]);
          double d=distance_ville(V[i],V[k]);
          M(i,k)=d;
      }
    }

}

