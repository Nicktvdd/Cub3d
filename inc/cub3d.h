/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:22:10 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/10/24 17:38:53 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define W 1024
# define H 512

# include "../libraries/get_next_line/get_next_line.h"
# include "../libraries/libft/libft.h"
# include "MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define SPACES " \f\n\r\t\v"
# define MAPCODES " 01NSEW"

typedef struct s_data
{
	int		fd;
	char	**texture;
	char	**color;
	char	**map;
	mlx_t   *mlx;

}			t_data;

/*Free Stuff*/

void		free_argt(char **argument);
void	free_argt_exit(char **argument);

/*Map tools*/
void		init_map(t_data *game, char **argv);
int			is_map(char *line);
void		get_map_line(char *line, char **temp);
void			check_map(char **map);

/*Parse utils*/

int			ft_strstr(char *big, char *little);
int			check_file(char **argument);
int			is_data(char *line, char **info, t_data **data);
int			is_empty(char *line);
int			check_delimiter(char c, char *delimiter);
int			check_firts_rc(char **map);
int			check_last_col(char **map);
int			check_last_row(char **map);


/*Error tools*/
void		error_msg(char *msg);
void		print_info(char **data);
void 		start_game(t_data *data);	


#endif
