/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:22:10 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/09/30 18:38:50 by jpelaez-         ###   ########.fr       */
=======
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:22:10 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/09/21 19:22:10 by nvan-den         ###   ########.fr       */
>>>>>>> 004a8a1b79afb0d3770e720219f1f5c37323d9bc
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
char 		*ft_realloc(char *str, size_t new_size);
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
