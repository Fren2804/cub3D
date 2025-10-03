/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:08:50 by mvassall          #+#    #+#             */
/*   Updated: 2025/07/04 17:08:55 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_append_string(char *dst, char *str)
{
	char	*output;

	if (dst == NULL)
	{
		if (str == NULL)
			return (NULL);
		return (ft_strdup(str));
	}
	if (str == NULL)
		return (dst);
	output = ft_strjoin(dst, str);
	free(dst);
	return (output);
}

char	*ft_append_char(char *dst, char c)
{
	char	s[2];

	s[0] = c;
	s[1] = '\0';
	return (ft_append_string(dst, s));
}
