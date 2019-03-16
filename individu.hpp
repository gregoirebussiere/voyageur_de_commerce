#ifndef individu_H
#define individu_H
#include "matrice_g.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Individu
{
    protected:

    int dim_;
    vector<int> val_;
    double fit_;



    public:

    Individu(){};
    Individu(int dim);
    Individu(const Individu &);
    virtual ~Individu(){}
    Individu(int n, const Matrice &M);
    double fitness(const Matrice &);

    int dim() const;
    vector<int> val() const;
    double fit() const;
    int operator()(int) const;
    void set(int i, int k,const Matrice &M);

    bool operator==(const Individu &);
    bool operator !=(const Individu&);
    bool operator < (const Individu&);

    void set_fitness(double);
};


ostream & operator<<(ostream &, const Individu &);
istream & operator>>(istream &, Individu &);
#endif
