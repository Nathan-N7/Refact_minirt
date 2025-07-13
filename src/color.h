#ifndef COLOR_H
# define COLOR_H

# include "vec3.h"
# include "ray.h"
# include "rt.h"

typedef t_vec3 color;


t_vec3 ray_color(t_ray r);

#endif
