/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:09:39 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/09/27 13:14:35 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_argt(char **argument)
{
	int	i;

	i = 0;
	while (argument[i])
	{
		free(argument[i]);
		argument[i] = NULL;
		i++;
	}
	free(argument);
}

void	free_argt_exit(char **argument)
{
	free_argt(argument);
	error_msg("Error, empty map");
}

