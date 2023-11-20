/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:51:17 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/20 14:10:52 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//TODO: Everything into this file
void	keys(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		close_game(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_up(data, data->player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_down(data, data->player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left(data, data->player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_right(data, data->player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_right(data, data->player);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_left(data, data->player);
}

void	render(t_data *data)
{
	set_background(data); // have to set also the textures
	ray_casting(data);
	set_speed(data);
	if (mlx_image_to_window(data->mlx, data->img, (0), (0)) < 0)
		error_msg("Error");
}

void	start_mlx(t_data *data)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->mlx = mlx_init(SCREEN_W, SCREEN_H, "NICKJUAN", true);
	if (!data->mlx)
		error_msg("Error");
	if (!(data->img = mlx_new_image(data->mlx, SCREEN_W, SCREEN_H)))
		error_msg("Error with new image");
}

void	start_game(t_data *data)
{
	star_mlx(data);
	render(data);
	mlx_loop_hook(data->mlx, (void *)keys, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
