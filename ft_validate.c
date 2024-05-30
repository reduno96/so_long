/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:01:24 by rel-mora          #+#    #+#             */
/*   Updated: 2024/05/30 18:43:10 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_path(char **map)
{
	t_indx	var;
	char	**cpy_map;

	var.i = 0;
	var.j = 0;
	while (map[var.i])
	{
		var.j = 0;
		while (map[var.i][var.j])
		{
			if (map[var.i][var.j] == 'P')
			{
				var.x = var.i;
				var.y = var.j;
			}
			var.j++;
		}
		var.i++;
	}
	cpy_map = NULL;
	cpy_map = ft_duplicate_map(map, var.j);
	ft_flood_fill(cpy_map, var.x, var.y);
	ft_check_flood(cpy_map);
}

char	**ft_validate(char *argv)
{
	char	**map;
	int		i;

	i = 0;
	map = NULL;
	if (ft_check_file(argv) == 1)
	{
		ft_check_map(argv, &map);
		ft_check_char(map);
		ft_check_all(map);
		ft_check_lgh(map);
		ft_player_path(map);
		while (map[i])
			printf("%s\n", map[i++]);
	}
	else
		ft_put_error();
	return (map);
}
