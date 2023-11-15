/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:51:17 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/15 08:50:24 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keys(mlx_key_data_t keydata, t_data *data)
{
  	int move = 2;
    
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		free_all(data);
		mlx_close_window(data->mlx);
	}
  	printf("image instance\n y: %i\n x: %i\n", data->img->instances[0].y, data->img->instances[0].x);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->img->instances[0].y -= move;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->img->instances[0].y += move;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->img->instances[0].x -= move;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->img->instances[0].x += move;
}

void	start_mlx(t_data *data)
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
	if (!player_position(data->player, data->map))
		error_msg("Error, no player position");
	if (!player_orientation(data->player, data->map))
		error_msg("Error, invalid orientation");
}

void	start_game(t_data *data)
{
	start_mlx(data);
	set_background(data); // have to set also the textures
	//set_player(data);
	//ray_casting(data);
	//minimap(data);
	//mlx_key_hook(data->mlx, &keys, data);
	//mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
