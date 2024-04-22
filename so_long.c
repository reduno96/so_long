/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:54:17 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/22 22:51:24 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

while !str
    i+;
i--;
if(str[i] == 'r')
    i--


int	main(int argc, char **argv)
{
	int		fd;
	char	*get_line;
	char	*joined;
	char	**map;
	int		i;

	(void)map;
	(void)argv;
	i = 0;
	get_line = NULL;
	if (argc > 1)
	{
		if (ft_check_file(argv[1]) )
		{
			fd = open("map.ber", O_RDONLY);
			get_line = get_next_line(fd);
			while (get_line != NULL)
			{
				joined = ft_join(joined, get_line);
				get_line = get_next_line(fd);
			}
			map = ft_split(joined, '\n');
		}
        else
        ft_putstr_fd("Error", 2);
	}
}
