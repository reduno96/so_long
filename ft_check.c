/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:10:04 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/24 15:57:11 by rel-mora         ###   ########.fr       */
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

void	ft_check_all(char **map)
{
	if (!ft_check_least(map, 'C') || !ft_check_least(map, 'E'))
	{
		ft_putstr_fd("Error", 2);
		exit(1);
	}
}

int	ft_check_least(char **map, char c)
{
	t_indx var;

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