/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_calculations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:12:42 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/10 18:08:04 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	step_sidedist_calculation(t_data *data, t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player->p_x - (double)ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = ((double)ray->map_x + 1.0 - data->player->p_x)
			* ray->delta_dist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player->p_y - (double)ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = ((double)ray->map_y + 1.0 - data->player->p_y)
			* ray->delta_dist_y;
	}
}

void	ray_calculations(t_data *data, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)SCREEN_W - 1;
	ray->raydir_x = data->player->dir_x + data->player->plane_x
		* ray->camera_x;
	ray->raydir_y = data->player->dir_y + data->player->plane_y
		* ray->camera_x;
	ray->map_x = (int)(data->player->p_x);
	ray->map_y = (int)(data->player->p_y);
	if (ray->raydir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs((1 / ray->raydir_x));
	if (ray->raydir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->raydir_y);
	step_sidedist_calculation(data, ray);
}

void	dda_algorithm(t_data *data, t_ray *ray)
{
	int	hit;

	hit = TRUE;
	while (hit == TRUE)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map[ray->map_x][ray->map_y] == '1')
			hit = FALSE;
	}
}

void	wall_calculations(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_dist = ray->side_dist_y - ray->delta_dist_y;
	ray->line_height = (int)(SCREEN_H / ray->perp_dist);
	/*division by 0*/
	// printf("%d\n", ray->line_height);
	// ft_putnbr_fd(ray->line_height,2);
	// ft_putchar_fd(' ',2);
	ray->draw_star = SCREEN_H / 2 - ray->line_height / 2;
	if (ray->draw_star < 0)
		ray->draw_star = 0;
	ray->draw_end = SCREEN_H / 2 + ray->line_height / 2;
	if (ray->draw_end >= SCREEN_H)
		ray->draw_end = SCREEN_H - 1;
}
