#include <iostream>
#include "matrice_g.hpp"
#include "chemin.hpp"
#include "villes.hpp"
#include <cstdlib>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
   //test de matrice
   matrice M(5);
   M(1,2)=5;
   M(1,3)=7;
   M(1,4)=3;
   M(1,5)=5;
   M(2,3)=-1;
   M(2,4)=-1;
   M(2,5)=9;
   M(3,4)=2;
   M(3,5)=-1;
   M(4,5)=1;

   for(int i=1;i<=M.dim_;i++)
   {
       for(int j=1;j<=M.dim_;j++) M(j,i)=M(i,j); //pour l'instant petit gain de temps pr symetriser la matrice
   }

   chemin C(5,M);



   C.set(1,0,M);
   C.set(2,1,M);
   C.set(3,4,M);
   C.set(4,3,M);
   C.set(5,2,M);





  /*
  matrice M1=remplir_villes(3);
  cout<<M1;
  */

  matrice M2=remplir_villesf("f_ville.txt");
  cout<<M2;







}
