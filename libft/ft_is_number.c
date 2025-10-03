/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user1 <user1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:11:54 by user1             #+#    #+#             */
/*   Updated: 2025/03/04 11:15:04 by user1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_number(char *str)
{
	unsigned int	count_digits;

	if (str == NULL)
		return (0);
	while (*str && ft_isspace(*str))
		str++;
	if (*str && (*str == '-' || *str == '+'))
		str++;
	count_digits = 0;
	while (*str && ft_isdigit(*str))
	{
		count_digits++;
		str++;
	}
	while (*str && ft_isspace(*str))
		str++;
	if (*str != '\0')
		return (0);
	return (count_digits <= 10);
}
