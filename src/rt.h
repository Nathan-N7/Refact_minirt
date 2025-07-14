#ifndef RT_H
# define RT_H

# include "../lib/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include "vec3.h"
# include "color.h"
# include "ray.h"

# define TRUE 1
# define FALSE 0

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_camera
{
	t_vec3 camera_center;
	double focal_length;
	double viewport_height;
	double viewport_width;
	t_vec3 viewport_u;
	t_vec3 viewport_v;
	double pixel_du_x;
	double pixel_dv_y;
	t_vec3 upper_left_corner;
}	t_camera;

typedef enum e_hittable_type
{
	SPHERE // Esfera
	// + outras futuras primitivas
}	t_hittable_type;


//mlx
void	init_mlx(t_mlx *mlx, int width, int height);
int		destroy(t_mlx *mlx);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		rgb_to_int(int r, int g, int b);

//camera
t_camera *init_camera(double aspect_ratio, int image_width, int image_height);
t_vec3 get_pixel00(t_camera *camera);
void destroy_camera(t_camera *camera);
t_vec3 get_pixel_center(t_camera *camera, int i, int j, t_vec3 pixel00);

double	hit_sphere(t_vec3 center, double radius, t_ray r);

#endif
