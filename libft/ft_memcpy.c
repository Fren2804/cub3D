/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:34:25 by mvassall          #+#    #+#             */
/*   Updated: 2025/01/17 11:15:48 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// dst == null, src == null, n == 3 => Segmentation fault
// dst != null, src == null, n == 3 => Segmentation fault
// dst == null, src != null, n == 3 => Segmentation fault
// dst == null, src == null, n == 0 => (nil)
// dst == null, src != null, n == 0 => (nil)
// dst != null, src == null, n == 0 => dst

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned char const	*s;

	if (n == 0)
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char const *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}
