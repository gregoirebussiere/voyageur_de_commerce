#include "individu.hpp"
#include "chemin.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

Chemin::Chemin(int n, const Matrice &M)
{
    if(n<=0) return;
    dim_=n; val_=NULL;
    val_=new int[dim_];
    for(int k=1;k<=dim_;k++) val_[k]=k-1;
    fit_=fitness(M);

}

Chemin::Chemin(const Chemin &V)
{
    dim_=V.dim(); val_=NULL;
    if(dim_<=0) return;
    val_=new int[dim_];
    for(int k=1; k<=dim_;k++) val_[k]=V.val_[k];
    fit_=V.fit_;

}



int Chemin::dim() const
{
    return dim_;
}

double Chemin::fit() const
{
    return fit_;
}


bool Chemin::operator==(const Chemin&V)
{
    if(dim_!=V.dim_) return false;

    int *pM=val_;
    int *pV=V.val_;
    for(int i=1;i<=dim_;i++,pM++,pV++) if ((*pM)!=(*pV)) return false;
    return true;
}

bool Chemin::operator!=(const Chemin &V)
{
    return !((*this)==V);
}

int & Chemin::operator()(int i) const
{
    return val_[i];
}

Chemin Chemin::mutation()
{
    Chemin A = Chemin(*this);
    int gene_mute1 = rand() % dim_;
    int gene_mute2 = rand() % dim_;
    A.val_[gene_mute1] = val_[gene_mute2];
    A.val_[gene_mute2] = val_[gene_mute1];
    return(A);
}


ostream & operator<<(ostream &os, const Chemin &V)
{
    os<<"Chemin de taille "<<V.dim()<<endl;
    for(int i=1; i<=V.dim();i++)
    {
        os<<V(i)<<" ";
    }
    os<<endl;
    os<<"Chemin de longeur "<<V.fit()<<endl;
    return os;
}

istream & operator>>(istream &is, const Chemin &V)
{

    for(int i=1; i<=V.dim();i++)
    {
        is>>V(i);
    }
    return is;
}

double Chemin::fitness(const Matrice &M)
{
    if ((dim_<=0) || (M.dim_<=0))
    {
        cout<<"Chemin ou Matrice vide";
        exit(-1);
    }
    double S=0.;
    for (int i=1;i<M.dim_;i++){
        if(M(val_[i]+1,val_[i+1]+1)<0)
        {
            return(-1);
        }

    S=S+M(val_[i]+1,val_[i+1]+1);

    }

    if(M(val_[dim_]+1,val_[1]+1)<0)
    {
     return(-1);
    }
    S=S+M(val_[dim_]+1,val_[1]+1); //decalage entre indice de Chemin et indice dans la Matrice
    fit_=S;
    return(fit_);
}


void Chemin::set(int i, int k, const Matrice &M)
{
    if ((i<0) || (i>dim_))
    {
        cout<<"indice en dehors du Chemin";
        exit(-1);
    }

    val_[i]=k;
    fit_=fitness(M);
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

