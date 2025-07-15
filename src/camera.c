#include "rt.h"

t_camera *init_camera(double aspect_ratio, int image_width, int image_height)
{
	t_camera *cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
		return NULL;

	cam->camera_center = vec3(0, 0, 0);
	cam->focal_length = 1.0;
	cam->viewport_height = 2.0;
	cam->viewport_width = cam->viewport_height * aspect_ratio;
	cam->viewport_u = vec3(cam->viewport_width / 2, 0, 0);
	cam->viewport_v = vec3(0, cam->viewport_height / 2, 0);
	cam->pixel_du_x = cam->viewport_width / (double)image_width;
	cam->pixel_dv_y = cam->viewport_height / (double)image_height;
	cam->upper_left_corner = vec3(-cam->viewport_u.x, cam->viewport_v.y, -cam->focal_length);
	cam->sample_per_pixel = 10; // Inicializa com 1 amostra por pixel
	cam->pixel_sample_scale = 1.0 / cam->sample_per_pixel;
	cam->max_depth = 50;


	return cam;
}

void destroy_camera(t_camera *camera)
{
	if (camera)
	{
		free(camera);
	}
}

void center_pixel(t_camera *camera, int pixel_x, int pixel_y, t_vec3 *pixel_center)
{
	if (!camera || !pixel_center)
		return;

	pixel_center->x = camera->upper_left_corner.x + (pixel_x + 0.5) * camera->pixel_du_x;
	pixel_center->y = camera->upper_left_corner.y - (pixel_y + 0.5) * camera->pixel_dv_y;
	pixel_center->z = camera->upper_left_corner.z;
}

t_vec3 get_pixel00(t_camera *camera)
{
	if (!camera)
		return vec3(0, 0, 0);

	return vec3_add(
		camera->upper_left_corner,
		vec3(camera->pixel_du_x * 0.5, camera->pixel_dv_y * 0.5, 0.0)
	);
}


t_vec3 get_pixel_center(t_camera *camera, int i, int j, t_vec3 pixel00)
{
	t_vec3 pixel_center;

	pixel_center = vec3_add(
		vec3_add(
			pixel00,vec3(camera->pixel_du_x * i, 0.0, 0.0)),

			vec3(0.0, -camera->pixel_dv_y * j, 0.0)
		);

	return pixel_center;
}

t_vec3  sample_square(void)
{
	double  dx = random_double() - 0.5;
	double  dy = random_double() - 0.5;

	return ((t_vec3){ dx, dy, 0.0 });
}

/*
** Constrói um raio que parte de cam->camera_center e atravessa
** o pixel (i,j), com jitter dentro do pixel.
*/
t_ray   get_ray(const t_camera *cam, int i, int j)
{
	t_vec3  offset      = sample_square();
	/* converte índice + jitter em deslocamento físico na imagem */
	double  u = ((double)i + offset.x) * cam->pixel_du_x;
	double  v = ((double)j + offset.y) * cam->pixel_dv_y;

	/* calcula a posição amostrada no plano da viewport */
	t_vec3  pixel_sample = vec3_add(
							vec3_add(
								cam->upper_left_corner,
								vec3(u, 0.0, 0.0)
							),
							vec3(0.0, -v, 0.0)
							);

	/* monta o raio: origem = centro da câmera; direção = pixel_sample - origem */
	return ray(
		cam->camera_center,
		vec3_sub(pixel_sample, cam->camera_center)
	);
}
