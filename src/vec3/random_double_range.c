#include "vec3.h"

double  random_double_range(double min, double max)
{
    /* estende [0,1) para [min,max) */
    return (min + (max - min) * random_double());
}