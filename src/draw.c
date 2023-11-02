/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:00:35 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/02 14:37:48 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

/* void	draw_map2D(t_data *data, uint32_t sizeY, uint32_t sizeX)
{
	uint32_t wall_color = ft_pixel(255, 255, 255, 255);
   	uint32_t empty_color = ft_pixel(0, 0, 0, 255);
	
    uint32_t i = 0;
    while (i < data->backgr->height && i < PIXELSIZE)  // Ensure we stay within bounds of map
    {
        uint32_t j = 0;
        uint32_t y = i * sizeY;
        while (j < data->backgr->width && j < PIXELSIZE)  // Ensure we stay within bounds of map
        {
			uint32_t x = j * sizeX;
			uint32_t draw_y = y;
			while (draw_y < y + sizeY && draw_y < data->backgr->height)
			{
				uint32_t draw_x = x;
				while (draw_x < x + sizeX && draw_x < data->backgr->width)
				{
					if (data->map[i][j] == '1')
						mlx_put_pixel(data->backgr, draw_x, draw_y, wall_color);
					else
						mlx_put_pixel(data->backgr, draw_x, draw_y, empty_color);
					draw_x++;
				}
				draw_y++;
            }
            j++;
        }
        i++;
    }
} */

void	draw_player(t_data *data)
{
	uint32_t x;
	uint32_t y;

	x = 0;
	y = 0;
	while (x < data->img->width)
	{
		while (y < data->img->height)
		{
			uint32_t color = ft_pixel(
				0xFF, // R
				100, // G
				0xFF, // B
				0xFF  // A
			);
			mlx_put_pixel(data->img, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}
int	get_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	define_color(t_data *data)
{
	data->floor_c = get_rgb(220, 100, 225);
	data->ceiling_c = get_rgb(100, 0, 225);
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
