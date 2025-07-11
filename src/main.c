#include "rt.h"



int rgb_to_int(int r, int g, int b) {
	return (r << 16) | (g << 8) | b;
}


int main()
{
	t_mlx *mlx;
	mlx = malloc(sizeof(t_mlx));

	init_mlx(mlx);


	for (int y = 0; y < HEIGHT; y++) {
		fprintf(stderr, "\rScanlines remaining: %d ", HEIGHT - y);
		fflush(stderr);
		for (int x = 0; x < WIDTH; x++) {
			float r = (float)x / (WIDTH - 1);
			float g = (float)(HEIGHT - y - 1) / (HEIGHT - 1);
			float b = 0.25;
			int ir = (int)(255 * r);
			int ig = (int)(255 * g);
			int ib = (int)(255 * b);

			int color = rgb_to_int(ir, ig, ib);

			// Define pixel (considera endian = 0 / little endian)
			int offset = (y * mlx->line_length) + (x * (mlx->bits_per_pixel / 8));
			*(int *)(mlx->addr + offset) = color;
		}
	}

	// Mostra imagem na janela
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);

	mlx_hook(mlx->win_ptr, 17, 0, destroy, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}


