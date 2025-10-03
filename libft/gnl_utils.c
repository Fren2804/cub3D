/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:29:31 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/03 18:07:09 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

size_t	gnl_strlen(char *str)
{
	size_t	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	*gnl_dispose(t_buf *sb)
{
	if (sb == NULL)
		return (NULL);
	if (sb->buf != NULL)
		free(sb->buf);
	free(sb);
	return (NULL);
}

t_buf	*gnl_alloc_buf(unsigned int buffer_size)
{
	t_buf	*sb;

	if (buffer_size == 0)
		return (NULL);
	sb = malloc(sizeof(t_buf));
	if (sb == NULL)
		return (NULL);
	sb->buf = malloc((buffer_size + 1) * sizeof(char));
	if (sb->buf == NULL)
		return (gnl_dispose(sb));
	sb->buf[0] = '\0';
	sb->start = NULL;
	sb->buffer_size = buffer_size;
	sb->ungetc = -1;
	return (sb);
}

char	*get_next_line(int fd)
{
	static t_buf	*tb;
	char			*line;

	if (tb == NULL)
		tb = gnl_alloc_buf(BUFFER_SIZE);
	line = gnl_getline(fd, tb);
	if (line == NULL)
		gnl_dispose(tb);
	return (line);
}
