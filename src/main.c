/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:10:14 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/10/04 17:13:54 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->map = NULL;
	data->texture = NULL;
	data->color = NULL;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 2)
		error_msg("Error, number of arguments invalid");
	if (argc == 1)
		error_msg("Error, we need a map");
	init_data(&data);
	init_map(&data, argv);
	check_map(data.map);
	return (0);
}