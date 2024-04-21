/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:54:17 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/21 14:36:09 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    int fd;
    char *get_line;
    char **map;
    int i;
    (void)map;
    (void)argv;


    i = 0;

    get_line = NULL;

    if(argc > 1)
    {
        fd = open("map.ber", O_RDONLY);

        // get_line = get_next_line(fd);
        // while(!get_line)
        // {
        //     get_line = get_next_line(fd);
        //     i++;
        // }
        putchar(75);
        putchar(65);
        putchar(65);

        // ft_check(get_line);
    }

}
