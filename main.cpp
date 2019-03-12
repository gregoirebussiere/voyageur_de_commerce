#include <cstdlib>
#include <iostream>
#include "chemin.hpp"
#include "matrice_g.hpp"
#include "villes.hpp"

using namespace std;

int main(){
    Chemin V;
    Matrice M = remplir_villesf("f_ville.txt");
    cout<<M<<endl;

    Chemin A = Chemin(3,M);
    cout<<A;

    Chemin B = Chemin(A);
    B.val()[0]=6;
    cout<<A;
    cout<<B;
    Chemin C=crossover(B,A,M);
    cout<<C;






    return 0;
}
