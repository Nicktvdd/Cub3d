/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:55:24 by nvan-den          #+#    #+#             */
/*   Updated: 2023/10/31 14:17:35 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
//TODO: make this work with the map
#define PLAYERSIZE 5
#define MINIMAPSIZE (HEIGHT / 3)

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

// -----------------------------------------------------------------------------

/* void	draw_line()
{
	//uint32_t center = image->height / 2;
	uint32_t color = ft_pixel(
				0xFF, // R
				100, // G
				0xFF, // B
				0xFF  // A
			);
	int dx = image->width - image->height;
	int dy = image->height - image->width;
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	
	int incrementx = dx / steps;
	int incrementy = dy / steps;
	
	int x = image->width;
	int y = image->height;
	int i = 0;

	while (i <= steps)
	{
		mlx_put_pixel(image, x, y, color);
		x += incrementx;
		y += incrementy;
		i++;
	}
} */

void	draw_map2D(uint32_t sizeY, uint32_t sizeX)
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
}

void	draw_player(void* param)
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
	//draw_line();
	(void)param;
}

// -----------------------------------------------------------------------------

void	ft_hook(void* param)
{
	mlx_t* mlx = param;
	int move = 2;
	
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
/* 	if (map[image->instances[0].y / HEIGHT][image->instances[0].x / WIDTH] == 1)
		move = 0; */
/* 	if (image->instances[0].y >= HEIGHT + PLAYERSIZE || image->instances[0].x >= WIDTH + PLAYERSIZE || image->instances[0].y <= PLAYERSIZE || image->instances[0].x <= PLAYERSIZE)
		move = -2;
	else
		move = 2; */ //collision not working yet
	printf("image instance\n y: %i\n x: %i\n", image->instances[0].y, image->instances[0].x);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= move;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += move;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= move;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += move;
}

// -----------------------------------------------------------------------------
void	error_exit(mlx_t* mlx)
{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
}
int32_t	main(int32_t argc, const char* argv[])
{
	mlx_t* mlx;
	
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true))) // create the window
		error_exit(mlx);
	if (!(backgr = mlx_new_image(mlx, MINIMAPSIZE, MINIMAPSIZE))) // background size is here
		error_exit(mlx);
	draw_map2D(MINIMAPSIZE / PIXELSIZE, MINIMAPSIZE / PIXELSIZE); // - drawing map
	if (mlx_image_to_window(mlx, backgr, (0), (0)) == -1) // background position here
		error_exit(mlx);
	if (!(image = mlx_new_image(mlx, PLAYERSIZE, PLAYERSIZE))) //p layer size is here
		error_exit(mlx);
	draw_player(mlx); // - drawing player
	if (mlx_image_to_window(mlx, image, ((MINIMAPSIZE / 2) - (PLAYERSIZE / 2) /* half of player */), (MINIMAPSIZE / 2 - (PLAYERSIZE / 2))) == -1) // player position here
		error_exit(mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	error_msg("fuck\n");
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
	init_data(&data);
	init_map(&data, argv);
	return (0);
} */
