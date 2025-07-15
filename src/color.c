#include "color.h"
#include "rt.h"


t_vec3 ray_color(t_ray r, t_hittable **world, int world_size, t_interval t_range, int depth)
{
    t_hit_record rec;

    if(depth <= 0)
        return vec3(0, 0, 0); // retorna preto se a profundidade máxima for atingida

    if(!hit_world(world, world_size, r, t_range, &rec))
        return vec3(0, 0, 0); // Cor de fundo se não houver interseção


    t_vec3 attenuation;
    t_ray scattered;
    t_vec3 emitted_color = rec.material->color_emited;
    if (!rec.material->scatter(rec.material, &r, &rec,&attenuation, &scattered))
        return emitted_color; // Retorna a cor emitida se não houver espalhamento

    t_vec3 scattered_color = vec3_mult_vecs(attenuation,ray_color(scattered, world, world_size, t_range, depth - 1));

    return vec3_add(emitted_color, scattered_color); // Retorna a cor emitida mais a cor espalhada

}
