#include "vec3.h"

t_vec3 random_vec3_in_range(double min, double max)
{
    return (vec3(
        min + (rand() / (double)RAND_MAX) * (max - min),
        min + (rand() / (double)RAND_MAX) * (max - min),
        min + (rand() / (double)RAND_MAX) * (max - min)
    ));
}