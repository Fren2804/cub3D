/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:52:11 by mvassall          #+#    #+#             */
/*   Updated: 2025/01/10 15:14:09 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*zero_str(void)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static int	count_digits(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*get_digits(char *digits, int n_digits, int n)
{
	int	digit;

	digits[n_digits] = '\0';
	if (n < 0)
		digits[0] = '-';
	while (n != 0)
	{
		digit = n % 10;
		if (digit < 0)
			digit = -digit;
		digits[--n_digits] = '0' + digit;
		n /= 10;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*digits;
	int		n_digits;

	if (n == 0)
		return (zero_str());
	n_digits = count_digits(n);
	if (n < 0)
		n_digits++;
	digits = (char *)malloc((n_digits + 1) * sizeof(char));
	if (digits == NULL)
		return (NULL);
	return (get_digits(digits, n_digits, n));
}
