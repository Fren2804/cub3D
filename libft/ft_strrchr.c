/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:36:10 by mvassall          #+#    #+#             */
/*   Updated: 2024/12/11 11:47:13 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	c &= 0xff;
	p = s;
	while (*p)
		p++;
	while (p >= s && *p != c)
		p--;
	if (*p == c)
		return ((char *)p);
	return (NULL);
}
