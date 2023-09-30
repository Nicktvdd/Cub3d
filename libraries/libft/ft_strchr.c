/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:18:23 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/09/29 17:13:31 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*array;

	array = (char *)str;
	while (*array != (unsigned char)c && *array != '\0')
	{
		array++;
	}
	if (*array == (unsigned char)c)
		return (array);
	else
		return (0);
}
