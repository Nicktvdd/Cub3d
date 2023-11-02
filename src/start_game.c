/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:51:17 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/02 14:31:42 by nvan-den         ###   ########.fr       */
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

void	start_mlx(t_data *data)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->mlx = mlx_init(W, H, "NICKJUAN", true);
	if (!data->mlx)
		error_msg("Error");
}

void set_image(t_data *data)
{
/* 	if (!(data->backgr = mlx_new_image(data->mlx, MINIMAPSIZE, MINIMAPSIZE))) // background size is here
		error_exit(data->mlx);
	draw_map2D(MINIMAPSIZE / PIXELSIZE, MINIMAPSIZE / PIXELSIZE); // - drawing map
	if (mlx_image_to_window(data->mlx, data->backgr, (0), (0)) == -1) // background position here
		error_exit(data->mlx); */
		//------------------
	if (!(data->img = mlx_new_image(data->mlx, PLAYERSIZE, PLAYERSIZE))) //p layer size is here
		error_exit(data->mlx);
	draw_player(data); // - drawing player
	if (mlx_image_to_window(data->mlx, data->img, ((MINIMAPSIZE / 2) - (PLAYERSIZE / 2) /* half of player */), (MINIMAPSIZE / 2 - (PLAYERSIZE / 2))) == -1) // player position here
		error_exit(data->mlx);
	
/* 	data->img = mlx_new_image(data->mlx, SCREEN_W, SCREEN_H);
	if (!data->img || (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0))
		error_msg("Error"); */
	//draw_floor(data);
}

void	start_game(t_data *data)
{
	start_mlx(data);
	set_image(data);
	mlx_key_hook(data->mlx, &keys, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
