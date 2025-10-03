/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:52:34 by mvassall          #+#    #+#             */
/*   Updated: 2025/07/25 16:57:01 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_int(char *str)
{
	unsigned int	count_digits;

	if (str == NULL)
		return (0);
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	if (*str && (*str == '-' || *str == '+'))
		str++;
	count_digits = 0;
	while (*str && ('0' <= *str && *str <= '9'))
	{
		count_digits++;
		str++;
	}
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	if (*str != '\0')
		return (0);
	return (count_digits <= 10);
}

uint64_t	ft_get_time_us(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (uint64_t)1000000) + tv.tv_usec);
}
