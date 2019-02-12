#include <cstdlib>
#include <iostream>
#include "chemin.hpp"
#include "matrice_g.hpp"

using namespace std;

int main(){
    matrice B = matrice();
    chemin V = chemin();
    V.dim_= 2;
    V.val_= new int[2];
    V.val_[0] = 0;
    V.val_[1] = 1;
    chemin chemin_mute =  mutation(V);

    return 0;
}