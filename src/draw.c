/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:00:35 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/10/30 15:39:23 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

/* void	draw_map2D(uint32_t sizeY, uint32_t sizeX)
{
	uint32_t wall_color = ft_pixel(255, 255, 255, 255);
   	uint32_t empty_color = ft_pixel(0, 0, 0, 255);
	
    uint32_t i = 0;
    while (i < backgr->height && i < PIXELSIZE)  // Ensure we stay within bounds of map
    {
        uint32_t j = 0;
        uint32_t y = i * sizeY;
        while (j < backgr->width && j < PIXELSIZE)  // Ensure we stay within bounds of map
        {
			uint32_t x = j * sizeX;
			uint32_t draw_y = y;
			while (draw_y < y + sizeY && draw_y < backgr->height)
			{
				uint32_t draw_x = x;
				while (draw_x < x + sizeX && draw_x < backgr->width)
				{
					if (map[i][j] == 1)
						mlx_put_pixel(backgr, draw_x, draw_y, wall_color);
					else
						mlx_put_pixel(backgr, draw_x, draw_y, empty_color);
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