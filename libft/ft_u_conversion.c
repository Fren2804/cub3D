/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user1 <user1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:29:31 by mvassall          #+#    #+#             */
/*   Updated: 2025/02/18 10:42:43 by user1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_u_conversion(int fd, unsigned int n)
{
	char	digits[MAX_DIGITS + 1];
	int		i_last;
	int		digit;

	if (n == 0)
		return (ft_c_conversion(fd, '0'));
	digits[MAX_DIGITS] = '\0';
	i_last = MAX_DIGITS;
	while (i_last > 0 && n != 0)
	{
		digit = n % 10;
		n /= 10;
		digits[--i_last] = '0' + digit;
	}
	return (ft_s_conversion(fd, digits + i_last));
}
