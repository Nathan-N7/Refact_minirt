#include "hittable.h"

int hit_world(t_hittable **world, int world_size, t_ray r,t_interval t_range, t_hit_record *rec)
{
	t_hit_record	tmp;
	int	hit_any = 0;
	int i;
	i = 0;
	while (i < world_size)
	{
		if (world[i]->hit(world[i]->obj, r, t_range.min, t_range.max, &tmp))
		{
			hit_any = 1;
			t_range.max = tmp.t;
			*rec = tmp;
		}
		i++;
	}
	return (hit_any);
}

void    set_face_normal(t_hit_record *rec, t_ray r, t_vec3 outward_normal)
{
	if (vec3_dot(r.dir, outward_normal) < 0.0)
	{
		rec->front_face = 1;
		rec->normal = outward_normal;
	}
	else
	{
		rec->front_face = 0;
		rec->normal = vec3_neg(outward_normal);
	}
}
