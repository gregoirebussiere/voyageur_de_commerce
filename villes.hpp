
#include "matrice_g.hpp"
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>



using namespace std;


class villes
{
    public:
    std::string nom;
    double x;
    double y;
    int *voisins; //tableau d'entiers de toutes les villes vaut 1 si deux villes  sont  voisins 0 sinon

    villes & operator=(const villes & V1)
    {
        if(this==&V1) return *this;
        nom=V1.nom;
        x=V1.x;
        y=V1.y;
        voisins=V1.voisins;
        return *this;
    }



};


double distance_ville(villes V1, villes V2)
{
    double d=sqrt((V1.x-V2.x)*(V1.x-V2.x)+(V1.y-V2.y)*(V1.y-V2.y));
    return(d);
}


int indice_ville(std::string nom, villes *V, int taille)
{
    int resultat=-1;
    for(int i=0;i<taille;i++)
    {
        if(nom.compare(V[i].nom)==0) {resultat=i;}
    }
    return(resultat);
}

int est_voisin(int i,int j,villes *V)
{
  villes V_=V[i];
  return(V_.voisins[j]);
}


matrice gener_graphe(villes * V,int taille) //fonction qui genere une matrice à partir d'une liste de villes  , taille correspond au nombre de villes dans la graphe
{
    int n=taille;
    matrice M(n);
    for(int i=0;i<n;i++)
    {

      for(int j=0;j<n;j++)
      {
          if (est_voisin(i,j,V)==1)
          {
             double d=distance_ville(V[i],V[j]);
             M(i+1,j+1)=d;
             M(j+1,i+1)=d;// attetion les indcies des matrices et des valeurs des villes sont décalés d'ou  la necessité de mettre le +1, à changer possibilement
          }
          else
          {
              M(i+1,j+1)=-1;
              M(j+1,i+1)=-1;
          }

      }
    }
return(M);
}

matrice remplir_villes(int taille)
{
    villes *V= new villes[taille];
    for (int i=0;i<taille;i++)
    {
      std::string nom;
      double x;
      double y;
      cout<<"Nom de la ville "<<i<<" ?";
      cin>>nom;
      V[i].nom=nom;
      cout<<"x de la ville "<<i<<" ?";
      cin>>x;
      V[i].x=x;
      cout<<"y de la ville "<<i<<" ?";
      cin>>y;
      V[i].y=y;
      V[i].voisins= new int[taille];
      for(int j=0;j<taille;j++)
      {
          int vois;
          cout<<"La ville "<<j<<" est elle voisin de "<<i<<" ?";
          cin>>vois;
          V[i].voisins[j]=vois;

      }

    }

    matrice M1=gener_graphe(V,taille);

    return(M1);
}
