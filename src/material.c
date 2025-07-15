#include "material.h"
#include "ray.h"        /* t_ray, ray() */
#include "hittable.h"   /* t_hit_record, hit_world() */
#include "vec3.h"      /* vec3_reflect(), vec3_dot(), vec3_unit_vector() */
#include <stdlib.h>
#include <math.h>

/* ================= Lam­ber­ti­an ================= */

static int lambertian_scatter(const t_material *self,
                              const t_ray *r_in,
                              const t_hit_record *rec,
                              t_vec3 *attenuation,
                              t_ray *scattered)
{
    (void)r_in;
    t_vec3 dir = vec3_add(rec->normal, random_unit_vector());
    if (vec3_near_zero(dir))
        dir = rec->normal;
    *scattered  = ray(rec->p, dir);
    *attenuation = self->albedo;
    return 1;
}

t_material *lambertian_create(t_vec3 albedo)
{
    t_material *m = malloc(sizeof(*m));
    if (!m) return NULL;
    m->scatter = lambertian_scatter;
    m->albedo  = albedo;
    m->fuzz    = 0.0;
    return m;
}

/* =================== Metal =================== */

static int metal_scatter(const t_material *self,
                         const t_ray *r_in,
                         const t_hit_record *rec,
                         t_vec3 *attenuation,
                         t_ray *scattered)
{
    t_vec3 unit_in   = vec3_unit_vector(r_in->dir);
    t_vec3 reflected = vec3_reflect(unit_in, rec->normal);
    t_vec3 fuzz_vec  = vec3_mul(random_unit_vector(), self->fuzz);

    *scattered   = ray(rec->p, vec3_add(reflected, fuzz_vec));
    *attenuation = self->albedo;

    /* só aceita se for para fora */
    return (vec3_dot(scattered->dir, rec->normal) > 0.0);
    //return 1;
}

t_material *metal_create(t_vec3 albedo, double fuzz)
{
    t_material *m = malloc(sizeof(*m));
    if (!m) return NULL;
    m->scatter = metal_scatter;
    m->albedo  = albedo;
    /* garante 0 ≤ fuzz ≤ 1 */
    m->fuzz  = (fuzz < 1.0) ? fuzz : 1.0;
    return m;
}

/* ================ Destrutor ================= */

void material_destroy(t_material *m)
{
    free(m);
}
