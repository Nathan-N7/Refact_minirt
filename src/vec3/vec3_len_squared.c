#include "vec3.h"

double vec3_length_squared(t_vec3 v)
{
    return (v.x*v.x + v.y*v.y + v.z*v.z);
}