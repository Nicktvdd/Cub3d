/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:55:24 by nvan-den          #+#    #+#             */
/*   Updated: 2023/09/27 14:44:29 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>

void	error_exit(mlx_t* mlx);

static mlx_image_t* image;
static mlx_image_t* backgr;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
// -----------------------------------------------------------------------------
int map[8][8] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}
};

void	put_big_pixel(uint32_t y, uint32_t x, uint32_t color)
{
	while (x < 10)
	{
		while (y < 10)
		{
				mlx_put_pixel(backgr, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}

void draw_map2D(void* param)
{
	uint32_t wall_color = ft_pixel(255, 255, 255, 255);
   	uint32_t empty_color = ft_pixel(0, 0, 0, 255);

    uint32_t i = 0;
	uint32_t sizeY = HEIGHT / 8;
	uint32_t sizeX = WIDTH / 8;
	
    while (i < backgr->height && i < 8)  // Ensure we stay within bounds of map
    {
        uint32_t j = 0;
        uint32_t y = i * sizeY;
        while (j < backgr->width && j < 8)  // Ensure we stay within bounds of map
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

    (void)param;
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
	// mlx_delete_image(mlx, image);
	// if (!(image = mlx_new_image(mlx, 50, 50))) //player size is here
	// 	error_exit(mlx);
	// draw_map2D(mlx);
	// draw_player(mlx);
	// if (mlx_image_to_window(mlx, image, (WIDTH / 2), (HEIGHT / 2)) == -1) // player position here
	// 	error_exit(mlx);
}

// -----------------------------------------------------------------------------
void	error_exit(mlx_t* mlx)
{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
}
int32_t main(int32_t argc, const char* argv[])
{
	mlx_t* mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true))) //create the window
		error_exit(mlx);
	if (!(backgr = mlx_new_image(mlx, WIDTH, HEIGHT))) //player size is here
		error_exit(mlx);
	draw_map2D(mlx); // - drawing map
	if (mlx_image_to_window(mlx, backgr, (0), (0)) == -1) // player position here
		error_exit(mlx);
	if (!(image = mlx_new_image(mlx, 50, 50))) //player size is here
		error_exit(mlx);
	draw_player(mlx); // - drawing player
	if (mlx_image_to_window(mlx, image, (WIDTH / 2), (HEIGHT / 2)) == -1) // player position here
		error_exit(mlx);
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