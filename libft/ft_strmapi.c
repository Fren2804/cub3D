/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:34:05 by mvassall          #+#    #+#             */
/*   Updated: 2024/12/11 11:47:06 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dup;
	char	*p;

	if (s == NULL || f == NULL)
		return (NULL);
	dup = ft_strdup(s);
	if (dup == NULL)
		return (NULL);
	p = dup;
	while (*p != '\0')
	{
		*p = f(p - dup, *p);
		p++;
	}
	return (dup);
}
