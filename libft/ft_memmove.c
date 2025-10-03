/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:34:31 by mvassall          #+#    #+#             */
/*   Updated: 2025/01/17 11:14:51 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// dst == null, src == null, n != 0 => Segmentation fault
// dst != null, src == null, n != 0 => Segmentation fault
// dst == null, src != null, n != 0 => Segmentation fault
// dst == null, src == null, n == 0 => (nil)
// dst == null, src != null, n == 0 => (nil)
// dst != null, src == null, n == 0 => dst

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (n == 0)
		return (dst);
	if (src < dst)
	{
		d = (char *)dst + n - 1;
		s = (const char *)src + n - 1;
		while (n--)
			*d-- = *s--;
	}
	else
	{
		d = (char *)dst;
		s = (const char *)src;
		while (n--)
			*d++ = *s++;
	}
	return (dst);
}
