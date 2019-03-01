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
    Chemin B = Chemin(A);
    cout<<B<<endl;
    cout<<B.mutation()<<endl;



    return 0;
}
