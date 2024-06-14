/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:08:30 by rel-mora          #+#    #+#             */
/*   Updated: 2024/06/14 22:08:43 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_indx *var, int i, int j)
{
	var->map[i][j] = '0';
	var->map[i][j - 1] = 'P';
	var->imgs.player_g->instances->x -= 32;
}

void	ft_move_down(t_indx *var, int i, int j)
{
	var->map[i][j] = '0';
	var->map[i][j + 1] = 'P';
	var->imgs.player_g->instances->x += 32;
}

void	ft_move_left(t_indx *var, int i, int j)
{
	var->map[i][j] = '0';
	var->map[i - 1][j] = 'P';
	var->imgs.player_g->instances->y -= 32;
}

void	ft_move_right(t_indx *var, int i, int j)
{
	var->map[i][j] = '0';
	var->map[i + 1][j] = 'P';
	var->imgs.player_g->instances->y += 32;
}

void	ft_move_player(t_indx *var, char c)
{
	int	i;
	int	j;

	j = var->imgs.player_g->instances->x / 32;
	i = var->imgs.player_g->instances->y / 32;
	if (c == 'a')
	{
		if (var->map[i][j - 1] != '1')
			ft_move_up(var, i, j);
	}
	else if (c == 'd')
	{
		if (var->map[i][j + 1] != '1')
			ft_move_down(var, i, j);
	}
	else if (c == 'w')
	{
		if (var->map[i - 1][j] != '1')
			ft_move_left(var, i, j);
	}
	else if (c == 's')
	{
		if (var->map[i + 1][j] != '1')
			ft_move_right(var, i, j);
	}
}
