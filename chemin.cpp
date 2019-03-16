#include "individu.hpp"
#include "chemin.hpp"


using namespace std;

Chemin::Chemin(int n, const Matrice &M) : Individu(n)
{
    for(int k=0;k<dim_;k++) val_[k]=k;
    fit_=fitness(M);

}

Chemin Chemin::rand_perm(const Matrice &M)
{
    for (int i=dim_-1;i>=0;i--){
        int r=rand()%(i+1);
        int v=val_[r];
        val_[r]=val_[i];
        val_[i]=v;
    };
    Chemin A=Chemin(*this);
    A.fitness(M);
    return(A);
}


Chemin Chemin::mutation(const Matrice &M)
{
    int gene_mute1 = rand() %dim_;
    int gene_mute2 = rand() % dim_;
    int temp =val_[gene_mute1];
    set(gene_mute1,val_[gene_mute2],M);
    set(gene_mute2,temp,M);
    Chemin A =Chemin(*this);
    A.fitness(M);
    return(A);
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



Chemin crossover(const Chemin &Chemin1, const Chemin &Chemin2, const Matrice &M) //on crée un nouvel individu à partir de deux chemins on commence par couper au mileieu
{   int limite=rand() % Chemin1.dim();

    Chemin NewC=Chemin(Chemin2);
    for(int i=0;i<limite;i++) NewC.val()[i]=Chemin1.val()[i];

    NewC.set_fitness(NewC.fitness(M));




     return(NewC);
}


