/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 20:03:55 by franmore          #+#    #+#             */
/*   Updated: 2025/10/02 10:06:32 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_sprite_hand(t_app *app)
{
	double	now;
	double	diff;

	now = mlx_get_time();
	if (app->last_time_sprite == 0.0)
	{
		app->last_time_sprite = now;
	}
	diff = now - app->last_time_sprite;
	if (diff >= 0.1)
	{
		app->hands[app->sprite_hand]
			->instances[app->hand_instance[app->sprite_hand]].enabled = false;
		app->sprite_hand ++;
		if (app->sprite_hand == 5)
			app->sprite_hand = 0;
		app->hands[app->sprite_hand]
			->instances[app->hand_instance[app->sprite_hand]].enabled = true;
		app->last_time_sprite = now;
	}
}

void	ft_try_move(t_app *app, double new_x, double new_y)
{
	if (new_x < 0 || new_y < 0 || new_x >= app->map->n_columns
		|| new_y >= app->map->n_lines)
		return ;
	if (map_is_cell_wall(app->map, (int)new_x, (int)new_y))
		return ;
	ft_sprite_hand(app);
	app->position_x = new_x;
	app->position_y = new_y;
}

void	ft_rot(t_app *app, double rot_frame)
{
	double	aux_dir_x;
	double	aux_plane_x;

	aux_dir_x = app->dir_x;
	app->dir_x = aux_dir_x * cos(rot_frame) - app->dir_y * sin(rot_frame);
	app->dir_y = aux_dir_x * sin(rot_frame) + app->dir_y * cos(rot_frame);
	aux_plane_x = app->plane_x;
	app->plane_x = aux_plane_x * cos(rot_frame) - app->plane_y * sin(rot_frame);
	app->plane_y = aux_plane_x * sin(rot_frame) + app->plane_y * cos(rot_frame);
}

void	ft_move(t_app *app, double new_x, double new_y, double distance_frame)
{
	if (mlx_is_key_down(app->mlx, MLX_KEY_W))
	{
		new_x = app->position_x + distance_frame * app->dir_x;
		new_y = app->position_y + distance_frame * app->dir_y;
		ft_try_move(app, new_x, new_y);
	}
	if (mlx_is_key_down(app->mlx, MLX_KEY_D))
	{
		new_x = app->position_x + distance_frame * (-app->dir_y);
		new_y = app->position_y + distance_frame * app->dir_x;
		ft_try_move(app, new_x, new_y);
	}
	if (mlx_is_key_down(app->mlx, MLX_KEY_S))
	{
		new_x = app->position_x - distance_frame * app->dir_x;
		new_y = app->position_y - distance_frame * app->dir_y;
		ft_try_move(app, new_x, new_y);
	}
	if (mlx_is_key_down(app->mlx, MLX_KEY_A))
	{
		new_x = app->position_x + distance_frame * app->dir_y;
		new_y = app->position_y + distance_frame * (-app->dir_x);
		ft_try_move(app, new_x, new_y);
	}
	ft_door_inputs(app);
}

void	ft_handle_input(t_app *app, double dt)
{
	double	distance_frame;
	double	rot_frame;

	distance_frame = app->move_speed * dt;
	rot_frame = app->rot_speed * dt;
	ft_move(app, 0, 0, distance_frame);
	if (mlx_is_key_down(app->mlx, MLX_KEY_LEFT))
		ft_rot(app, -rot_frame);
	if (mlx_is_key_down(app->mlx, MLX_KEY_RIGHT))
		ft_rot(app, rot_frame);
	if (mlx_is_key_down(app->mlx, MLX_KEY_LEFT_SHIFT))
		if (app->move_speed < 8)
			app->move_speed += 0.2;
	if (mlx_is_key_down(app->mlx, MLX_KEY_LEFT_CONTROL))
		if (app->move_speed > 1)
			app->move_speed -= 0.2;
	if (mlx_is_key_down(app->mlx, MLX_KEY_M) && !app->key_m_press)
	{
		app->minimap_draw = !app->minimap_draw;
		app->key_m_press = 1;
	}
	if (!mlx_is_key_down(app->mlx, MLX_KEY_M))
		app->key_m_press = 0;
	ft_mouse_move(app);
}
