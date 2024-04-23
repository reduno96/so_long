/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:17:12 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/23 19:25:40 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_file(char *argv)
{
	int	i;

	i = ft_strlen(argv) - 1;
	if (argv[i] != 'r')
		return (0);
	i--;
	if (argv[i] != 'e')
		return (0);
	i--;
	if (argv[i] != 'b')
		return (0);
	i--;
	if (argv[i] != '.')
		return (0);
	return (1);
}
