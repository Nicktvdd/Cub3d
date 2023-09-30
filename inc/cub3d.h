/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:22:10 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/09/30 19:14:15 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WIDTH 1024
# define HEIGHT 512

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

}			t_data;

/*Free Stuff*/

void		free_argt(char **argument);
void	free_argt_exit(char **argument);

/*Map tools*/
void		init_map(t_data *game, char **argv);
int			is_map(char *line);
void		get_map_line(char *line, char **temp);

/*Parse utils*/

int			ft_strstr(char *big, char *little);
int			check_file(char **argument);
int			is_data(char *line, char **info, t_data **data);
int			is_empty(char *line);
int			check_delimiter(char c, char *delimiter);

/*Error tools*/
void		error_msg(char *msg);

#endif
