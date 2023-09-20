/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:53:52 by jpelaez-          #+#    #+#             */
/*   Updated: 2022/12/14 15:52:39 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *saved)
{
	int		byte_r;
	char	*buffer;

	buffer = (char *)malloc((sizeof(char)) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (0);
	byte_r = 1;
	while (!(ft_strchr(saved, '\n')) && byte_r != 0)
	{
		byte_r = read(fd, buffer, BUFFER_SIZE);
		if (byte_r == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_r] = '\0';
		saved = ft_strjoin(saved, buffer);
	}
	free(buffer);
	return (saved);
}

static char	*get_line(char *sv)
{
	size_t	i;
	char	*line;

	if (sv[0] == '\0')
		return (NULL);
	i = 0;
	while (sv[i] != '\0' && sv[i] != '\n')
		i++;
	if (sv[i] == '\n')
		i++;
	line = ft_strdup(sv, i);
	return (line);
}

static char	*next_line(char *sv)
{
	size_t	i;
	char	*new_saved;

	i = 0;
	while (sv[i] != '\0' && sv[i] != '\n')
		i++;
	if (sv[i] == '\0')
	{
		free(sv);
		return (NULL);
	}
	if (sv[i] == '\n')
		i++;
	new_saved = ft_substr(sv, i, ft_strlen(sv) - i);
	return (new_saved);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved;

	if (fd == -1 || read(fd, NULL, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (saved == NULL)
	{
		saved = (char *)malloc(1 * sizeof(char));
		saved[0] = '\0';
	}
	saved = read_line(fd, saved);
	line = get_line(saved);
	saved = next_line(saved);
	return (line);
}
