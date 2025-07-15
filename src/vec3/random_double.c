#include "vec3.h"

double  random_double(void)
{
    /* rand() devolve inteiro em [0,RAND_MAX], então
       dividimos por (RAND_MAX + 1.0) para obter [0,1) */
    return ((double)rand() / (RAND_MAX + 1.0));
}