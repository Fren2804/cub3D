/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:33:27 by mvassall          #+#    #+#             */
/*   Updated: 2025/03/04 19:50:28 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atol(const char *str)
{
	long int	val;
	int			is_positive;

	while (*str && ft_isspace(*str))
		str++;
	if (*str == '\0')
		return (0);
	is_positive = 1;
	if (*str == '+' || *str == '-')
	{
		is_positive = (*str != '-');
		str++;
	}
	val = 0;
	while (*str && ft_isdigit(*str))
		val = (val * 10) - (*str++ - '0');
	if (is_positive)
		return (-val);
	return (val);
}
