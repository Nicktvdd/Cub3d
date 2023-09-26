/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:22:10 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/09/26 17:06:55 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libraries/libft/libft.h"
# include "../libraries/get_next_line/get_next_line.h"
# include "MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 256
# define HEIGHT 256

typedef struct s_data
{
	int	fd;
	char 	**texture;
	char	**color;
	char	**map;

}		t_data;

/*Map tools*/
void	init_map(t_data *game, char **argv);


/*Parse utils*/

int	ft_strstr(char *big, char *little);
int	check_file(char **argument);
int	is_data(char *line, char **info, t_data *data);

/*Error tools*/
void	error_msg(char *msg);

#endif
