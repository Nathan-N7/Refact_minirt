#include "vec3.h"

t_vec3 vec3_mul(t_vec3 v, double t)
{
    return (vec3(v.x * t, v.y * t, v.z * t));
}