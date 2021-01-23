#include "cub3d.h"

void
	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void
	cub_image_painter(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x = 0;
	int		y = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 500, "POOP");
	img.img = mlx_new_image(mlx, 800, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	while (x < 800)
	{
		y = 0;
		while (y < 500)
		{
			if (x == 400 && y == 250)
				my_mlx_pixel_put(&img, y, x, 0x000000);
			else
				my_mlx_pixel_put(&img, x, y, 0x00FA9A);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
