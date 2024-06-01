/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:02:07 by rel-mora          #+#    #+#             */
/*   Updated: 2024/06/01 15:31:17 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_texture(t_indx *var, char *path, int x, int y)
{
	var->texture[var->i][var->j] = mlx_load_png(path);
	var->img[var->i][var->j] = mlx_texture_to_image(var->mlx,
			var->texture[var->i][var->j]);
	if (mlx_image_to_window(var->mlx, var->img[var->i][var->j], x, y) < 0)
		ft_put_error();
}

void	ft_put_img(char *line, t_indx *var)
{
	var->j = 0;
	while (line[var->j])
	{
		if (line[var->j] == 'C' || line[var->j] == 'E' || line[var->j] == 'P')
			ft_load_texture(var, "./texture/grass.png", var->j * 32, var->i
				* 32);
		if (line[var->j] == '1')
			ft_load_texture(var, "./texture/wall.png", var->j * 32, var->i
				* 32);
		else if (line[var->j] == '0')
			ft_load_texture(var, "./texture/grass.png", var->j * 32, var->i
				* 32);
		else if (line[var->j] == 'P')
			ft_load_texture(var, "./texture/player_stand_right.png", var->j
				* 32, var->i * 32);
		else if (line[var->j] == 'E')
			ft_load_texture(var, "./texture/door.png", var->j * 32, var->i
				* 32);
		else if (line[var->j] == 'C')
			ft_load_texture(var, "./texture/elixir.png", var->j * 32, var->i
				* 32);
		var->j++;
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	(void)param;
	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");
	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("!");
}

void	ft_delete_all_imgs(t_indx *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= var->x)
	{
		while (j <= var->y)
		{
			mlx_delete_image(var->mlx, var->img[i][j]);
			mlx_delete_texture(var->texture[i][j]);
			j++;
		}
		i++;
	}
}

void	ft_initialize(t_indx *var)
{
	while (var->map[var->x])
	{
		var->y = ft_strlen(var->map[var->x]);
		var->x++;
	}
	var->len = var->x * var->y;
	var->mlx = mlx_init(var->y * 32, var->x * 32, "so_long_game", false);
	var->texture = malloc(sizeof(mlx_texture_t **) * var->x);
	var->img = malloc(sizeof(mlx_image_t **) * var->x);
	for (int i = 0; i < var->x; i++)
	{
		var->texture[i] = malloc(sizeof(mlx_texture_t *) * var->y);
		var->img[i] = malloc(sizeof(mlx_image_t *) * var->y);
	}
	while (var->map[var->i])
	{
		ft_put_img(var->map[var->i], var);
		var->i++;
	}
	mlx_key_hook(var->mlx, &my_keyhook, NULL);
	mlx_loop(var->mlx);
	ft_delete_all_imgs(var);
	mlx_terminate(var->mlx);
}
