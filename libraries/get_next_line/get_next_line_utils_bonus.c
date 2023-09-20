/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:36:09 by jpelaez-          #+#    #+#             */
/*   Updated: 2022/12/05 14:36:40 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	if ((unsigned char)c == '\0')
		return (str);
	if (str == NULL)
		return (NULL);
	while (*str != (unsigned char)c && *str != '\0')
		str++;
	if (*str == (unsigned char)c)
		return (str);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (s1 == NULL && s2 == NULL)
		return (0);
	i = 0;
	j = 0;
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	return (s3);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (0);
	i = start;
	j = 0;
	s2 = (char *)malloc(sizeof(char) * len + 1);
	if (s2 == NULL)
		return (0);
	while (i < len + start)
		s2[j++] = s[i++];
	s2[j] = '\0';
	free(s);
	return (s2);
}

char	*ft_strdup(char *src, size_t destlen)
{
	int		i;
	char	*dest;

	dest = malloc(sizeof(char) * (destlen + 1));
	if (dest == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0' && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		dest[i] = '\n';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
