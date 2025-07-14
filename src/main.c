#include "rt.h"



int rgb_to_int(int r, int g, int b) {
	return (r << 16) | (g << 8) | b;
}


// Verifica se o raio atinge a esfera
	// A equação da esfera é (p - c) . (p - c) = r^2
	// onde p é o ponto no raio, c é o centro da esfera e r é o raio da esfera
	// O discriminante deve ser >= 0 para haver interseção

	// (orig + t * dir - center) . (orig + t * dir - center) = radius^2
	// Expande e resolve para t
	// Se o discriminante for >= 0, há interseção
double hit_sphere(t_vec3 center, double radius, t_ray r)
{
	t_vec3 oc;
	double a,c,h, discriminant;
	/* vetor do centro da esfera até a origem do raio */
	oc = vec3_sub(center, r.orig);
	/* coeficientes da quadrática at² + bt + c = 0 */
	a = vec3_length_squared(ray_direction(r));
	h = vec3_dot(ray_direction(r), oc);
	c = vec3_length_squared(oc) - radius * radius;
	discriminant = h*h - a*c;
	if (discriminant < 0.0)
		return (-1.0);
	else
		return ((h - sqrt(discriminant)) / a); // retorna o menor t positivo
}


int main()
{
	t_mlx *mlx;
	t_camera *camera;
	int image_width;
	int image_height;
	int i;
	int j;
	t_ray r;
	t_vec3 pixel_center;
	t_vec3 ray_direction;
	t_vec3 pixel_color;
	double aspect_ratio;
	int packed_color;
	t_vec3 pixel00;

	mlx = malloc(sizeof(t_mlx));


	// Define a proporção da imagem
	aspect_ratio = 16.0/9.0; // Exemplo de proporção 16:9
	image_width = 800; // Largura da imagem
	image_height = (int)(image_width / aspect_ratio);
	if(image_height < 1)
		image_height = 1;

	// inicializa o mlx
	init_mlx(mlx, image_width, image_height);

	//inicializar a camera
	camera = init_camera(aspect_ratio, image_width, image_height);
	pixel00 = get_pixel00(camera);


	//loop para criar a imagem
	j = 0;
	while(j < image_height)
	 {
		ft_printf( "\rScanlines remaining: %d ", image_height - j);
		i = 0;
		while (i < image_width)
		{
			// posição do centro do pixel (i,j)
			pixel_center = get_pixel_center(camera, i, j, pixel00);

			//cria o raio da camera até o pixel
			ray_direction = vec3_sub(pixel_center, camera->camera_center);
			r = ray(camera->camera_center, ray_direction);

			pixel_color = ray_color(r);
			int ir = (int)(255 * pixel_color.x);
			int ig = (int)(255 * pixel_color.y);
			int ib = (int)(255 * pixel_color.z);

			packed_color = rgb_to_int(ir, ig, ib);

			// Define pixel (considera endian = 0 / little endian)
			my_mlx_pixel_put(mlx, i, j, packed_color);
			i++;
		}
		j++;
	}
	ft_printf("\nDone.\n");

	// Mostra imagem na janela
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);

	mlx_hook(mlx->win_ptr, 17, 0, destroy, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
