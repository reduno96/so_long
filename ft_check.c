/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:10:04 by rel-mora          #+#    #+#             */
/*   Updated: 2024/06/13 12:04:59 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_file(char *argv)
{
	int	i;

	i = ft_strlen(argv) - 1;
	if (argv[i] != 'r')
		return (0);
	i--;
	if (argv[i] != 'e')
		return (0);
	i--;
	if (argv[i] != 'b')
		return (0);
	i--;
	if (argv[i] != '.')
		return (0);
	return (1);
}

char	**ft_check_map(char *argv, char **map)
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
			ft_put_error();
		joined = ft_join(joined, get_line);
		free(get_line);
		get_line = get_next_line(fd);
	}
	map = ft_split(joined, '\n');
	free(joined);
	if (!map)
		ft_put_error();
	return (map);
}

void	ft_check_char(char **map)
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
				ft_put_error();
			var.j++;
		}
		var.i++;
	}
}

int	ft_check_least(char **map, char c)
{
	t_indx	var;

	var.i = 0;
	while (map[var.i])
	{
		var.j = 0;
		while (map[var.i][var.j])
		{
			if (map[var.i][var.j] == c)
				return (1);
			var.j++;
		}
		var.i++;
	}
	return (0);
}

void	ft_check_all(char **map)
{
	if (!ft_check_least(map, 'C') || !ft_check_least(map, 'E')
		|| !ft_check_least(map, 'P'))
		ft_put_error();
}
