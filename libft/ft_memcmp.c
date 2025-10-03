/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:34:18 by mvassall          #+#    #+#             */
/*   Updated: 2024/12/11 11:46:16 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*uc1;
	const unsigned char	*uc2;

	if (!n)
		return (0);
	uc1 = s1;
	uc2 = s2;
	while (--n && (*uc1 == *uc2))
	{
		uc1++;
		uc2++;
	}
	return (*uc1 - *uc2);
}
