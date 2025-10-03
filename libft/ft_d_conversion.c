/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user1 <user1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:29:31 by mvassall          #+#    #+#             */
/*   Updated: 2025/02/18 10:41:06 by user1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_rc(int rc)
{
	if (rc < 0)
		return (rc);
	return (rc);
}

int	ft_d_conversion(int fd, int n)
{
	int		is_negative;
	char	digits[MAX_DIGITS];
	int		i_last;
	int		digit;
	int		rc;

	if (n == 0)
		return (ft_c_conversion(fd, '0'));
	is_negative = (n < 0);
	i_last = MAX_DIGITS - 1;
	digits[i_last] = '\0';
	while (i_last > 0 && n != 0)
	{
		digit = n % 10;
		n /= 10;
		if (digit < 0)
			digit = -digit;
		digits[--i_last] = '0' + digit;
	}
	if (is_negative)
		digits[--i_last] = '-';
	rc = ft_s_conversion(fd, digits + i_last);
	return (check_rc(rc));
}
