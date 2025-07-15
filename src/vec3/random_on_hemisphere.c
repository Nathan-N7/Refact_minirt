#include "vec3.h"

t_vec3 random_on_hemisphere(t_vec3 normal)
{
    t_vec3 in_unit_sphere = random_vec3_in_range(-1.0, 1.0);
    if (vec3_length_squared(in_unit_sphere) >= 1.0)
        return (random_on_hemisphere(normal));

    if (vec3_dot(in_unit_sphere, normal) > 0.0)
        return (in_unit_sphere);
    else
        return (vec3_neg(in_unit_sphere));
}