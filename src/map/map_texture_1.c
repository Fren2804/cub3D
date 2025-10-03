/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_texture_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:04:50 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/29 16:29:59 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "map.h"

void	map_texture_1(t_parser *p)
{
	while (ft_isspace(*p->cc))
		p->cc++;
	p->cw = NULL;
	p->words = NULL;
	if (ft_strchr("NSWE", *p->cc) != NULL)
	{
		p->cw = ft_append_char(p->cw, *p->cc);
		p->state = 2;
		return ;
	}
	p->state = -1;
	return ;
}

void	map_texture_2(t_parser *p)
{
	if (ft_strchr("OEA", *p->cc) != NULL)
	{
		p->cw = ft_append_char(p->cw, *p->cc);
		p->words = (char **)ptr_array_append((void **)p->words, p->cw);
		p->cw = NULL;
		p->state = 3;
		return ;
	}
	p->state = -1;
	return ;
}

void	map_texture_3(t_parser *p)
{
	if (ft_isspace(*p->cc))
	{
		p->state = 4;
		return ;
	}
	p->state = -1;
	return ;
}

void	map_texture_4(t_parser *p)
{
	while (ft_isspace(*p->cc))
		p->cc++;
	if (*p->cc == '"')
	{
		p->state = 6;
		return ;
	}
	if (ft_isprint(*p->cc))
	{
		p->cw = ft_append_char(p->cw, *p->cc);
		p->state = 5;
		return ;
	}
	p->state = -1;
}

void	map_texture_5(t_parser *p)
{
	while (ft_isprint(*p->cc))
	{
		p->cw = ft_append_char(p->cw, *p->cc);
		p->cc++;
	}
	p->words = (char **)ptr_array_append((void **)p->words, p->cw);
	p->cw = NULL;
	p->state = -1;
	if (*p->cc == '\0')
		p->state = 0;
	return ;
}
