#include "color.h"
#include "rt.h"


t_vec3 ray_color(t_ray r, t_hittable **world, int world_size, t_interval t_range, int depth)
{
    t_hit_record rec;

    if(depth <= 0)
        return vec3(0, 0, 0); // retorna preto se a profundidade máxima for atingida

    if (hit_world(world, world_size, r, t_range, &rec))
    {
        t_vec3 attenuation;
        t_ray scattered;
        if (rec.material->scatter(rec.material, &r, &rec,
                                  &attenuation, &scattered))
        {
            return vec3_mult_vecs(attenuation,
                ray_color(scattered, world,
                          world_size, t_range, depth - 1));
        }
        return vec3(0,0,0); // retorna preto se não houver espalhamento
    }
    // fundo gradient
    {
        t_vec3 unit = vec3_unit_vector(r.dir);
        double t = 0.5 * (unit.y + 1.0);
        return vec3_add(
            vec3_mul(vec3(1,1,1), 1.0 - t),
            vec3_mul(vec3(0.5,0.7,1.0), t)
        );
    }
}
