/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 22:22:39 by user1             #+#    #+#             */
/*   Updated: 2025/09/30 14:46:09 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray.h"

static int	ray_verticals_p(t_ray *ray, t_app *app)
{
	double	y;
	double	x;
	double	delta;

	delta = ray->rdir.y / ray->rdir.x;
	x = floor(app->position_x) + 1.0;
	y = app->position_y + delta * (x - app->position_x);
	while (x < app->map->n_columns
		&& map_get_cell_d(app->map, x, y) == EMPTY_CHAR)
	{
		x += 1.0;
		y += delta;
	}
	if (x < app->map->n_columns && map_is_cell_wall_d(app->map, x, y))
	{
		ray->colision.x = x;
		ray->colision.y = y;
		ray->len = (x - app->position_x) / ray->rdir.x;
		return (1);
	}
	return (0);
}

static int	ray_verticals_n(t_ray *ray, t_app *app)
{
	double	y;
	double	x;
	double	delta;

	delta = ray->rdir.y / ray->rdir.x;
	x = floor(app->position_x);
	y = app->position_y + delta * (x - app->position_x);
	while (x > 0 && map_get_cell_d(app->map, x - 1.0, y) == EMPTY_CHAR)
	{
		x -= 1.0;
		y -= delta;
	}
	if (x > 0 && map_is_cell_wall_d(app->map, x - 1.0, y))
	{
		ray->colision.x = x;
		ray->colision.y = y;
		ray->len = (x - app->position_x) / ray->rdir.x;
		return (1);
	}
	return (0);
}

double	ray_verticals(t_ray *ray, t_app *app)
{
	if ((ray->rdir.x > 0.0 && ray_verticals_p(ray, app))
		|| (ray->rdir.x < 0.0 && ray_verticals_n(ray, app)))
	{
		ray->p_len = ray->len
			* (ray->rdir.x * app->dir_x + ray->rdir.y * app->dir_y);
		return (ray->len);
	}
	return (DBL_MAX);
}
