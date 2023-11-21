/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:04:31 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/11/21 15:09:35 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_text_path(char *argument)
{
	int	len;

	len = ft_strlen(argument);
	if (argument[--len] == 'g' && argument[--len] == 'n'
		&& argument[--len] == 'p' && argument[--len] == '.')
		return (1);
	return (0);
}

int	check_format(char **texture)
{
	int	i;

	i = 0;
	while (texture[i])
	{
		if (!check_text_path(texture[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_data(t_data *data)
{
	if (!check_format(data->texture))
		error_msg("Invalid texture format");
}
