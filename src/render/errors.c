/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-26 20:19:02 by franmore          #+#    #+#             */
/*   Updated: 2025-09-26 20:19:02 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "render.h"

int	ft_check_textures(t_app *app)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!app->texts[i])
			return (ft_print_message_error("Error. No texts wall. \n"));
		i ++;
	}
	i = 0;
	while (i < 6)
	{
		if (!app->text_hands[i])
			return (ft_print_message_error("Error. No texts hands. \n"));
		i ++;
	}
	if (!app->text_door)
		return (ft_print_message_error("Error. No texts door. \n"));
	return (0);
}

int	ft_print_message_error(char *messg)
{
	ft_dprintf(2, messg);
	return (1);
}
