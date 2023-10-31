/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:00:35 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/10/31 18:46:06 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	define_color(t_data *data)
{
	data->floor_c = get_rgb(220, 100, 225);
	data->ceiling_c = get_rgb(100, 0, 225);
}

void	draw_floor(t_data *data, int x_scale, int y_scale)
{
	int	i;
	int	j;
	int	dx;
	int	dy;

	i = 0;
	define_color(data);
	while (data->map[i] != NULL)
	{
		j = 0;
		x_scale = SCREEN_W / ft_strlen(data->map[i]);
		while (data->map[i][j] != '\0')
		{
			dy = 0;
			while (dy < y_scale)
			{
				dx = 0;
				while (dx < x_scale)
				{
					if (data->map[i][j] == '1')
						mlx_put_pixel(data->img, j * x_scale + dx, i * y_scale
								+ dy, data->floor_c);
					else
						mlx_put_pixel(data->img, j * x_scale + dx, i * y_scale
								+ dy, data->ceiling_c);
					dx++;
				}
				dy++;
			}
			j++;
		}
		i++;
	}
}
