/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:33:27 by mvassall          #+#    #+#             */
/*   Updated: 2025/02/15 11:59:00 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	val;
	int	is_positive;

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
