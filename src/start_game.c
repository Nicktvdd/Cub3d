/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:51:17 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/10/31 17:40:55 by jpelaez-         ###   ########.fr       */
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
	data->mlx = mlx_init(W, H, "NICKJUAN", true);
	if (!data->mlx)
		error_msg("Error");
}

void set_image(t_data *data)
{
	if(!(data->img = mlx_new_image(data->mlx, SCREEN_W, SCREEN_H)))
		error_msg("Error with new image");
	ft_putendl_fd(ft_itoa(data->map_height),2);
	draw_floor(data, 0, SCREEN_H / data->map_height);
	if (mlx_image_to_window(data->mlx, data->img, (0), (0)) < 0)
		error_msg("Error");
	// draw_floor(data);
	// if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
	// 	error_msg("Error");
}

void	star_game(t_data *data)
{
	star_mlx(data);
	set_image(data);
	mlx_key_hook(data->mlx, &keys, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
