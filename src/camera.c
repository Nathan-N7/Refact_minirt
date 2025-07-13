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
