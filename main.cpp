#include <cstdlib>
#include <ctime>
#include <iostream>
#include "chemin.hpp"
#include "matrice_g.hpp"
#include "villes.hpp"

using namespace std;

int main(){
    Chemin V;
    Matrice M = remplir_villesf("f_ville.txt");
    cout<<M<<endl;

    Chemin A = Chemin(10,M);
    cout<<A<<endl;

    Chemin B = Chemin(A);

    B.set(6,3,M);
    B.set(8,1,M);
    B.set(1,9,M);

    cout<<B;


    srand(time(NULL));
    Chemin C=crossover(B,A,M);
    cout<<C<<endl;












    return 0;
}
