/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:51:17 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/06 16:56:37 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//TODO: Everything into this file
void	keys(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		free_all(data);
		mlx_close_window(data->mlx);
	}
}

void	star_mlx(t_data *data)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->mlx = mlx_init(SCREEN_W, SCREEN_H, "NICKJUAN", true);
	if (!data->mlx)
		error_msg("Error");
}

void	set_background(t_data *data)
{
	if (!(data->img = mlx_new_image(data->mlx, SCREEN_W, SCREEN_H)))
		error_msg("Error with new image");
	define_color(data);
	draw_floor_ceiling(data);
	if (mlx_image_to_window(data->mlx, data->img, (0), (0)) < 0)
		error_msg("Error");
}

void	set_player(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	if (!data->player)
		error_msg("Malloc Error");
	if (!player_position(data->player, data->map))
		error_msg("Error, no player position");
	if (!player_orientation(data->player, data->map))
		error_msg("Erros invalid orientation");
}

void	star_game(t_data *data)
{
	star_mlx(data);
	set_background(data); // have to set also the textures
	set_player(data);
	ray_casting(data);
	mlx_key_hook(data->mlx, &keys, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
