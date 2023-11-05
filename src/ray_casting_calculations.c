/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_calculations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:12:42 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/05 17:32:20 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	step_sidedist_calculation(t_data *data)
{
	if (data->raydir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->player->p_x - data->map_x)
			* data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1 - data->player->p_x)
			* data->delta_dist_x;
	}
	if (data->raydir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->player->p_y - data->map_y)
			* data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1 - data->player->p_y)
			* data->delta_dist_y;
	}
}

void	ray_calculations(t_data *data, int x)
{
	data->camera_x = 2 * x / (double)SCREEN_W - 1;
	data->raydir_x = data->player->dir_x + data->player->plane_x
		* data->camera_x;
	data->raydir_y = data->player->dir_y + data->player->plane_y
		* data->camera_x;
	data->map_x = (int)data->player->p_x;
	data->map_y = (int)data->player->p_y;
	if (data->raydir_x == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs((1 / data->raydir_x));
	if (data->raydir_y == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1 / data->raydir_x);
	step_sidedist_calculation(data);
}

void	dda_algorithm(t_data *data)
{
	int	hit;

	hit = TRUE;
	while (hit == TRUE)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->map[data->map_x][data->map_y] == '1')
			hit = FALSE;
	}
}

void	wall_calculations(t_data *data)
{
	if (data->side == 0)
		data->perp_dist = data->side_dist_x - data->delta_dist_x;
	else
		data->perp_dist = data->side_dist_y - data->delta_dist_y;
	data->line_height = (int)(SCREEN_H / data->perp_dist);
	data->draw_star = SCREEN_H / 2 - data->line_height / 2;
	if(data->draw_star < 0)
		data->draw_star = 0;
	data->draw_end = SCREEN_H / 2 + data->line_height / 2;
	if(data->draw_end >= SCREEN_H )
		data->draw_end = SCREEN_H - 1;
}
