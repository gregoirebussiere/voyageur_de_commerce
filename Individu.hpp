#include <stdlib>
#include <iostream>

using namespace std;

class Individu
{
    protected:
    int size;
    int *data;
    double fitness;

    Individu();
    Individu(int size, int *data);
    virtual ~Individu(){};

}