/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:01:24 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/24 15:00:16 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player(char **map)
{
	t_indx	var;
	char	*res;
	char	**cpy_map;

	var.i = 0;
	var.j = 0;
	res = NULL;
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
	char	*get_line;
	char	*joined;
	int		fd;

	map = NULL;
	joined = NULL;
	if (ft_check_file(argv) == 1)
	{
		fd = open(argv, O_RDONLY);
		get_line = get_next_line(fd);
		while (get_line != NULL)
		{
			joined = ft_join(joined, get_line);
			get_line = get_next_line(fd);
		}
		map = ft_split(joined, '\n');
		ft_check_just(map);
		ft_check_all(map);
		ft_check_lgh(map);
		ft_player(map);
	}
	else
		ft_putstr_fd("Error", 2);
	return (map);
}
