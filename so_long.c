/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:54:17 by rel-mora          #+#    #+#             */
/*   Updated: 2024/06/01 12:55:37 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_indx	*var;

	var = malloc(sizeof(t_indx));
	var->map = NULL;
	if (argc == 2)
	{
		var->map = ft_validate(argv[1]);
		ft_initialize(var);
	}
	else
		ft_put_error();
	free(var);
}
