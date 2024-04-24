/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:07:39 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/24 08:02:36 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
// Keys
#define ESC_KEY 53

// Include
// # include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
}			t_data;
typedef struct s_indx
{
	int i;
	int j;
	int x;
	int y;
}			t_indx;

int ft_check_file(char *argv);
char	**ft_validate(char *argv);
void ft_free_map(char **map);
#endif