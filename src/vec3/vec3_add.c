#include "vec3.h"
#include <math.h>
#include <stdlib.h>

t_vec3 vec3_add(t_vec3 a, t_vec3 b)
{
    return (vec3(a.x + b.x, a.y + b.y, a.z + b.z));
}