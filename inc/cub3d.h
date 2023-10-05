/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:22:10 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/10/05 14:34:07 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WIDTH 1024
# define HEIGHT 512
# define PIXELSIZE 8

# include "../libraries/libft/libft.h"
# include "../libraries/get_next_line/get_next_line.h"
# include "MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <MLX42/MLX42.h>
# include <math.h>

typedef struct s_data
{
	int	fd;
	char 	**texture;
	char	**color;

}		t_data;

/*Map tools*/
void	init_map(t_data *game, char **argv);


/*Parse utils*/

int	ft_strstr(char *big, char *little);

/*Error tools*/
void	error_msg(char *msg);

#endif
