#include "so_long.h"

void	ft_initialize(char **map)
{
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	t_indx			var;
	int				max_x;
	int				max_y;
	int				len;

	var.i = 0;
	var.j = 0;
	max_x = 0;
	max_y = 0;
	for (int i = 0; map[i]; i++)
	{
		len = strlen(map[i]);
		if (len > max_x)
			max_x = len;
		max_y++;
	}
	mlx = mlx_init(max_y * 32, max_x * 32, "so_long_game", false);
	texture = mlx_load_png("./texture/grass.png");
	img = mlx_texture_to_image(mlx, texture);
	while (map[var.i])
	{
		var.j = 0;
		while (map[var.i][var.j])
		{
			if (map[var.i][var.j] == '1')
				mlx_image_to_window(mlx, img, var.i * 32, var.j * 32);
			var.j++;
		}
		var.i++;
	}
	mlx_loop(mlx);
}
