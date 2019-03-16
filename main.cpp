#include <cstdlib>
#include <ctime>
#include <iostream>
#include "chemin.hpp"
#include "matrice_g.hpp"
#include "villes.hpp"
#include "population.hpp"

using namespace std;

int main(){
    Chemin V;
    Matrice M = remplir_villesf("f_ville.txt");
    cout<<M<<endl;

    /*Individu A=Individu(10,M);
    Individu B=Individu(10,M);
    cout<<A<<endl;
    cout<<B<<endl;

    A.set(1,3,M);
    A.set(3,1,M);
    */

   Population P=Population(4,10,0.5,0.5,0.5,M);

















    return 0;
}
