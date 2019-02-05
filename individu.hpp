#include <stdlib>
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
    virtual mutation() = 0;
}
individu operator *(const individu &ind1, const individu &ind2);