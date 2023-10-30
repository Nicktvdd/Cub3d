/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:10:14 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/10/30 15:27:37 by nvan-den         ###   ########.fr       */
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

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	if (argc > 2)
		error_msg("Error, number of arguments invalid");
	if (argc == 1)
		error_msg("Error, we need a map");
	init_data(&data);
	init_map(&data, argv);
	check_map(data.map);
	start_game(&data);
	return (0);
}
