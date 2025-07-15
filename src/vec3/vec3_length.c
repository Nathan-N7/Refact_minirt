#include "vec3.h"

double vec3_length(t_vec3 v)
{
    return (sqrt(vec3_length_squared(v)));
}