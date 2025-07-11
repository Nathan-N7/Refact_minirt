#ifndef RT_H
# define RT_H

# include "../lib/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>


#define WIDTH 256
#define HEIGHT 256

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

void	init_mlx(t_mlx *mlx);
int		destroy(t_mlx *mlx);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		rgb_to_int(int r, int g, int b);

#endif
