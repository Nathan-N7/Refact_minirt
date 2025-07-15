/* interval.c */
#include "interval.h"

/* vazio: min = +inf, max = -inf */
const t_interval  g_interval_empty    = {INFINITY, -INFINITY};
/* universo: min = -inf, max = +inf */
const t_interval  g_interval_universe = {-INFINITY, INFINITY};

void    interval_init_empty(t_interval *i)
{
    i->min = INFINITY;
    i->max = -INFINITY;
}

void    interval_init(t_interval *i, double min, double max)
{
    i->min = min;
    i->max = max;
}

double  interval_size(const t_interval *i)
{
    return (i->max - i->min);
}

int     interval_contains(const t_interval *i, double x)
{
    return (i->min <= x && x <= i->max);
}

int     interval_surrounds(const t_interval *i, double x)
{
    return (i->min < x && x < i->max);
}

double  interval_clamp(const t_interval *i, double x)
{
    if (x < i->min)
        return (i->min);
    if (x > i->max)
        return (i->max);
    return (x);
}

