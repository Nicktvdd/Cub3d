/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:10:14 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/22 15:13:10 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_textures(t_data *data)
{
	data->text_1 = mlx_load_png(data->texture[0]);
	if (!data->text_1)
		error_msg("Error loading textures");
	data->text_2 = mlx_load_png(data->texture[1]);
	if (!data->text_2)
		error_msg("Error loading textures");
	data->text_3 = mlx_load_png(data->texture[2]);
	if (!data->text_3)
		error_msg("Error loading textures");
	data->text_4 = mlx_load_png(data->texture[3]);
	if (!data->text_4)
		error_msg("Error loading textures");
}

void	set_player(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	if (!data->player)
		error_msg("Malloc Error");
	if (!player_position(data->player, data->map))
		error_msg("Player position error");
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
	check_data(&data);
	set_player(&data);
	set_textures(&data);
	start_game(&data);
	return (0);
}
