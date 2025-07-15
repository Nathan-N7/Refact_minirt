#include "vec3.h"
#include <math.h>
#include <stdlib.h>

t_vec3 vec3_div(t_vec3 v, double t)
{
    return (vec3(v.x / t, v.y / t, v.z / t));
}