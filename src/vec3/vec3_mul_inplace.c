#include "vec3.h"
#include <math.h>
#include <stdlib.h>

void vec3_mul_inplace(t_vec3 *v, double t)
{
    v->x *= t;
    v->y *= t;
    v->z *= t;
}