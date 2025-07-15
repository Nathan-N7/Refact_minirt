#include "vec3.h"

t_vec3 vec3_neg(t_vec3 v)
{
    return (vec3(-v.x, -v.y, -v.z));
}