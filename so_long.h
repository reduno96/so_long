/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:07:39 by rel-mora          #+#    #+#             */
/*   Updated: 2024/05/30 22:08:09 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Keys
# define ESC_KEY 53

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_indx
{
	int	i;
	int	j;
	int	x;
	int	y;
}		t_indx;

int		ft_check_file(char *argv);
void	ft_check_wall(char **map, int i);
int		ft_check_least(char **map, char c);
void	ft_check_lgh(char **map);
void	ft_check_char(char **map);
void	ft_check_all(char **map);
void	ft_check_flood(char **cpy_map);
void	ft_check_map(char *argv, char ***map);
void	ft_player_path(char **map);
char	**ft_validate(char *argv);
char	**ft_duplicate_map(char **map, int j);
void	ft_free_map(char **map);
void	ft_initialize(char **map);
void	ft_flood_fill(char **cpy_map, int x, int y);
void	ft_put_error(void);

#endif