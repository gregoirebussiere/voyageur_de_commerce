#include "matrice_g.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

Matrice::Matrice(int n, double v)
{
    if(n<=0) return;
    dim_=n; val_=NULL;
    int d=dim_*dim_;
    val_=new double[d];
    for(int k=0;k<d;k++) val_[k]=v;

}

Matrice::Matrice(const Matrice &V)
{
    dim_=V.dim_; val_=NULL;
    if(dim_<=0) return;
    int d=dim_*dim_;
    val_=new double[d];
    for(int k=0; k<d;k++) val_[k]=V.val_[k];
}

Matrice::~Matrice()
{
    if(val_!=NULL) delete [] val_;
}

int Matrice::dim() const
{
    return dim_;
}

bool Matrice::operator==(const Matrice&V)
{
    if(dim_!=V.dim_) return false;

    double *pM=val_;
    double *pV=V.val_;
    int d=dim_*dim_;
    for(int i=1;i<=d;i++,pM++,pV++) if ((*pM)!=(*pV)) return false;
    return true;
}

bool Matrice::operator!=(const Matrice &V)
{
    return !((*this)==V);
}

double & Matrice::operator()(int i,int j) const
{
    return val_[(j-1)*dim_+i-1];
}

ostream & operator<<(ostream &os, const Matrice &M)
{
    os<<"graphe de dimensions "<<M.dim_<<endl;
    for(int i=1; i<=M.dim_;i++)
    {
        for(int j=1;j<=M.dim_;j++) os<<M(i,j)<<" ";
        os<<endl;
    }
    os<<endl;
    return os;
}

istream & operator>>(istream &is, const Matrice &M)
{

    for(int i=1; i<=M.dim_;i++)
    {
        for(int j=1;i<=M.dim_;j++) is>>M(i,j);
    }
    return is;
}
