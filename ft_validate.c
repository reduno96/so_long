/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:01:24 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/27 17:51:45 by rel-mora         ###   ########.fr       */
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
char **ft_check_inside(char *argv, char **map)
{
	char	*joined;
	char	*get_line;
	int		fd;

	joined = NULL;
	fd = open(argv, O_RDONLY);
	get_line = get_next_line(fd);
	while (get_line != NULL)
	{
		if (get_line[0] == '\n')
		{
			ft_putstr_fd("Error", 2);
			exit(1);
		}
		joined = ft_join(joined, get_line);
		get_line = get_next_line(fd);
	}

	map = ft_split(joined, '\n');
	if (!(map))
	{
		ft_putstr_fd("Error", 2);
		exit(1);
	}
	return map;
}

char	**ft_validate(char *argv)
{
	char	**map;
	// char	*get_line;
	char	*joined;
	// int		fd;

	// int i = 0;
	map = NULL;
	joined = NULL;
	if (ft_check_file(argv) == 1)
	{
		map = ft_check_inside(argv, map);
		ft_check_just(map);
		ft_check_all(map);
		ft_check_lgh(map);
		ft_player(map);
	}
	else
	{
		ft_putstr_fd("Error", 2);
		exit(1);
	}
	return (map);
}
