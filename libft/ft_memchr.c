/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:34:10 by mvassall          #+#    #+#             */
/*   Updated: 2024/12/11 11:46:05 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*p;

	if (!n)
		return (NULL);
	p = s;
	c &= 0xff;
	while (n--)
	{
		if (*p == c)
			return (p);
		p++;
	}
	return (NULL);
}
