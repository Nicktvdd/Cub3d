/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:00:35 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/10/30 19:05:59 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8);
}

void	define_color(t_data *data)
{
	data->floor_c = get_rgb(220, 100, 0);
	data->ceiling_c = get_rgb(225, 30, 0);
}

void	draw_floor(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	define_color(data);
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j])
		{
			mlx_put_pixel(data->img, i, j, data->floor_c);
			j++;
		}
		i++;
	}
}
