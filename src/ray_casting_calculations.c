/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_calculations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:12:42 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/02 16:42:35 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_box_position_direction(t_data *data, int x)
{
	data->camera_x = 2 * x / (double)SCREEN_W - 1;
	data->raydir_x = data->player->dir_x + data->player->plane_x
		* data->camera_x;
	data->raydir_y = data->player->dir_y + data->player->plane_y
		* data->camera_x;
	data->map_x = (int)data->player->p_x;
	data->map_y = (int)data->player->p_y;
}
