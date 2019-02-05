#include "Population.hpp"
#include <iostream>
using namespace std;

Population::Population()
{
    card = 0;
    *Individus = [];
    prop_mut = 0;
    prop_cons = 0;
    prop_cross = 0;
}