/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:22:10 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/02 14:55:20 by nvan-den         ###   ########.fr       */
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
# define SPACES " \f\n\r\t\v"
# define MAPCODES " 01NSEW"
# define PLAYER_P "NSEW"
# define SCREEN_W 1024
# define SCREEN_H 512




typedef struct s_player
{
	int 	p_x;
	int		p_y;
	int     dir_x;
	int		dir_y;
	
}	t_player;


typedef struct s_data
{
	int		fd;
	char	**texture;
	char	**color;
	char	**map;
	int 	floor_c;
	int 	ceiling_c;
	int		map_height;
	mlx_t   *mlx;
	mlx_image_t	*img;
	mlx_image_t	*backgr;

	t_player *player;
	
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

int		ft_strstr(char *big, char *little);
int		check_file(char **argument);
int		is_data(char *line, char **info, t_data **data);
int		is_empty(char *line);
int		check_delimiter(char c, char *delimiter);
int		check_first_rc(char **map);
int		check_last_col(char **map);
int		check_last_row(char **map);

/*Error tools*/
void	error_msg(char *msg);
void	print_info(char **data);
void 	start_game(t_data *data);
void	error_exit(mlx_t* mlx);

/* Drawing */
void	draw_map2D(t_data *data, uint32_t sizeY, uint32_t sizeX);
void	draw_player(t_data *data);

/* Hooks */
void	ft_hook(void* param);

/*Draw stuff*/
void	draw_floor_ceiling(t_data *data);
void	define_color(t_data *data);

/*Player stuff*/
int 	player_position(t_player *player, char **map);
int		player_orientation(t_player *player, char **map);

void	minimap(t_data *data);
#endif
