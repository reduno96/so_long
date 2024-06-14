/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:17:12 by rel-mora          #+#    #+#             */
/*   Updated: 2024/06/14 16:32:35 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_len_map(t_indx *var)
{
	while (var->map[var->x])
	{
		var->y = ft_strlen(var->map[var->x]);
		var->x++;
	}
	var->len = var->x * var->y;
}

void	ft_where_is(t_indx *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (var->map[i])
	{
		j = 0;
		while (var->map[i][j])
		{
			if (var->map[i][j] == 'P')
			{
				var->p_idx = j;
				var->p_idy = i;
			}
			j++;
		}
		i++;
	}
}
