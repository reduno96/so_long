/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:54:17 by rel-mora          #+#    #+#             */
/*   Updated: 2024/06/01 14:11:49 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize_value(t_indx *var)
{
	var->mlx = NULL;
	var->texture = NULL;
	var->i = 0;
	var->j = 0;
	var->map = NULL;
	var->x = 0;
	var->y = 0;
	var->len = 0;
	var->img = NULL;
}
int	main(int argc, char **argv)
{
	t_indx	*var;

	var = malloc(sizeof(t_indx));
	ft_initialize_value(var);
	if (argc == 2)
	{
		var->map = ft_validate(argv[1]);
		ft_initialize(var);
	}
	else
		ft_put_error();
	free(var);
}
