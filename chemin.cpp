#include "individu.hpp"
#include "chemin.hpp"


using namespace std;

Chemin::Chemin(int n, const Matrice &M) : Individu(n)
{
    for(int k=0;k<dim_;k++) val_[k]=k;
    fit_=fitness(M);

}











void Chemin::set(int i, int k, const Matrice &M)
{
    if ((i<0) || (i>dim_))
    {
        cout<<"indice en dehors du Chemin";
        exit(-1);
    }

    val_[i]=k;
}

bool Chemin::admissible()
{
    int *marquage= new int[dim_];
    for(int i=1;i<=dim_;i++) marquage[i]=0; //tableau qui marque si on est passé par une ville ou non, 0 pour non 1 pour oui
    for(int k=1;k<=dim_;k++)
    {
      if (marquage[val_[k]]==1)
            {
                return(false);
            }
      else
      {
          marquage[val_[k]]=1;
      }
    }
    return(true);
    delete [] marquage;
}





