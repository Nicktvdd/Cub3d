/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:22:10 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/09/20 14:43:34 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 256
# define HEIGHT 256

typedef struct s_data
{
	int	fd;

}		t_data;

/*Map tools*/
void	init_map(t_data *game, int argc, char **argv);

/*Error tools*/
void	error_msg(char *msg);

#endif
