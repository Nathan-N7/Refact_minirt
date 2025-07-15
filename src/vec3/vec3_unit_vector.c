#include "vec3.h"

t_vec3 vec3_unit_vector(t_vec3 v)
{
    return (vec3_div(v, vec3_length(v)));
}