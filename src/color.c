#include "color.h"

t_vec3 ray_color(t_ray r)
{
	t_vec3 unit_direction;
	double a;
	t_vec3 white;
	t_vec3 blue;
	t_vec3 term1;
	t_vec3 term2;

	if(hit_sphere(vec3(0, 0, -1), 0.5, r))
		return vec3(1.0, 0.0, 0.0); // cor vermelha se o raio atingir a esfera

	unit_direction = vec3_unit_vector(r.dir);
	a = 0.5 * (unit_direction.y + 1.0);

	//cores base
	white = vec3(1.0, 1.0, 1.0);
	blue = vec3(0.5, 0.7, 1.0);

	term1 = vec3_mul(white, 1.0 - a);
	term2 = vec3_mul(blue, a);
	return vec3_add(term1, term2);
}
