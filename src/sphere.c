#include "sphere.h"
#include <stdlib.h>



int sphere_hit(
	void *obj,
	t_ray r,
	double t_min,
	double t_max,
	t_hit_record *rec
)
{
	t_sphere	*sp = obj;
	t_vec3	oc = vec3_sub(r.orig, sp->center);
	double	a = vec3_length_squared(r.dir);
	double	half_b = vec3_dot(r.dir, oc);
	double	c = vec3_length_squared(oc) - sp->radius * sp->radius;
	double	disc = half_b * half_b - a * c;
	double	sqrtd;
	double	root;
	if (disc < 0.0)
		return (0);
	sqrtd = sqrt(disc);
	root = ( -half_b - sqrtd ) / a;
	if (root < t_min || root > t_max)
	{
		root = ( -half_b + sqrtd ) / a;
		if (root < t_min || root > t_max)
			return (0);
	}
	rec->t = root;
	rec->p = ray_at(r, rec->t);
	/* normal “não orientada” */
	t_vec3 outward_normal = vec3_div(
		vec3_sub(rec->p, sp->center),
		sp->radius
	);
	/* orienta normal para frente ou verso */
	set_face_normal(rec, r, outward_normal);
	rec->material = sp->material;
		return (1);
}

/*
** Cria o t_sphere e o envelopa num t_hittable
*/
t_hittable *sphere_create(t_vec3 center, double radius, t_material *material)
{
	t_hittable *ht;

	ht = malloc(sizeof(*ht) + sizeof(t_sphere));
	if (!ht)
		return (NULL);
	ht->obj = (void *)(ht + 1);
	((t_sphere *)ht->obj)->center = center;
	((t_sphere *)ht->obj)->radius = radius;
	((t_sphere *)ht->obj)->material = material;
	ht->hit = sphere_hit;
	return (ht);
}
