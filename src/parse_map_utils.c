/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:35:12 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/09/26 17:51:44 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_not_data(char *line)
{
	char	**info;

	info = ft_split(line, " ");
	if (!info[0])
		error_msg("Allocation Error");
	if (ft_strnstr(info[0], "NO", ft_strlen(info[0])) || ft_strnstr(info[0],
			"SO", ft_strlen(info[0])) || ft_strnstr(info[0], "WE",
			ft_strlen(info[0])) || ft_strnstr(info[0], "EA", ft_strlen(info[0]))
		|| ft_strnstr(info[0], "F", ft_strlen(info[0])) || ft_strnstr(info[0],
			"C", ft_strlen(info[0])))
	{
		free_argt(info);
		return (0);
	}
	return (1);
}

int	is_map(char *line)
{
	if (is_not_data(line))
		return (0);
	else if (is_empty(line))
		return (0);
	else
		return (1);
}
