/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:08:30 by rel-mora          #+#    #+#             */
/*   Updated: 2024/09/02 07:46:39 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hide_coin_instance(t_indx *var, mlx_image_t *coin, int player_x,
		int player_y)
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
			if (coin->instances[i].enabled == 1)
				var->count_coin++;
			coin->instances[i].enabled = 0;
			return ;
		}
		i++;
	}
}

void	ft_move_please(t_indx *var, char c)
{
	if (c == 'a')
	{
		var->imgs.player_g->instances->x -= 32;
		hide_coin_instance(var, var->imgs.elixir_g, var->j - 1, var->i);
	}
	else if (c == 'd')
	{
		var->imgs.player_g->instances->x += 32;
		hide_coin_instance(var, var->imgs.elixir_g, var->j + 1, var->i);
	}
	else if (c == 'w')
	{
		var->imgs.player_g->instances->y -= 32;
		hide_coin_instance(var, var->imgs.elixir_g, var->j, var->i - 1);
	}
	else if (c == 's')
	{
		var->imgs.player_g->instances->y += 32;
		hide_coin_instance(var, var->imgs.elixir_g, var->j, var->i + 1);
	}
	ft_print_moves(var);
	if (var->imgs.door_g->instances->x == var->imgs.player_g->instances->x
		&& var->imgs.door_g->instances->y == var->imgs.player_g->instances->y
		&& var->count_coin == var->imgs.elixir_g->count)
		exit(1);
}

void	ft_move_player(t_indx *var, char c)
{
	var->j = var->imgs.player_g->instances->x / 32;
	var->i = var->imgs.player_g->instances->y / 32;
	if (c == 'a')
	{
		if (var->map[var->i][var->j - 1] != '1')
			ft_move_please(var, c);
	}
	else if (c == 'd')
	{
		if (var->map[var->i][var->j + 1] != '1')
			ft_move_please(var, c);
	}
	else if (c == 'w')
	{
		if (var->map[var->i - 1][var->j] != '1')
			ft_move_please(var, c);
	}
	else if (c == 's')
	{
		if (var->map[var->i + 1][var->j] != '1')
			ft_move_please(var, c);
	}
}

void	ft_move(t_indx *var, char c)
{
	int	inst_ply_x;
	int	inst_ply_y;

	inst_ply_x = var->imgs.player_g->instances->x / 32;
	inst_ply_y = var->imgs.player_g->instances->y / 32;
	ft_move_player(var, c);
}
