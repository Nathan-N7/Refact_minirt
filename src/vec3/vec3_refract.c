#include "vec3.h"

t_vec3  vec3_refract(t_vec3 uv, t_vec3 n, double ref_index)
{
    double cos_theta;
    t_vec3 r_out_perp;
    t_vec3 r_out_parallel;
    double k;

    /* ângulo entre -uv e a normal (máximo 1) */
    cos_theta = fmin(vec3_dot(vec3_neg(uv), n), 1.0);
    /* componente perpendicular */
    r_out_perp = vec3_mul(
                     vec3_add(uv, vec3_mul(n, cos_theta)),
                     ref_index
                 );
    /* calcula o termo de normalização */
    k = 1.0 - vec3_length_squared(r_out_perp);
    /* componente paralela */
    r_out_parallel = vec3_mul(n, -sqrt(fabs(k)));
    /* soma perpendicular + paralela */
    return (vec3_add(r_out_perp, r_out_parallel));
}