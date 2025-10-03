/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-26 19:14:03 by franmore          #+#    #+#             */
/*   Updated: 2025-09-26 19:14:03 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_textures(t_app *app)
{
	app->text_wall_n = mlx_load_png(app->map->textures[0]);
	app->text_wall_s = mlx_load_png(app->map->textures[1]);
	app->text_wall_w = mlx_load_png(app->map->textures[2]);
	app->text_wall_e = mlx_load_png(app->map->textures[3]);
	app->texts[0] = app->text_wall_n;
	app->texts[1] = app->text_wall_e;
	app->texts[2] = app->text_wall_s;
	app->texts[3] = app->text_wall_w;
	app->text_hands[0] = mlx_load_png("textures/hand_1_1.png");
	app->text_hands[1] = mlx_load_png("textures/hand_1_2.png");
	app->text_hands[2] = mlx_load_png("textures/hand_2_3.png");
	app->text_hands[3] = mlx_load_png("textures/hand_2_3.png");
	app->text_hands[4] = mlx_load_png("textures/hand_3_3.png");
	app->text_hands[5] = mlx_load_png("textures/hand_3_1.png");
	app->sprite_hand = 0;
	app->text_door = mlx_load_png("textures/door.png");
}

void	ft_general_atributes(t_app *app, int x, int y)
{
	double	fov;

	app->position_x = x + 0.5;
	app->position_y = y + 0.5;
	fov = 0.65;
	app->plane_x = -app->dir_y * fov;
	app->plane_y = app->dir_x * fov;
	app->move_speed = 3.0;
	app->rot_speed = 2.0;
	app->last_time = 0.0;
	app->mouse_sens = 0.05;
	app->mouse_inited = 0;
	app->height = HEIGHT;
	app->width = WIDTH;
	app->last_time_sprite = 0.0;
	app->door_delay = 0.0;
	app->door_opening = 0;
	ft_textures(app);
}

void	ft_assign_values(t_app *app, int x, int y, int dir)
{
	if (dir == 'N')
	{
		app->dir_x = 0;
		app->dir_y = -1;
	}
	else if (dir == 'E')
	{
		app->dir_x = 1;
		app->dir_y = 0;
	}
	else if (dir == 'S')
	{
		app->dir_x = 0;
		app->dir_y = 1;
	}
	else
	{
		app->dir_x = -1;
		app->dir_y = 0;
	}
	ft_general_atributes(app, x, y);
}

int	ft_hands_aux(t_app *app, unsigned int width, unsigned int height, int i)
{
	i = 0;
	while (i < 6)
	{
		mlx_resize_image(app->hands[i], width, height);
		i ++;
	}
	app->x_hand = (WIDTH - app->hands[0]->width) / 2;
	app->y_hand = HEIGHT - app->hands[0]->height;
	if (app->y_hand < 0)
		app->y_hand = 0;
	i = 0;
	while (i < 6)
	{
		app->hand_instance[i] = mlx_image_to_window(app->mlx, app->hands[i],
				app->x_hand, app->y_hand);
		if (app->hand_instance[i] == -1)
			return (ft_print_message_error("Error. Hand instance. \n"));
		app->hands[i]->instances[app->hand_instance[i]].enabled = false;
		i ++;
	}
	app->hands[0]->instances[app->hand_instance[0]].enabled = true;
	return (0);
}

int	ft_hands(t_app *app)
{
	unsigned int	width;
	unsigned int	height;
	int				i;

	i = 0;
	while (i < 6)
	{
		app->hands[i] = mlx_texture_to_image(app->mlx, app->text_hands[i]);
		if (!app->hands[i])
			return (ft_print_message_error("Error. Hands text to image. \n"));
		i ++;
	}
	width = WIDTH / 2;
	height = HEIGHT / 4;
	if (ft_hands_aux(app, width, height, i))
		return (1);
	return (0);
}
