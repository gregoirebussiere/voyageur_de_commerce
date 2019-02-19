
#include "matrice_g.hpp"
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string>



using namespace std;


class villes
{
    public:
    string nom;
    double x;
    double y;
    string *voisins;

};

double distance_ville(villes V1, villes V2)
{
    double d=sqrt((V1.x-V2.x)*(V1.x-V2.x)+(V1.y-V2.y)*(V1.y-V2.y));
    return(d);
}

int indice_ville(villes *V, string nom) //fonction qui rend l'indice de la ville nommé nom dans la liste de villes V
{
   int ind=-1;
   for (int i=1;i<=sizeof(V);i++)
   {
       if(V[i].nom==nom) ind=i;
   }
   return(ind);
}

matrice gener_graphe(villes * V) //fonction qui genere une matrice à partir d'une liste de villes
{
    int n=sizeof(V);
    matrice M(n);
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

