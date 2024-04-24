/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:01:24 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/24 11:06:29 by rel-mora         ###   ########.fr       */
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
	int		j;
	size_t	res;

	i = 0;
	j = 0;
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
	if (cpy_map[x][y] == 'C' || cpy_map[x][y] != '0' || cpy_map[x][y] != 'E' || cpy_map[x][y] != 'P')
		cpy_map[x][y] = '1';
	ft_flood_fill(cpy_map, x+1, y);
	ft_flood_fill(cpy_map, x-1, y);
	ft_flood_fill(cpy_map, x, y+1);
	ft_flood_fill(cpy_map, x, y-1);
}
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
}

void	ft_check_just(char **map)
{
	t_indx	var;

	var.i = 0;
	while (map[var.i])
	{
		var.j = 0;
		while (map[var.i][var.j])
		{
			if (map[var.i][var.j] != '0' && map[var.i][var.j] != '1'
				&& map[var.i][var.j] != 'P' && map[var.i][var.j] != 'E'
				&& map[var.i][var.j] != 'C')
			{
				ft_putstr_fd("Error", 2);
				exit(1);
			}
			var.j++;
		}
		var.i++;
	}
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
		ft_check_lgh(map);
		ft_player(map);

	}
	else
		ft_putstr_fd("Error", 2);
	return (map);
}
