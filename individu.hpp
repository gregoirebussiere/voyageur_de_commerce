#include <cstdlib>
#include <iostream>

using namespace std;

class individu
{
    protected:
    int dim_;
    int *val_;
    
    public:
    double fit_;
    individu();
    individu(int size, int *data);
    virtual ~individu();
    virtual individu* mutation() = 0;
};
