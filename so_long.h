/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:07:39 by rel-mora          #+#    #+#             */
/*   Updated: 2024/06/14 22:12:52 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_images
{
	mlx_texture_t	*wall_t;
	mlx_image_t		*wall_g;
	mlx_texture_t	*grass_t;
	mlx_image_t		*grass_g;
	mlx_texture_t	*player_t;
	mlx_image_t		*player_g;
	mlx_texture_t	*door_t;
	mlx_image_t		*door_g;
	mlx_texture_t	*elixir_t;
	mlx_image_t		*elixir_g;

}					t_images;

typedef struct s_indx
{
	char			**map;
	mlx_t			*mlx;
	t_images		imgs;
	int				count_move;
	int				i;
	int				j;
	int				x;
	int				y;
	int				len;
	int				p_idx;
	int				p_idy;

}					t_indx;

int					ft_check_file(char *argv);
void				ft_check_wall(char **map, int i);
int					ft_check_least(char **map, char c);
void				ft_check_lgh(char **map);
void				ft_check_char(char **map);
void				ft_check_all(char **map);
void				ft_check_flood(char **cpy_map);
char				**ft_check_map(char *argv, char **map);

void				ft_len_map(t_indx *var);
void	ft_move_player(t_indx *var, char c);
void				ft_player_path(char **map);
void				ft_where_is(t_indx *var);

char				**ft_validate(char *argv);
char				**ft_duplicate_map(char **map, int j);
void				ft_free_map(char **map);
void				free_func(t_indx *var);

void				ft_initialize(t_indx *var);
void				ft_flood_fill(char **cpy_map, int x, int y);
void				ft_put_error(void);

#endif