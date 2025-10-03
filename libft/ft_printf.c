/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:29:31 by mvassall          #+#    #+#             */
/*   Updated: 2025/02/05 15:13:35 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Only implemented conversions 'csdiuxXp%' without parameters.
static int	proc_conversion(int fd, va_list vl, char cc)
{
	char	seq[3];

	if (cc == '\0')
		return (-1);
	if (cc == '%')
		return (ft_c_conversion(fd, '%'));
	if (cc == 'c')
		return (ft_c_conversion(fd, va_arg(vl, int)));
	if (cc == 's')
		return (ft_s_conversion(fd, va_arg(vl, char *)));
	if (cc == 'd' || cc == 'i')
		return (ft_d_conversion(fd, va_arg(vl, int)));
	if (cc == 'u')
		return (ft_u_conversion(fd, va_arg(vl, unsigned int)));
	if (cc == 'x' || cc == 'X')
		return (ft_x_conversion(fd, va_arg(vl, unsigned int), cc == 'X'));
	if (cc == 'p')
		return (ft_p_conversion(fd, va_arg(vl, void *)));
	seq[0] = '%';
	seq[1] = cc;
	seq[2] = '\0';
	return (ft_s_conversion(fd, seq));
}

// Common function for ft_dprintf and ft_printf
static int	internal_printf(int fd, const char *fmt, va_list va)
{
	int	length;
	int	in_conversion;
	int	rc;

	length = 0;
	in_conversion = 0;
	while (*fmt)
	{
		if (in_conversion)
		{
			rc = proc_conversion(fd, va, *fmt);
			if (rc < 0)
				return (rc);
			length += rc;
			in_conversion = 0;
		}
		else if (*fmt == '%')
			in_conversion = 1;
		else
			length += ft_c_conversion(fd, *fmt);
		fmt++;
	}
	if (in_conversion)
		return (-1);
	return (length);
}

// This version accepts file_descriptor.
int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	va;
	int		rc;

	va_start(va, fmt);
	rc = internal_printf(fd, fmt, va);
	va_end(va);
	return (rc);
}

// Requested mandatory function.
int	ft_printf(const char *fmt, ...)
{
	va_list	va;
	int		rc;

	va_start(va, fmt);
	rc = internal_printf(1, fmt, va);
	va_end(va);
	return (rc);
}
