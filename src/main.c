/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:10:14 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/02 14:55:37 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (!check_delimiter(data->map[i][j], PLAYER_P))
			{
				break ;
			}
			j++;
		}
		i++;
	}
	data->map_height = get_map_height(data->map);
}

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
	start_position(&data);
	start_game(&data);
	return (0);
}
