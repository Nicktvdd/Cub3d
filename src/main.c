/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:10:14 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/09 16:30:34 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	if (!data->player)
		error_msg("Malloc Error");
	if (!player_position(data->player, data->map))
		error_msg("Error, no player position");
	if (!player_orientation(data->player, data->map))
		error_msg("Erros invalid orientation");
	data->map_height = get_map_height(data->map);
}

void	init_data(t_data *data)
{
	data->map = NULL;
	data->texture = NULL;
	data->color = NULL;
	data->ray = malloc(sizeof(t_ray));
	if (!data->ray)
		error_msg("malloc error");
	data->player = NULL;
}

void	render(t_data *data)
{
	set_background(data); // have to set also the textures
	ray_casting(data);
	set_speed(data);
	if (mlx_image_to_window(data->mlx, data->img, (0), (0)) < 0)
		error_msg("Error");	
	// mlx_delete_image(data->mlx, data->img);
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
	set_player(&data);
	star_game(&data);
	return (0);
}
