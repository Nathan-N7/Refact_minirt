#ifndef COLOR_H
# define COLOR_H

# include "vec3/vec3.h"
# include "ray.h"
# include "hittable.h"


typedef struct s_hittable t_hittable;

typedef t_vec3 color;


t_vec3 ray_color(t_ray r, t_hittable **world, int world_size, t_interval t_range, int depth);

#endif
