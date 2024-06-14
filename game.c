/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:02:07 by rel-mora          #+#    #+#             */
/*   Updated: 2024/06/14 22:17:00 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_indx *data)
{
	data->imgs.player_t = mlx_load_png("./texture/player_stand_right.png");
	data->imgs.wall_t = mlx_load_png("./texture/wall.png");
	data->imgs.grass_t = mlx_load_png("./texture/grass.png");
	data->imgs.door_t = mlx_load_png("./texture/door.png");
	data->imgs.elixir_t = mlx_load_png("./texture/elixir.png");
	data->imgs.player_g = mlx_texture_to_image(data->mlx, data->imgs.player_t);
	data->imgs.wall_g = mlx_texture_to_image(data->mlx, data->imgs.wall_t);
	data->imgs.grass_g = mlx_texture_to_image(data->mlx, data->imgs.grass_t);
	data->imgs.door_g = mlx_texture_to_image(data->mlx, data->imgs.door_t);
	data->imgs.elixir_g = mlx_texture_to_image(data->mlx, data->imgs.elixir_t);
	mlx_delete_texture(data->imgs.player_t);
	mlx_delete_texture(data->imgs.wall_t);
	mlx_delete_texture(data->imgs.grass_t);
	mlx_delete_texture(data->imgs.door_t);
	mlx_delete_texture(data->imgs.elixir_t);
}

void	ft_put_img(char *map, t_indx *var)
{
	var->j = 0;
	while (map[var->j])
	{
		if (map[var->j] == 'C' || map[var->j] == 'E' || map[var->j] == 'P'
			|| map[var->j] == '0')
			mlx_image_to_window(var->mlx, var->imgs.grass_g, var->j * 32, var->i
				* 32);
		if (map[var->j] == '1')
			mlx_image_to_window(var->mlx, var->imgs.wall_g, var->j * 32, var->i
				* 32);
		else if (map[var->j] == 'P')
		{
			var->p_idx = var->j;
			var->p_idy = var->i;
		}
		else if (map[var->j] == 'E')
			mlx_image_to_window(var->mlx, var->imgs.door_g, var->j * 32, var->i
				* 32);
		else if (map[var->j] == 'C')
			mlx_image_to_window(var->mlx, var->imgs.elixir_g, var->j * 32,
				var->i * 32);
		var->j++;
	}
}

void	hide_coin_instance(mlx_image_t *coin, int player_x, int player_y)
{
	int		coin_x;
	int		coin_y;
	size_t	i;

	i = 0;
	while (i < coin->count)
	{
		coin_x = coin->instances[i].x / 32;
		coin_y = coin->instances[i].y / 32;
		if (player_x == coin_x && player_y == coin_y)
		{
			coin->instances[i].enabled = 0;
			return ;
		}
		i++;
	}
}

int	there_is_coin(t_indx *var)
{
	int	k;
	int	t;

	t = 0;
	k = 0;
	while (var->map[k])
	{
		while (var->map[k][t])
		{
			if (var->map[k][t] == 'C')
			{
				printf("////-----%c", var->map[k][t]);
				return (1);
			}
			t++;
		}
		k++;
	}
	return (0);
}

void	ft_move(t_indx *var, char c)
{
	ft_move_player(var, c);
	ft_where_is(var);
	hide_coin_instance(var->imgs.elixir_g, var->p_idx, var->p_idy);
	var->count_move++;
	ft_printf("%i \n", var->count_move);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_indx	*var;
	int		i;

	i = 0;
	var = (t_indx *)param;
	ft_where_is(var);
	// if (there_is_coin(var))
	// 	exit(1);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE
			|| keydata.action == MLX_REPEAT))
		ft_move(var, 'a');
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE
			|| keydata.action == MLX_REPEAT))
		ft_move(var, 'd');
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE
			|| keydata.action == MLX_REPEAT))
		ft_move(var, 'w');
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE
			|| keydata.action == MLX_REPEAT))
		ft_move(var, 's');
}

void	ft_initialize(t_indx *var)
{
	int	i;

	i = 0;
	ft_len_map(var);
	if ((var->x * 32) >= 1440 || (var->y * 32) >= 2560)
		ft_put_error();
	var->mlx = mlx_init(var->y * 32, var->x * 32, "so_long_game", false);
	load_images(var);
	while (var->map[var->i])
	{
		ft_put_img(var->map[var->i], var);
		var->i++;
	}
	mlx_image_to_window(var->mlx, var->imgs.player_g, var->p_idx * 32,
		var->p_idy * 32);
	mlx_key_hook(var->mlx, &my_keyhook, var);
	mlx_loop(var->mlx);
	free_func(var);
	mlx_terminate(var->mlx);
}
