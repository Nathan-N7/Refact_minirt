#include "vec3.h"
#include <math.h>
#include <stdlib.h>

// Construtor
t_vec3 vec3(double x, double y, double z)
{
    t_vec3 v = {x, y, z};
    return (v);
}