/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:48:07 by nvan-den          #+#    #+#             */
/*   Updated: 2023/11/02 15:21:05 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_map2D(t_data *data)
{
	uint32_t wall_color = ft_pixel(255, 255, 255, 255);
   	uint32_t empty_color = ft_pixel(0, 0, 0, 255);
	uint32_t size = MINIMAPSIZE / PIXELSIZE;
	
    uint32_t i = 0;
    while (i < data->backgr->height && i < PIXELSIZE)  // Ensure we stay within bounds of map
    {
        uint32_t j = 0;
        uint32_t y = i * size;
        while (j < data->backgr->width && j < PIXELSIZE)  // Ensure we stay within bounds of map
        {
			uint32_t x = j * size;
			uint32_t draw_y = y;
			while (draw_y < y + size && draw_y < data->backgr->height)
			{
				uint32_t draw_x = x;
				while (draw_x < x + size && draw_x < data->backgr->width)
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
}

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

void	minimap(t_data *data)
{
	if (!(data->backgr = mlx_new_image(data->mlx, MINIMAPSIZE, MINIMAPSIZE))) // background size is here
		error_exit(data->mlx);
	draw_map2D(data); // - drawing map
	if (mlx_image_to_window(data->mlx, data->backgr, (0), (0)) == -1) // background position here
		error_exit(data->mlx);
		//------------------
	if (!(data->img = mlx_new_image(data->mlx, PLAYERSIZE, PLAYERSIZE))) //p layer size is here
		error_exit(data->mlx);
	draw_player(data); // - drawing player
	if (mlx_image_to_window(data->mlx, data->img, ((MINIMAPSIZE / 2) - (PLAYERSIZE / 2) /* half of player */), (MINIMAPSIZE / 2 - (PLAYERSIZE / 2))) == -1) // player position here
		error_exit(data->mlx);
}
