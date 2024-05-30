/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:54:17 by rel-mora          #+#    #+#             */
/*   Updated: 2024/05/30 23:14:09 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;

	map = NULL;
	if (argc == 2)
	{
		map = ft_validate(argv[1]);
		ft_initialize(map);
	}
	else
		ft_put_error();
	ft_free_map(map);
}
// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>

// #define WIDTH 256
// #define HEIGHT 256

// // Exit the program as failure.
// static void	ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// // Print the window width and height.
// static void	ft_hook(void *param)
// {
// 	const mlx_t	*mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

// int	main(void)
// {
// 	mlx_t		*mlx;
// 	mlx_image_t	*img;

// 	// MLX allows you to define its core behaviour before startup.
// 	mlx_set_setting(MLX_MAXIMIZED, false);
// 	printf("MLX_MAXIMIZED: %d\n", 7);
// 	mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
// 	if (!mlx)
// 		ft_error();
// 	/* Do stuff */
// 	// Create and display the image.
// 	img = mlx_new_image(mlx, 256, 256);
// 	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
// 		ft_error();
// 	// Even after the image is being displayed, we can still modify the buffer.
// 	mlx_put_pixel(img, 0, 0, 0xFF0000FF);
// 	// Register a hook and pass mlx as an optional param.
// 	// NOTE: Do this before calling mlx_loop!
// 	mlx_loop_hook(mlx, ft_hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (0);
// }
