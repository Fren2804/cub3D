/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-26 19:13:59 by franmore          #+#    #+#             */
/*   Updated: 2025-09-26 19:13:59 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_assign_door_aux(t_app *app, int x, int y)
{
	app->x_door = x;
	app->y_door = y;
	app->map->plane[y][x] = '2';
}

int	ft_assign_door(t_app *app, int x, int y)
{
	if (app->map->plane[y - 1][x] == '1')
	{
		if (app->map->plane[y + 1][x] == '.')
			return (0);
		if (app->map->plane[y][x - 1] == '1')
			return (0);
		if (app->map->plane[y][x + 1] == '1')
			return (0);
		ft_assign_door_aux(app, x, y);
		return (1);
	}
	else
	{
		if (app->map->plane[y + 1][x] == '1')
			return (0);
		if (app->map->plane[y][x - 1] == '.')
			return (0);
		if (app->map->plane[y][x + 1] == '.')
			return (0);
		ft_assign_door_aux(app, x, y);
		return (1);
	}
}

void	ft_put_door(t_app *app)
{
	int	x;
	int	y;

	y = 2;
	while (y < app->map->n_lines - 2)
	{
		x = 2;
		while (x < app->map->n_columns - 2)
		{
			if (app->map->plane[y][x] == '1')
				if (ft_assign_door(app, x, y))
					return ;
			x ++;
		}
		y ++;
	}
	app->x_door = -3;
	app->y_door = -3;
}

void	ft_choose_ini(t_app *app)
{
	int	x;
	int	y;

	x = app->map->player_init_x;
	y = app->map->player_init_y;
	ft_put_door(app);
	if (app->map->player_init_dir == 'N')
		return (ft_assign_values(app, x, y, 'N'));
	else if (app->map->player_init_dir == 'E')
		return (ft_assign_values(app, x, y, 'E'));
	else if (app->map->player_init_dir == 'S')
		return (ft_assign_values(app, x, y, 'S'));
	else if (app->map->player_init_dir == 'W')
		return (ft_assign_values(app, x, y, 'W'));
}

int	ft_init_mlx(t_app *app)
{
	app->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!app->mlx)
		return (ft_print_message_error("Error, init mlx. \n"));
	app->img = mlx_new_image(app->mlx, WIDTH, HEIGHT);
	if (!app->img)
	{
		mlx_terminate(app->mlx);
		return (ft_print_message_error("Error, create img. \n"));
	}
	if (mlx_image_to_window(app->mlx, app->img, 0, 0) < 0)
	{
		mlx_delete_image(app->mlx, app->img);
		mlx_terminate(app->mlx);
		return (ft_print_message_error("Error, img to window. \n"));
	}
	return (0);
}
