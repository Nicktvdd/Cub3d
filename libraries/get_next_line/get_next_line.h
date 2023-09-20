/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:02:13 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/04/03 14:48:37 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strchr_2(char *str, int c);
char	*ft_strjoin_2(char *s1, char *s2);
char	*ft_substr_2(char *s, unsigned int start, size_t len);
char	*ft_strdup_2(char *src, size_t destlen);

size_t	ft_strlen_2(const char *str);

#endif
