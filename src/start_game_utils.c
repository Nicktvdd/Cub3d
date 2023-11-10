/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:05:44 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/10 13:14:55 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_speed(t_data *data)
{
	data->frameTime = 16.0 / 1000.0;
	data->m_speed = data->frameTime * 5.0;
	data->rot_speed = data->frameTime * 3.0;
}

void	set_background(t_data *data)
{
	define_color(data);
	draw_floor_ceiling(data);
	// if (mlx_image_to_window(data->mlx, data->img, (0), (0)) < 0)
	// 	error_msg("Error");
}

void close_game(t_data *data)
{
	free_all(data);
	mlx_close_window(data->mlx);
}