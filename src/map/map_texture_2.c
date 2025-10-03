/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_texture_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:02:10 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/29 16:30:35 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "map.h"

void	map_texture_6(t_parser *p)
{
	if (*p->cc == '\\')
	{
		p->state = 8;
		return ;
	}
	if (ft_isprint(*p->cc))
	{
		p->cw = ft_append_char(p->cw, *p->cc);
		p->state = 7;
		return ;
	}
	p->state = -1;
}

void	map_texture_7(t_parser *p)
{
	if (*p->cc == '\\')
	{
		p->state = 8;
		return ;
	}
	if (*p->cc == '\"')
	{
		p->words = (char **)ptr_array_append((void **)p->words, p->cw);
		p->cw = NULL;
		p->state = 9;
		return ;
	}
	if (ft_isprint(*p->cc))
	{
		p->cw = ft_append_char(p->cw, *p->cc);
		return ;
	}
	p->state = -1;
}

void	map_texture_8(t_parser *p)
{
	if (*p->cc == '\"' || *p->cc == '\\')
	{
		p->cw = ft_append_char(p->cw, *p->cc);
		p->state = 7;
		return ;
	}
	p->state = -1;
	return ;
}

void	map_texture_9(t_parser *p)
{
	while (ft_isspace(*p->cc))
		p->cc++;
	if (*p->cc == '\0' || *p->cc == '\n')
	{
		p->state = 0;
		return ;
	}
	p->state = -1;
}
