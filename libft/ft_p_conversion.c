/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user1 <user1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:29:31 by mvassall          #+#    #+#             */
/*   Updated: 2025/02/18 10:41:53 by user1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_p_conversion(int fd, void *ptr)
{
	int	rc;

	if (ptr == NULL)
		return (ft_s_conversion(fd, "(nil)"));
	rc = ft_s_conversion(fd, "0x");
	if (rc < 0)
		return (rc);
	rc = ft_x_conversion(fd, (unsigned long)ptr, 0);
	if (rc < 0)
		return (rc);
	return (rc + 2);
}
