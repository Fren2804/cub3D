/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 20:03:51 by franmore          #+#    #+#             */
/*   Updated: 2025/10/02 10:09:16 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "render.h"

void	ft_door_inputs(t_app *app)
{
	double	now;

	if (mlx_is_key_down(app->mlx, MLX_KEY_SPACE)
		&& !app->door_opening && app->looking_door)
	{
		now = mlx_get_time();
		app->door_delay = now;
		app->door_opening = 1;
	}
	now = mlx_get_time();
	if (now - app->door_delay >= 0.5 && app->door_opening)
	{
		app->door_opening = 0;
		if (app->map->plane[app->y_door][app->x_door] == DOOR_CHAR_CLOSE)
			app->map->plane[app->y_door][app->x_door] = EMPTY_CHAR;
		else if (app->map->plane[app->y_door][app->x_door] == EMPTY_CHAR)
			app->map->plane[app->y_door][app->x_door] = DOOR_CHAR_CLOSE;
	}
}

void	ft_mouse_move(t_app *app)
{
	int		mx;
	int		my;
	double	rot_mouse;

	if (!app->mouse_inited)
	{
		mlx_get_mouse_pos(app->mlx, &mx, &my);
		app->last_mouse_x = mx;
		app->last_mouse_y = my;
		app->mouse_inited = 1;
		return ;
	}
	mlx_get_mouse_pos(app->mlx, &mx, &my);
	rot_mouse = (mx - app->last_mouse_x) * app->mouse_sens;
	ft_rot(app, rot_mouse);
	app->last_mouse_x = mx;
	app->last_mouse_y = my;
}
