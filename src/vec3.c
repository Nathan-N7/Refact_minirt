#include "vec3.h"
#include <math.h>
#include <stdlib.h>

// Construtor
t_vec3 vec3(double x, double y, double z) {
    t_vec3 v = {x, y, z};
    return v;
}

// Operações básicas
t_vec3 vec3_add(t_vec3 a, t_vec3 b) {
    return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

t_vec3 vec3_sub(t_vec3 a, t_vec3 b) {
    return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

t_vec3 vec3_neg(t_vec3 v) {
    return vec3(-v.x, -v.y, -v.z);
}

t_vec3 vec3_mul(t_vec3 v, double t) {
    return vec3(v.x * t, v.y * t, v.z * t);
}

t_vec3 vec3_div(t_vec3 v, double t) {
    return vec3(v.x / t, v.y / t, v.z / t);
}

// Operações in-place
void vec3_add_inplace(t_vec3 *a, t_vec3 b) {
    a->x += b.x;
    a->y += b.y;
    a->z += b.z;
}

void vec3_mul_inplace(t_vec3 *v, double t) {
    v->x *= t;
    v->y *= t;
    v->z *= t;
}

t_vec3 vec3_mult_vecs(t_vec3 a, t_vec3 b) {
    return vec3(a.x * b.x, a.y * b.y, a.z * b.z);
}

void vec3_div_inplace(t_vec3 *v, double t) {
    vec3_mul_inplace(v, 1.0 / t);
}

// Produto escalar e vetorial
double vec3_dot(t_vec3 a, t_vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

t_vec3 vec3_cross(t_vec3 a, t_vec3 b) {
    return vec3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}

// Comprimento e normalização
double vec3_length_squared(t_vec3 v) {
    return v.x*v.x + v.y*v.y + v.z*v.z;
}

double vec3_length(t_vec3 v) {
    return sqrt(vec3_length_squared(v));
}

t_vec3 vec3_unit_vector(t_vec3 v) {
    return vec3_div(v, vec3_length(v));
}

t_vec3 random_vec3(void)
{
    return vec3(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX);
}

t_vec3 random_vec3_in_range(double min, double max)
{
    return vec3(
        min + (rand() / (double)RAND_MAX) * (max - min),
        min + (rand() / (double)RAND_MAX) * (max - min),
        min + (rand() / (double)RAND_MAX) * (max - min)
    );
}

t_vec3 random_unit_vector(void)
{
    while(1)
    {
        t_vec3 v = random_vec3_in_range(-1.0, 1.0);
        double lensq = vec3_length_squared(v);
        if (1e-160 < lensq && lensq <= 1.0)
            return vec3_div(v, sqrt(lensq));
    }

}

t_vec3 random_on_hemisphere(t_vec3 normal)
{
    t_vec3 in_unit_sphere = random_vec3_in_range(-1.0, 1.0);
    if (vec3_length_squared(in_unit_sphere) >= 1.0)
        return random_on_hemisphere(normal);

    if (vec3_dot(in_unit_sphere, normal) > 0.0)
        return in_unit_sphere;
    else
        return vec3_neg(in_unit_sphere);
}

int vec3_near_zero(t_vec3 v)
{
    const double  s = 1e-8;

    if (fabs(v.x) < s
     && fabs(v.y) < s
     && fabs(v.z) < s)
        return (1);
    return (0);
}

t_vec3  vec3_reflect(t_vec3 v, t_vec3 n)
{
    return vec3_sub(v,
           vec3_mul(n, 2.0 * vec3_dot(v, n)));
}
