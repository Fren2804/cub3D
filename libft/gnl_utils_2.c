/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:28:26 by user1             #+#    #+#             */
/*   Updated: 2025/09/04 10:44:10 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gnl_ungetchar(int c, t_buf *rb)
{
	if (rb == NULL || c < 0 || rb->ungetc >= 0)
		return (0);
	rb->ungetc = c;
	return (1);
}

int	gnl_getchar(int fd, t_buf *rb)
{
	int	c;

	if (fd < 0 || rb == NULL)
		return (-2);
	if (rb->ungetc >= 0)
	{
		c = rb->ungetc;
		rb->ungetc = -1;
		return (c);
	}
	if (rb->start == NULL || *rb->start == '\0')
		if (gnl_read_buf(fd, rb) <= 0)
			return (-1);
	c = *rb->start;
	rb->start++;
	return (c);
}
