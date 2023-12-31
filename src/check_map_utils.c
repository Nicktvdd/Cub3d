/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:29:37 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/21 15:02:57 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_around_zero(int i, int j, char **map)
{
	if (!map[i + 1] || !map[i][j + 1] || !map[i + 1][j])
		return (0);
	if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
		return (0);
	if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
		return (0);
	return (1);
}

// TODO: Initialize len and nextlen, remove printf
int	check_spaces(char **map)
{
	int	i;
	int	j;
	int	len;
	int	nextlen;

	i = -1;
	j = -1;
	len = 0;
	nextlen = 0;
	while (map[++i])
	{
		if (map[i + 1])
			nextlen = ft_strlen(map[i + 1]);
		while (map[i][++j])
		{
			if (map[i][j] == '0' && (i == 0 || j == 0 || j >= len
				|| j >= nextlen || !check_around_zero(i, j, map)))
				return (0);
		}
		len = ft_strlen(map[i]);
		j = -1;
	}
	return (1);
}

int	get_map_height(char **map)
{
	int	i;
	int	height;

	i = 0;
	height = 0;
	while (map[i])
	{
		height++;
		i++;
	}
	return (height);
}

int	check_last_row(char **map)
{
	int	i;
	int	n_rows;

	i = 0;
	n_rows = get_map_height(map);
	while (map[n_rows - 1][i] != '\0')
	{
		if (map[n_rows - 1][i] != '1' && map[n_rows - 1][i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	check_last_col(char **map)
{
	int		i;
	size_t	row_len;

	i = 0;
	while (map[i])
	{
		row_len = ft_strlen(map[i]);
		if (row_len > 0 && (map[i][row_len - 1] != '1' && map[i][row_len
			- 1] != ' '))
			return (0);
		i++;
	}
	return (1);
}
