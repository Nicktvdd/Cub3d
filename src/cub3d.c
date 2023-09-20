/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:55:24 by nvan-den          #+#    #+#             */
/*   Updated: 2023/09/20 15:36:53 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (argc > 2)
		error_msg("Error, number of arguments invalid");
	if (argc == 1)
		error_msg("Error, we need a map");
	init_map(&data, argv);
	return (0);
}