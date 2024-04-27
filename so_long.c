/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:54:17 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/27 17:49:40 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		i;
	t_data mlx;

	// (void) argv;
	i = 0;
	map = NULL;
	if (argc == 2)
	{
		map = ft_validate(argv[1]);

		mlx.mlx_ptr = mlx_init();
		mlx.mlx_win =  mlx_new_window(mlx.mlx_ptr, 1000,700, "Hello world!");
		mlx_loop(mlx.mlx_ptr);
	}
}

