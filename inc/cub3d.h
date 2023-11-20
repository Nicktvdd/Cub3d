/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:22:10 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/20 16:06:02 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WIDTH 1024
# define W 1024
# define HEIGHT 512
# define H 512
# define PIXELSIZE 8
# define PLAYERSIZE 20
# define MINIMAPSIZE (HEIGHT / 3)


# include "../libraries/get_next_line/get_next_line.h"
# include "../libraries/libft/libft.h"
# include "../libraries/MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <MLX42/MLX42.h>
# include <math.h>
# include <limits.h>
# define SPACES " \f\n\r\t\v"
# define MAPCODES " 01NSEW"
# define PLAYER_P "NSEW"
# define SCREEN_W 1024
# define SCREEN_H 512
# define TEXTURE_W 64
# define TEXTURE_H 64
# define TRUE 1
# define FALSE 0

typedef struct s_player
{
	double	p_x;
	double	p_y;
	double	dir_x;
	double	dir_y;
	double 	plane_x;
	double 	plane_y;
}	t_player;


typedef struct s_ray 
{
	double 	camera_x;
	double	raydir_x;
	double raydir_y;
	int 	map_x;
	int		map_y;
	double delta_dist_x;
	double delta_dist_y;
	int		step_x;
	int 	step_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_dist;
	int		side;
	int 	line_height;
	int		draw_star;
	int		draw_end;
	double	wall_x;
	int		text_x;
	int 	text_y;
} 	t_ray;

typedef struct s_data
{
	int		fd;
	char	**texture;
	char	**color;
	char	**map;
	int 	floor_c;
	int 	ceiling_c;
	uint32_t	wall_c;
	int		map_height;
	double	frameTime;
	double	m_speed;
	double 	rot_speed;
	mlx_t   *mlx;
	mlx_image_t	*img;
	mlx_texture_t *text_1;
	mlx_texture_t *text_2;
	mlx_texture_t *text_3;
	mlx_texture_t *text_4;
	mlx_texture_t *text_to_draw;
	t_player *player;
	t_ray    *ray;
	
}			t_data;

/*Free Stuff*/

void	free_argt(char **argument);
void	free_argt_exit(char **argument);
void	free_all(t_data *data);

/*Map tools*/
void	init_map(t_data *game, char **argv);
int		is_map(char *line);
void	get_map_line(char *line, char **temp);
void	check_map(char **map);
int		get_map_height(char **map);

/*Parse utils*/

int		check_file(char **argument);
int		is_data(char *line, char **info, t_data **data);
int		is_empty(char *line);
int		check_delimiter(char c, char *delimiter);
int		check_first_rc(char **map);
int		check_last_col(char **map);
int		check_last_row(char **map);
int		check_color(t_data *data);
int		check_spaces(char **map);

/*Error tools*/
void	error_msg(char *msg);
void	print_info(char **data);
void 	start_game(t_data *data);
void	error_exit(mlx_t* mlx);

/* Drawing */
void	draw_map2D(t_data *data);
void	draw_player(t_data *data);

/* Hooks */
void	ft_hook(t_data *data);

/*Draw stuff*/
void	draw_floor_ceiling(t_data *data);
void	define_color(t_data *data);
void	set_background(t_data *data);
void	render(t_data *data);

/*Player stuff*/
int 	player_position(t_player *player, char **map);
int		player_orientation(t_player *player, char **map);

/*RayCasting*/
void	ray_casting(t_data *data);
void	ray_calculations(t_data *data, t_ray *ray, int x);
void 	dda_algorithm(t_data *data, t_ray *ray);
void	wall_calculations(t_ray *ray);


/*Key hook*/
void	move_up(t_data *data, t_player *player);
void	move_down(t_data *data, t_player *player);
void	move_right(t_data *data, t_player *player);
void	move_left(t_data *data, t_player *player);
void	set_speed(t_data *data);
void	rotate_right(t_data *data, t_player *player);
void	rotate_left(t_data *data, t_player *player);


/*HOOK*/
void	close_game(t_data *data);

#endif
