/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:03:45 by rel-mora          #+#    #+#             */
/*   Updated: 2024/06/01 13:35:22 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_wall(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i - 1][j])
	{
		if (map[i - 1][j] != '1')
		{
			ft_putstr_fd("Error", 2);
			exit(1);
		}
		j++;
	}
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1')
		{
			ft_putstr_fd("Error", 2);
			exit(1);
		}
		j++;
	}
}

void	ft_check_lgh(char **map)
{
	int		i;
	size_t	res;

	i = 0;
	res = 0;
	res = ft_strlen(map[i]);
	while (map[i])
	{
		if (res != ft_strlen(map[i]) || map[i][res - 1] != '1'
			|| map[i][0] != '1')
		{
			ft_putstr_fd("Error", 2);
			exit(1);
		}
		i++;
	}
	ft_check_wall(map, i);
}

void	ft_check_flood(char **cpy_map)
{
	t_indx	var;

	var.i = 0;
	var.j = 0;
	while (cpy_map[var.i])
	{
		var.j = 0;
		while (cpy_map[var.i][var.j])
		{
			if (cpy_map[var.i][var.j] == 'E' || cpy_map[var.i][var.j] == 'C')
			{
				ft_putstr_fd("Error", 2);
				exit(1);
			}
			var.j++;
		}
		var.i++;
	}
}

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
