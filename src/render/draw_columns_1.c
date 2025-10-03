/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_columns_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-26 20:03:41 by franmore          #+#    #+#             */
/*   Updated: 2025-09-26 20:03:41 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	ft_hit_2(t_app *app, t_render *r)
{
	if (r->pos_x < 0 || r->pos_y < 0 || r->pos_x >= app->map->n_columns
		|| r->pos_y >= app->map->n_lines)
	{
		r->hit = 1;
		return (1);
	}
	if (map_is_cell_wall(app->map, r->pos_x, r->pos_y))
		r->hit = 1;
	if (r->pos_x == app->x_door && r->pos_y == app->y_door)
	{
		if (fabs(app->position_x - app->x_door) <= 3
			&& fabs(app->position_y - app->y_door) <= 3)
			app->looking_door = 1;
		app->is_door = 1;
	}
	else
		app->is_door = 0;
	return (0);
}

void	ft_hit_1(t_app *app, t_render *r)
{
	r->hit = 0;
	r->side = 0;
	while (!r->hit)
	{
		if (r->side_x < r->side_y)
		{
			r->side_x += r->delta_x;
			r->pos_x += r->step_x;
			if (r->step_x == 1)
				r->side = 0;
			else
				r->side = 1;
		}
		else
		{
			r->side_y += r->delta_y;
			r->pos_y += r->step_y;
			if (r->step_y == 1)
				r->side = 2;
			else
				r->side = 3;
		}
		if (ft_hit_2(app, r))
			break ;
	}
}

void	ft_ray_dir_2(t_app *app, t_render *r)
{
	if (r->raydir_x < 0.0)
	{
		r->step_x = -1;
		r->side_x = (app->position_x - r->pos_x) * r->delta_x;
	}
	else
	{
		r->step_x = 1;
		r->side_x = (r->pos_x + 1.0 - app->position_x) * r->delta_x;
	}
	if (r->raydir_y < 0.0)
	{
		r->step_y = -1;
		r->side_y = (app->position_y - r->pos_y) * r->delta_y;
	}
	else
	{
		r->step_y = 1;
		r->side_y = (r->pos_y + 1.0 - app->position_y) * r->delta_y;
	}
}

void	ft_ray_dir_1(t_app *app, t_render *r)
{
	r->column_x = r->x;
	r->camera_x = (2.0 * (double)r->x / (double)WIDTH) - 1.0;
	r->raydir_x = app->dir_x + app->plane_x * r->camera_x;
	r->raydir_y = app->dir_y + app->plane_y * r->camera_x;
	if (r->raydir_x == 0)
		r->delta_x = 1e30;
	else
		r->delta_x = fabs(1.0 / r->raydir_x);
	if (r->raydir_y == 0)
		r->delta_y = 1e30;
	else
		r->delta_y = fabs(1.0 / r->raydir_y);
	r->pos_x = (int)app->position_x;
	r->pos_y = (int)app->position_y;
	ft_ray_dir_2(app, r);
}

void	ft_draw_columns(t_app *app)
{
	t_render	r;

	app->looking_door = 0;
	r.x = 0;
	while (r.x < WIDTH)
	{
		ft_ray_dir_1(app, &r);
		ft_hit_1(app, &r);
		ft_side_1(app, &r);
		r.y = r.draw_start;
		ft_draw_1(app, &r);
		r.x++;
	}
}
