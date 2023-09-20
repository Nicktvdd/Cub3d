/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:34:09 by jpelaez-          #+#    #+#             */
/*   Updated: 2022/12/14 17:09:12 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*saved[1024];

	if (fd == -1 || read(fd, NULL, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (saved[fd] == NULL)
	{
		saved[fd] = (char *)malloc(1 * sizeof(char));
		saved[fd][0] = '\0';
	}
	saved[fd] = read_line(fd, saved[fd]);
	line = get_line(saved[fd]);
	saved[fd] = next_line(saved[fd]);
	return (line);
}
