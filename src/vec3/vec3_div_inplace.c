#include "vec3.h"
#include <math.h>
#include <stdlib.h>

void vec3_div_inplace(t_vec3 *v, double t)
{
    vec3_mul_inplace(v, 1.0 / t);
}