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
    /*
    Individu A=Individu(10,M);
    Individu B=Individu(10,M);
    cout<<A<<endl;
    cout<<B<<endl;

    A.set(2,1,M);
    A.set(3,1,M);
    A.set(4,1,M);
    A.set(5,1,M);


    cout<<A<<endl;



    cout<<C<<endl;

    */


   /*


   P.mutation_pop(M);

   cout<<P<<endl;

   P.tri();

   cout<<P<<endl;

   P.tronque();

   cout<<P<<endl;

   */




   int taille_boucle=100;
   int taille_pop=100;
   int taille_chemin=10;

   Population P=Population(taille_pop,taille_chemin,0.9,0.8,0.1,M);

   Population Best_pop=Population(taille_boucle,taille_chemin,0.5,0.8,0.5,M);

   for(int i=0; i<taille_boucle; i++)
   {
    P.mutation_pop(M);
    P.crossover_pop(M);
    P.tri();
    P.tronque();
    P.add_alea(M); //pr l'etape d'apres
    Best_pop.set_Individu(i,P.acces(1));
    }





    ofstream fichier("chemin_final1.txt", ios::out | ios::trunc);

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

                cout << "Erreur à l'ouverture !" << endl;





















    return 0;
}
