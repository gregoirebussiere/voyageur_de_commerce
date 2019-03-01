#ifndef individu_H
#define individu_H
#include <cstdlib>
#include <iostream>

using namespace std;

class Individu
{
    protected:

    int dim_;
    int *val_;
    double fit_;


    public:

    Individu(){};
    Individu(int dim, int *val){};
    virtual ~Individu(){if(val_!=NULL) delete [] val_;}
    //virtual Individu* mutation() = 0;
};
#endif
