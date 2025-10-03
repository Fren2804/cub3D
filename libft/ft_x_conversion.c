/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user1 <user1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:29:31 by mvassall          #+#    #+#             */
/*   Updated: 2025/02/18 10:42:39 by user1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_x_conversion(int fd, unsigned long n, int is_uppercase)
{
	char	hdigits[2 * sizeof(unsigned long) + 1];
	int		i_last;
	char	*char_set;

	if (n == 0)
		return (ft_c_conversion(fd, '0'));
	char_set = "0123456789abcdef";
	if (is_uppercase)
		char_set = "0123456789ABCDEF";
	i_last = sizeof(hdigits) - 1;
	hdigits[i_last] = '\0';
	while (i_last > 0 && n != 0)
	{
		hdigits[--i_last] = char_set[n & 0x0f];
		n >>= 4;
	}
	return (ft_s_conversion(fd, hdigits + i_last));
}
