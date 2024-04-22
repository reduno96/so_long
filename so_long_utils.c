/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:17:12 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/22 22:43:43 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_file(char *argv)
{
    // (void)argv;
    char *after_dot;

    after_dot = ft_strchr(argv, '.');

    if (ft_strcmp(after_dot, ".ber") == 0)
        return 1;


    return 0;

}
