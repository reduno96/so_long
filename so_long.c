/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:54:17 by rel-mora          #+#    #+#             */
/*   Updated: 2024/06/15 00:59:51 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize_value(t_indx *var)
{
	var->mlx = NULL;
	var->i = 0;
	var->j = 0;
	var->map = NULL;
	var->x = 0;
	var->y = 0;
	var->len = 0;
	var->count_move = 0;
	var->p_idx = 0;
	var->p_idy = 0;
	var->count_coin = 0;
}

int	main(int argc, char **argv)
{
	t_indx	var;

	ft_initialize_value(&var);
	if (argc == 2)
	{
		var.map = ft_validate(argv[1]);
		ft_initialize(&var);
	}
	else
		ft_put_error();
}
