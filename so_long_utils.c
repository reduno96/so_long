/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:17:12 by rel-mora          #+#    #+#             */
/*   Updated: 2024/06/21 17:11:42 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_len_map(t_indx *var)
{
	var->x = 0;
	var->y = 0;
	while (var->map[var->x])
	{
		var->y = ft_strlen(var->map[var->x]);
		var->x++;
	}
	var->len = var->x * var->y;
}

void	ft_print_moves(t_indx *var)
{
	var->count_move++;
	ft_printf("%i \n", var->count_move);
}

void	ft_check_just(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	if (count > 1)
		ft_put_error("the map not valid");
}

void	ft_check_most(char **map)
{
	ft_check_just(map, 'E');
	ft_check_just(map, 'P');
}

int	ft_check_images(mlx_texture_t *img)
{
	if (img == NULL)
		ft_put_error("not found image");
	return (1);
}
