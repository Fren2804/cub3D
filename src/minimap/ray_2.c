/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 20:26:03 by user1             #+#    #+#             */
/*   Updated: 2025/09/30 14:46:05 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "map.h"
#include "ray.h"

static int	ray_horizontal_p(t_ray *ray, t_app *app)
{
	double	y;
	double	x;
	double	delta;

	delta = ray->rdir.x / ray->rdir.y;
	y = floor(app->position_y) + 1.0;
	x = app->position_x + delta * (y - app->position_y);
	while (y < app->map->n_lines
		&& map_get_cell_d(app->map, x, y) == EMPTY_CHAR)
	{
		y += 1.0;
		x += delta;
	}
	if (y < app->map->n_lines && map_is_cell_wall_d(app->map, x, y))
	{
		ray->colision.x = x;
		ray->colision.y = y;
		ray->len = (y - app->position_y) / ray->rdir.y;
		return (1);
	}
	return (0);
}

static int	ray_horizontal_n(t_ray *ray, t_app *app)
{
	double	y;
	double	x;
	double	delta;

	delta = ray->rdir.x / ray->rdir.y;
	y = floor(app->position_y);
	x = app->position_x + delta * (y - app->position_y);
	while (y > 0 && map_get_cell_d(app->map, x, y - 1.0) == EMPTY_CHAR)
	{
		y -= 1.0;
		x -= delta;
	}
	if (y > 0 && map_is_cell_wall_d(app->map, x, y - 1.0))
	{
		ray->colision.x = x;
		ray->colision.y = y;
		ray->len = (y - app->position_y) / ray->rdir.y;
		return (1);
	}
	return (0);
}

double	ray_horizontals(t_ray *ray, t_app *app)
{
	if ((ray->rdir.y > 0.0 && ray_horizontal_p(ray, app))
		|| (ray->rdir.y < 0.0 && ray_horizontal_n(ray, app)))
	{
		ray->p_len = ray->len
			* (ray->rdir.x * app->dir_x + ray->rdir.y * app->dir_x);
		return (ray->len);
	}
	return (DBL_MAX);
}
