/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:55:24 by nvan-den          #+#    #+#             */
/*   Updated: 2023/09/21 20:16:57 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>

static mlx_image_t* image;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
// -----------------------------------------------------------------------------
#define mapX  8      //map width
#define mapY  8      //map height
#define mapS 64      //map cube size
int map[]=           //the map array. Edit to change level but keep the outer walls
{
	1,1,1,1,1,1,1,1,
	1,0,1,0,0,0,0,1,
	1,0,1,0,0,0,0,1,
	1,0,1,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,1,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,
};

void draw_map2D()
{
	int x,y,xo,yo;
	x = 0;
	y = 0;
	xo = 0;
	yo = 0;
	
	uint32_t color;
	if (map[y*mapX+x] == 1)
		color = ft_pixel(0, 0 ,0, 0);
	else
		color = ft_pixel(1, 1, 1, 1);
	while (x < mapX)
	{
		while (y < mapY)
		{
			mlx_put_pixel(image, 0+xo+1, 0+yo+1, color);
			mlx_put_pixel(image, 0   +xo+1, mapS+yo-1, color);
			mlx_put_pixel(image,  mapS+xo-1, mapS+yo-1, color);
			mlx_put_pixel(image, mapS+xo-1, 0   +yo+1, color);
			y++;
		}
		y = 0;
		x++;
	}
}
// -----------------------------------------------------------------------------

void draw_player(void* param)
{
	uint32_t x;
	uint32_t y;

	x = 0;
	y = 0;
	while (x < image->width)
	{
		while (y < image->height)
		{
			uint32_t color = ft_pixel(
				0xFF, // R
				100, // G
				0xFF, // B
				0xFF  // A
			);
			mlx_put_pixel(image, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
	(void)param;
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 2;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 2;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 2;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 2;
}

// -----------------------------------------------------------------------------

int32_t main(int32_t argc, const char* argv[])
{
	mlx_t* mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 20, 20))) //player size is here
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, (WIDTH / 2), (HEIGHT / 2)) == -1) // player position here
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	mlx_loop_hook(mlx, draw_map2D, mlx);
	mlx_loop_hook(mlx, draw_player, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	(void)argc;
	(void)argv;
	return (EXIT_SUCCESS);
}
/* 
int	main(int argc, char **argv)
{
	t_data data;

	if (argc > 2)
		error_msg("Error, number of arguments invalid");
	if (argc == 1)
		error_msg("Error, we need a map");
	init_map(&data, argv);
	return (0);
} */