#include "color.h"

t_vec3 ray_color(t_ray r)
{
	double t;
	t_vec3 N;
	t_vec3 unit_dir;
	double a;
	t_vec3 white = vec3(1.0, 1.0, 1.0);
	t_vec3 blue  = vec3(0.5, 0.7, 1.0);
	/* 1) testa interseção com esfera centrada em (0,0,-1), raio 0.5 */
	t = hit_sphere(vec3(0.0, 0.0, -1.0), 0.5, r);
	if (t > 0.0)
	{
		/* 2) ponto de interseção P = orig + t*dir */
		t_vec3 P = ray_at(r, t);
		/* 3) normal unitária em P */
		N = vec3_unit_vector(vec3_sub(P, vec3(0.0, 0.0, -1.0)));
		/* 4) mapeia N∈[−1,1] para cor em [0,1] */
		return (vec3_mul(vec3_add(N, vec3(1.0, 1.0, 1.0)), 0.5));
	}
	/* 5) gradiente de fundo: lerp entre branco e azul */
	unit_dir = vec3_unit_vector(r.dir);
	a = 0.5 * (unit_dir.y + 1.0);
	return (vec3_add(
		vec3_mul(white, 1.0 - a),
		vec3_mul(blue,           a)
	));
}
