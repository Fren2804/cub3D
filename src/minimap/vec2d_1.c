/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:43:52 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/30 11:44:08 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2d.h"
#include "libft.h"
#include <math.h>

t_vec2d	*vec2d_create(double x, double y)
{
	t_vec2d	*v;

	v = ft_calloc(1, sizeof(t_vec2d));
	if (v == NULL)
		return (NULL);
	v->x = x;
	v->y = y;
	return (v);
}

void	vec2d_destroy(t_vec2d **v)
{
	if (v == NULL || *v == NULL)
		return ;
	free(*v);
	*v = NULL;
}

double	vec2d_length(t_vec2d *v)
{
	double	lenght;

	if (v == NULL)
		return (0.0);
	lenght = sqrt((v->x * v->x) + (v->y * v->y));
	return (lenght);
}

void	vec2d_normalize(t_vec2d *v)
{
	double	lenght;

	if (v == NULL)
		return ;
	lenght = vec2d_length(v);
	if (lenght == 0.0)
		return ;
	v->x /= lenght;
	v->y /= lenght;
}

double	vec2d_distance(t_vec2d *a, t_vec2d *b)
{
	double	dx;
	double	dy;

	if (a == NULL || b == NULL)
		return (0.0);
	dx = a->x - b->x;
	dy = a->y - b->y;
	return (sqrt(dx * dx + dy * dy));
}
