#include "chemin.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

chemin::chemin(int n, const matrice &M)
{
    if(n<=0) return;
    dim_=n; val_=NULL;
    val_=new int[dim_];
    for(int k=1;k<=dim_;k++) val_[k]=k-1;
    //calcul de fitnees
    fit_=fitness(M);



}

chemin::chemin(const chemin &V, const matrice &M)
{
    dim_=V.dim_; val_=NULL;
    if(dim_<=0) return;
    val_=new int[dim_];
    for(int k=1; k<=dim_;k++) val_[k]=V.val_[k];
    fit_=fitness(M);


}

chemin::~chemin()
{
    if(val_!=NULL) delete [] val_;
}


chemin::mutation()
{
    gene_mute1 = rand() % dim_;
    gene_mute2 = rand() % dim_;
    val_[gene_mute1],val[gene_mute2] = val[gene_mute2],val[gene_mute1];
}


int chemin::dim() const
{
    return dim_;
}

double chemin::fit() const
{
    return fit_;
}

bool chemin::operator==(const chemin&V)
{
    if(dim_!=V.dim_) return false;

    int *pM=val_;
    int *pV=V.val_;
    for(int i=1;i<=dim_;i++,pM++,pV++) if ((*pM)!=(*pV)) return false;
    return true;
}

bool chemin::operator!=(const chemin &V)
{
    return !((*this)==V);
}

int & chemin::operator()(int i) const
{
    return val_[i];
}

ostream & operator<<(ostream &os, const chemin &V)
{
    os<<"chemin de taille "<<V.dim_<<endl;
    for(int i=1; i<=V.dim_;i++)
    {
        os<<V(i)<<" ";
    }
    os<<endl;
    os<<"chemin de longeur "<<V.fit_<<endl;
    return os;
}

istream & operator>>(istream &is, const chemin &V)
{

    for(int i=1; i<=V.dim_;i++)
    {
        is>>V(i);
    }
    return is;
}

double chemin::fitness(const matrice &M)
{
    if ((dim_<=0) || (M.dim_<=0))
    {
        cout<<"chemin ou matrice vide";
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
    S=S+M(val_[dim_]+1,val_[1]+1); //decalage entre indice de chemin et incdice dans la matrice
    fit_=S;
    return(fit_);
}

