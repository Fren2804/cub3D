/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:35:42 by mvassall          #+#    #+#             */
/*   Updated: 2024/12/11 11:47:03 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len >= size)
	{
		if (size > 0)
		{
			ft_memcpy(dst, src, size);
			dst[size - 1] = '\0';
		}
	}
	else
		ft_memcpy(dst, src, src_len + 1);
	return (src_len);
}
