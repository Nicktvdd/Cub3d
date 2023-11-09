/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:20:41 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/09 18:37:59 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_stuff(int x, t_ray *ray, t_data *data)
{
	int	y;

	y = ray->draw_star;
	while (y < ray->draw_end)
	{
		mlx_put_pixel(data->img, x, y, data->wall_c);
		y++;
	}
}

void	ray_casting(t_data *data)
{
	int	x;

	x = 0;
	while (x < SCREEN_W)
	{
		ray_calculations(data, data->ray, x);
		dda_algorithm(data, data->ray);
		wall_calculations(data->ray);
		draw_stuff(x, data->ray, data);
		x++;
	}
}
