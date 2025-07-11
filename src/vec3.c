#include "vec3.h"
#include <math.h>

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
