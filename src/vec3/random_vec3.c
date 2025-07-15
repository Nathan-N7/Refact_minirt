#include "vec3.h"
#include <math.h>
#include <stdlib.h>

t_vec3 random_vec3(void)
{
    return vec3(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX);
}