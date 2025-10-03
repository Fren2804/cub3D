/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user1 <user1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:29:31 by mvassall          #+#    #+#             */
/*   Updated: 2025/03/07 09:37:55 by user1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static char	*gnl_find_nl(char *str)
{
	if (str != NULL)
	{
		while (*str != '\0' && *str != '\n')
			str++;
		if (*str == '\0')
			str = NULL;
	}
	return (str);
}

static char	*gnl_joinstr(char *str1, char *str2, size_t len)
{
	size_t	size;
	char	*line;
	char	*pline;

	size = gnl_strlen(str1) + (len + 1);
	line = NULL;
	if (size > 0)
		line = malloc(size * sizeof(char));
	if (line == NULL)
		return (str1);
	pline = line;
	if (str1 != NULL)
	{
		while (*str1)
			*pline++ = *str1++;
	}
	while (len-- > 0)
		*pline++ = *str2++;
	line[size - 1] = '\0';
	return (line);
}

static char	*found_nl(char *line, char *nlp, t_buf *rb)
{
	char	*aux;

	aux = gnl_joinstr(line, rb->start, (nlp - rb->start) + 1);
	rb->start = nlp + 1;
	if (aux == NULL)
	{
		return (line);
	}
	free(line);
	return (aux);
}

ssize_t	gnl_read_buf(int fd, t_buf *rb)
{
	ssize_t	nb_read;

	if (fd < 0 || rb == NULL)
		return (-1);
	nb_read = read(fd, rb->buf, rb->buffer_size);
	if (nb_read <= 0)
	{
		rb->buf[0] = '\0';
		rb->start = NULL;
	}
	else
	{
		rb->buf[nb_read] = '\0';
		rb->start = rb->buf;
	}
	return (nb_read);
}

char	*gnl_getline(int fd, t_buf *rb)
{
	char	*nlp;
	char	*line;
	char	*aux;

	if (fd < 0 || rb == NULL || rb->buf == NULL || rb->buffer_size == 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (rb->start == NULL || *rb->start == '\0')
		{
			if (gnl_read_buf(fd, rb) <= 0)
				return (line);
		}
		nlp = gnl_find_nl(rb->start);
		if (nlp != NULL)
			return (found_nl(line, nlp, rb));
		aux = gnl_joinstr(line, rb->start, gnl_strlen(rb->start));
		if (aux == NULL)
			return (line);
		free(line);
		line = aux;
		rb->start = NULL;
	}
}
