#include "vec3.h"
#include <math.h>
#include <stdlib.h>

t_vec3 vec3_cross(t_vec3 a, t_vec3 b)
{
    return (vec3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    ));
}