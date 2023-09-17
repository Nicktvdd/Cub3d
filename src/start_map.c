/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:57:50 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/09/17 19:01:42 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_file(int argc, char **argument)
{
	if (!ft_strstr(argument[1], ".cub"))
		return (0);
	return (1);
}
void	init_map(t_list *game, int argc, char **argv)
{
    if (!check_file(argc, argv))
		error_msg("Error, invalid file format");
    
}