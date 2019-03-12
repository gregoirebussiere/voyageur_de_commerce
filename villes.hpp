#ifndef Ville_H
#define Ville_H
#include "matrice_g.hpp"
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <fstream>




using namespace std;


class Ville
{
    public:
    std::string nom;
    double x;
    double y;
    int *voisins; //tableau d'entiers de toutes les Ville vaut 1 si deux Ville  sont  voisins 0 sinon

    Ville & operator=(const Ville & V1)
    {
        if(this==&V1) return *this;
        nom=V1.nom;
        x=V1.x;
        y=V1.y;
        voisins=V1.voisins;
        return *this;
    }



};


double distance_ville(Ville V1, Ville V2)
{
    double d=sqrt((V1.x-V2.x)*(V1.x-V2.x)+(V1.y-V2.y)*(V1.y-V2.y));
    return(d);
}


int indice_ville(std::string nom, Ville *V, int taille)
{
    int resultat=-1;
    for(int i=0;i<taille;i++)
    {
        if(nom.compare(V[i].nom)==0) {resultat=i;}
    }
    return(resultat);
}

int est_voisin(int i,int j,Ville *V)
{
  Ville V_=V[i];
  return(V_.voisins[j]);
}


Matrice gener_graphe(Ville * V,int taille) //fonction qui genere une matrice à partir d'une liste de Ville  , taille correspond au nombre de Ville dans la graphe
{
    int n=taille;
    Matrice M(n);
    for(int i=0;i<n;i++)
    {

      for(int j=0;j<n;j++)
      {
          if (est_voisin(i,j,V)==1)
          {
             double d=distance_ville(V[i],V[j]);
             M(i,j)=d;
             M(j,i)=d;// attetion les indcies des matrices et des valeurs des Ville sont décalés d'ou  la necessité de mettre le +1, à changer possibilement
          }
          else
          {
              M(i,j)=-1;
              M(j,i)=-1;
          }

      }
    }
return(M);
}

Matrice remplir_villes(int taille) // ici on utlise l'entréé de commande pour remplir toutes les données
{
    Ville *V= new Ville[taille];
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

    Matrice M1=gener_graphe(V,taille);
    for(int i=0;i<taille;i++)
    {
        delete [] V[i].voisins;
    }

    delete [] V;
    return(M1);
}



Matrice remplir_villesf(string nom_fichier)
{
     ifstream fichier(nom_fichier.c_str(), ios::in);
     if(fichier)
     {

         int taille;
         fichier>> taille;


         Ville *V= new Ville[taille];

        string nom;
        double x;
        double y;
        int vois;
         for (int i=0;i<taille;i++)
         {
             fichier >> nom >> x >> y;
             V[i].nom=nom;
             V[i].x=x;
             V[i].y=y;
             V[i].voisins= new int[taille];
             for (int j=0;j<taille;j++)
             {

                 fichier >> vois;
                 V[i].voisins[j]=vois;
             }
         }
         fichier.close();

    Matrice M1=gener_graphe(V,taille);
    for(int i=0;i<taille;i++)
    {
        delete [] V[i].voisins;
    }

    delete [] V;
    return(M1);
    }
}
#endif
