#ifndef MATERIAL_H
# define MATERIAL_H

# include "vec3/vec3.h"
# include "ray.h"
# include "color.h"
/* forward declare para evitar ciclos */
typedef struct s_hit_record  t_hit_record;

typedef struct s_material   t_material;
typedef int (*t_scatter_fn)(const t_material *self,
                            const t_ray *r_in,
                            const t_hit_record *rec,
                            t_vec3 *attenuation,
                            t_ray *scattered);

/* “Base class” para todos os materiais */
struct s_material
{
    t_scatter_fn  scatter;  /* método virtual */
    t_vec3        albedo;   /* cor difusa ou refletância */
    double        fuzz;     /* para metal; ignorado em Lambertian */
	double		refractive_index; /* índice de refração, usado em materiais como vidro */
    t_vec3      color_emited;    /* cor do material, usada para renderização */
};

/* Construtores para as “subclasses” */
t_material *lambertian_create(t_vec3 albedo);
t_material *metal_create(t_vec3 albedo, double fuzz);
t_material *dielectric_create(double refractive_index);
t_material *diffuse_light_create(t_vec3 albedo);

/* Destrutor único */
void        material_destroy(t_material *m);

#endif /* MATERIAL_H */
