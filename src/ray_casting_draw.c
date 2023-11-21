/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:00:35 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/21 15:05:00 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	define_color(t_data *data)
{
	data->floor_c = get_rgb(220, 100, 0);
	data->ceiling_c = get_rgb(225, 30, 0);
}

void	draw_floor_ceiling(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_H)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			if (y < SCREEN_H / 2)
				mlx_put_pixel(data->img, x, y, data->ceiling_c);
			else
				mlx_put_pixel(data->img, x, y, data->floor_c);
			x++;
		}
		y++;
	}
}
