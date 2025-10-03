/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:33:50 by mvassall          #+#    #+#             */
/*   Updated: 2024/12/11 11:45:21 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_overflow(size_t n, size_t sz)
{
	size_t	min;
	size_t	div;

	min = sz;
	if (n < sz)
		sz = n;
	div = (~(size_t)0) / min;
	return (div < n || div < sz);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*area;
	size_t	total_bytes;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (is_overflow(nmemb, size))
		return (NULL);
	total_bytes = nmemb * size;
	area = (char *)malloc(total_bytes);
	if (area == NULL)
		return (NULL);
	return (ft_memset(area, 0, total_bytes));
}
