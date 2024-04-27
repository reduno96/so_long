/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:07:39 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/27 15:22:52 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
// Keys
# define ESC_KEY 53

// Include
// # include <mlx.h>
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
#include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>



typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
}			t_data;
typedef struct s_indx
{
	int		i;
	int		j;
	int		x;
	int		y;
}			t_indx;

int			ft_check_file(char *argv);
void		ft_check_wall(char **map, int i);
int			ft_check_least(char **map, char c);
void		ft_check_lgh(char **map);
void		ft_check_just(char **map);
void		ft_check_all(char **map);
void		ft_check_flood(char **cpy_map);
char		**ft_validate(char *argv);
void		ft_free_map(char **map);
char		**ft_duplicate_map(char **map, int j);
void		ft_flood_fill(char **cpy_map, int x, int y);
#endif