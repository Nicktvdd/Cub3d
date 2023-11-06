/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:20:41 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/06 17:13:27 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_casting(t_data *data)
{
	int x;

	x = 0;
	data->ray = malloc(sizeof(t_ray));
	if (!data->ray)
		error_msg("malloc error");
	while (x < SCREEN_W)
	{
		ray_calculations(data, data->ray, x);
		dda_algorithm(data, data->ray);
		wall_calculations(data->ray);
		x++;
	}
	mlx_put_pixel(data->img, data->ray->draw_star, data->ray->draw_end,
			data->wall_c);
	if (mlx_image_to_window(data->mlx, data->img, (0), (0)) < 0)
		error_msg("Error");
}
