#include "vec3.h"

t_vec3 random_vec3(void)
{
    return (vec3(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX));
}