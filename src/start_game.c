/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:51:17 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/08 18:23:32 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//TODO: Everything into this file
void	keys(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		free_all(data);
		mlx_close_window(data->mlx);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_up(data, data->player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_down(data, data->player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left(data, data->player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_right(data, data->player); 
	ray_casting(data);
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
	set_speed(data);
	mlx_loop_hook(data->mlx, (void*)keys, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
