/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:17:12 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/24 11:12:55 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_duplicate_map(char **map, int j)
{
	char	**cpy_map;
	t_indx	var;

	var.i = 0;
	var.j = 0;
	cpy_map = malloc((j + 1) * sizeof(char *));
	while (map[var.i])
	{
		cpy_map[var.i] = ft_strdup(map[var.i]);
		var.i++;
	}
	cpy_map[var.i] = NULL;
	return (cpy_map);
}

void	ft_flood_fill(char **cpy_map, int x, int y)
{
	if (cpy_map[x][y] == '1')
		return ;
	if (cpy_map[x][y] == 'C' || cpy_map[x][y] != '0' || cpy_map[x][y] != 'E'
		|| cpy_map[x][y] != 'P')
		cpy_map[x][y] = '1';
	ft_flood_fill(cpy_map, x + 1, y);
	ft_flood_fill(cpy_map, x - 1, y);
	ft_flood_fill(cpy_map, x, y + 1);
	ft_flood_fill(cpy_map, x, y - 1);
}
