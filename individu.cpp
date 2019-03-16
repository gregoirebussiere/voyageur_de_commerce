#include "individu.hpp"



using namespace std;

Individu::Individu(int dim){
    dim_=dim;
    if(dim<=0) return;
    val_=vector<int>(dim_);

}

Individu::Individu(const Individu &V)
{
    dim_=V.dim();
    if(dim_<=0) return;
    val_= vector<int>(dim_);

    for(int k=0; k<dim_; k++)
      {  val_[k]=V.val_[k];}
    fit_=V.fit_;
}

double Individu::fitness(const Matrice &M)
{
    if ((dim_<0) || (M.dim()<0))
    {
        cout<<"Chemin  ou Matrice vide";
        exit(-1);
    }
    double S=0.;
    for (int i=0;i<dim_-1;i++){
        if(M(val_[i],val_[i+1])<0)
        {
            return(-1);
        }

    S=S+M(val_[i],val_[i+1]);

    }

    if(M(val_[dim_-1],val_[0])<0)
    {
     return(-1);
    }
    S=S+M(val_[dim_-1],val_[0]); //decalage entre indice de Chemin et indice dans la Matrice
    fit_=S;
    return(fit_);
}

Individu::Individu(int n, const Matrice &M) : Individu(n)
{
    for(int k=0;k<dim_;k++) val_[k]=k;
    fit_=fitness(M);

}

int Individu::dim() const
{
    return dim_;
}

double Individu::fit() const
{
    return fit_;
}

vector<int> Individu::val() const
{
    return(val_);
}


bool Individu::operator==(const Individu&V)
{
    if(dim_!=V.dim_) return false;

    for(int i=0;i<dim_;i++)
    {
        if(val_[i]!=V.val_[i]) return false;
     }
    return true;
}

bool Individu::operator!=(const Individu &V)
{
    return !((*this)==V);
}

int  Individu::operator()(int i) const
{
    return val_[i];
}

void Individu::set(int i, int k,const Matrice &M)
{
    if((i<0)|| (i>dim_))
    {
        cout<<"indice en dehors de l'Individu";
        exit(-1);
    }

    val_[i]=k;
    fit_=fitness(M);
}

void Individu::set_fitness(double x)
{
    double fit_=x;
}

bool Individu::operator<(const Individu &V)
{
   return(fit_<V.fit_);
}


ostream & operator<<(ostream &os, const Individu &V)
{
    os<<"Chemin de taille "<<V.dim()<<endl;
    for(int i=0; i<V.dim();i++)
    {
        os<<V(i)<<" ";
    }
    os<<endl;
    os<<"Fitness"<<V.fit()<<endl;
    return os;
}

istream & operator>>(istream &is, const Individu &V)
{

    for(int i=0; i<V.dim();i++)
    {
        is>>V(i);
    }
    return is;
}



