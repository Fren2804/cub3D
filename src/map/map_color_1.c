/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_color_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:51:42 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/29 16:25:51 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"

void	map_color1(t_parser *p)
{
	while (*p->cc == ' ')
		p->cc++;
	if (*p->cc == 'C' || *p->cc == 'F')
	{
		p->cw = ft_append_char(p->cw, *p->cc);
		p->words = (char **)ptr_array_append((void **)p->words, p->cw);
		p->cw = NULL;
		p->state = 2;
		return ;
	}
	p->state = -1;
	return ;
}

void	map_color2(t_parser *p)
{
	while (*p->cc == ' ')
		p->cc++;
	if (ft_isdigit(*p->cc))
	{
		p->cw = ft_append_char(p->cw, *p->cc);
		p->state = 3;
		return ;
	}
	p->state = -1;
}

void	map_color3(t_parser *p)
{
	while (ft_isdigit(*p->cc))
	{
		p->cw = ft_append_char(p->cw, *p->cc);
		p->cc++;
	}
	p->words = (char **)ptr_array_append((void **)p->words, p->cw);
	p->cw = NULL;
	if (*p->cc == ' ')
		p->state = 4;
	else if (*p->cc == ',')
		p->state = 5;
	else if (*p->cc == '\0' || *p->cc == '\n')
		p->state = 0;
	else
		p->state = -1;
	return ;
}

void	map_color4(t_parser *p)
{
	while (*p->cc == ' ')
		p->cc++;
	if (*p->cc == ',')
		p->state = 5;
	else if (*p->cc == '\0' || *p->cc == '\n')
		p->state = 0;
	else
		p->state = -1;
	return ;
}

void	map_color5(t_parser *p)
{
	while (*p->cc == ' ')
		p->cc++;
	if (ft_isdigit(*p->cc))
	{
		p->cw = ft_append_char(p->cw, *p->cc);
		p->state = 3;
		return ;
	}
	p->state = -1;
	return ;
}
