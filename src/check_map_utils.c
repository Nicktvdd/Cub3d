/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:29:37 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/10/05 14:29:17 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_firts_rc(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[i][0] != '\0')
	{
		if (map[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_last_row(char **map)
{
	int	i;
	int	n_rows;

	i = 0;
	n_rows = 0;
	while (map[i] != NULL)
	{
		n_rows++;
		i++;
	}
	i = 0;
	while (map[n_rows][i])
	{
		if (map[n_rows - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_last_col(char **map)
{
	int i;
	size_t row_len;

	i = 0;
	while (map[i])
	{
		row_len = ft_strlen(map[i]);
		if (row_len > 0 && map[i][row_len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}