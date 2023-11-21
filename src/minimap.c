/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:48:07 by nvan-den          #+#    #+#             */
/*   Updated: 2023/11/21 12:53:05 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "cub3d.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	draw_map2D(t_data *data)
{
	uint32_t	wall_color;
	uint32_t	empty_color;
	uint32_t	size;
	uint32_t	i;
	uint32_t	j;
	uint32_t	y;
	uint32_t	x;
	uint32_t	draw_y;
	uint32_t	draw_x;

	wall_color = ft_pixel(255, 255, 255, 255);
	empty_color = ft_pixel(0, 0, 0, 255);
	size = MINIMAPSIZE / PIXELSIZE;
	i = 0;
	while (i < data->backgr->height && i < PIXELSIZE)
	{
		j = 0;
		y = i * size;
		while (j < data->backgr->width && j < PIXELSIZE)
		{
			x = j * size;
			draw_y = y;
			while (draw_y < y + size && draw_y < data->backgr->height)
			{
				draw_x = x;
				while (draw_x < x + size && draw_x < data->backgr->width)
				{
					if (data->map[i][j] == '1')
						mlx_put_pixel(data->backgr, draw_x, draw_y, wall_color);
					else
						mlx_put_pixel(data->backgr, draw_x, draw_y,
							empty_color);
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
	uint32_t	x;
	uint32_t	y;

	x = 0;
	y = 0;
	while (x < data->img->width)
	{
		while (y < data->img->height)
		{
			uint32_t color = ft_pixel(0xFF,
										100,
										0xFF,
										0xFF
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
	if (!(data->backgr = mlx_new_image(data->mlx, MINIMAPSIZE, MINIMAPSIZE)))
		error_exit(data->mlx);
	draw_map2D(data);
	if (mlx_image_to_window(data->mlx, data->backgr, (0), (0)) == -1)
		error_exit(data->mlx);
	if (!(data->img = mlx_new_image(data->mlx, PLAYERSIZE, PLAYERSIZE)))
		error_exit(data->mlx);
	draw_player(data);                                                                                                                                     
	if (mlx_image_to_window(data->mlx, data->img, ((MINIMAPSIZE / 2)
				- (PLAYERSIZE / 2)), (MINIMAPSIZE / 2
				- (PLAYERSIZE / 2))) == -1)
		error_exit(data->mlx);
}
 */