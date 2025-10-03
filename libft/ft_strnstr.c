/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:36:04 by mvassall          #+#    #+#             */
/*   Updated: 2024/12/11 11:47:11 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	return (b);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		l_len;
	size_t		b_len;
	size_t		scan_len;
	const char	*scan_big;
	const char	*end_big;

	if (*little == '\0')
		return ((char *)big);
	b_len = ft_strlen(big);
	scan_len = ft_min(b_len, len);
	l_len = ft_strlen(little);
	if (scan_len < l_len)
		return (NULL);
	scan_big = big;
	end_big = big + (scan_len - l_len);
	while (scan_big <= end_big)
	{
		if (ft_memcmp(scan_big, little, l_len) == 0)
			return ((char *)scan_big);
		scan_big++;
	}
	return (NULL);
}
