/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:11:23 by rel-mora          #+#    #+#             */
/*   Updated: 2024/06/15 16:41:10 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_error(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_func(t_indx *var)
{
	int	i;

	i = 0;
	while (var->map[i])
		free(var->map[i++]);
	free(var->map);
}
