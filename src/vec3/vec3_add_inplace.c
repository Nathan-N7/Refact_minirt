#include "vec3.h"

void vec3_add_inplace(t_vec3 *a, t_vec3 b)
{
    a->x += b.x;
    a->y += b.y;
    a->z += b.z;
}