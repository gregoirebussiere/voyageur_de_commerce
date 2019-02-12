#include <cstdlib>
#include <iostream>

using namespace std;

class individu
{
    protected:
    int size;
    int *data;
    
    public:
    double fitness;

    individu();
    individu(int size, int *data);
    virtual ~individu();
    virtual individu* mutation() = 0;
};
