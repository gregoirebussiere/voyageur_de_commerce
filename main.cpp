#include <cstdlib>
#include <ctime>
#include <iostream>
#include "chemin.hpp"
#include "matrice_g.hpp"
#include "villes.hpp"
#include "population.hpp"


using namespace std;


int main(){

    srand(time(NULL));
    Chemin V;
    Matrice M = remplir_villesf("f_ville10.txt");
    cout<<M<<endl;



   /*int taille_boucle=100;*/
   int taille_pop=100;
   int taille_chemin=10;

   Population P=Population(taille_pop,taille_chemin,0.5,0.8,0.5,M);

   Population Best_pop=Population(0,taille_chemin,0.5,0.8,0.5,M);

   int compt = 1;
   double best_fit = P.acces(1).fit();

   while (compt<50)
   {
    P.mutation_pop(M);
    P.crossover_pop(M);
    P.tri();
    P.tronque();
    P.add_alea(M);
    if (best_fit==P.acces(1).fit())
    {
        compt++;
    }
    else
    {
        compt=1;
    }
    best_fit = P.acces(1).fit(); //pr l'etape d'apres
    Best_pop.set_end_Individu(P.acces(1));
   }


   /*for(int i=0; i<taille_boucle; i++)
   {
    P.mutation_pop(M);
    P.crossover_pop(M);
    P.tri();
    P.tronque();
    P.add_alea(M); //pr l'etape d'apres
    Best_pop.set_Individu(i,P.acces(1));
    }*/




    ofstream fichier("chemin_final1.txt", ios::out | ios::trunc);

    if(fichier)
    {
    fichier<<taille_chemin<<endl;
    fichier<<Best_pop.acces_taille()<<endl;
    for(int i=0; i<Best_pop.acces_taille(); i++)
    {
        for(int j=0; j<taille_chemin; j++)
        {
            fichier<<Best_pop.acces(i)(j)<<" ";
        }
        fichier<<Best_pop.acces(i).fit()<<endl;
    }
     fichier.close();
    }

    else  // sinon

                cout << "Erreur à l'ouverture !" << endl;


    /*ofstream fichier("chemin_final1.txt", ios::out | ios::trunc);

    if(fichier)
    {
    fichier<<taille_chemin<<endl;
    fichier<<taille_boucle<<endl;
    for(int i=0; i<taille_boucle; i++)
    {
        for(int j=0; j<taille_chemin; j++)
        {
            fichier<<Best_pop.acces(i)(j)<<" ";
        }
        fichier<<Best_pop.acces(i).fit()<<endl;
    }
     fichier.close();
    }

    else  // sinon

                cout << "Erreur à l'ouverture !" << endl;*/





















    return 0;
}
