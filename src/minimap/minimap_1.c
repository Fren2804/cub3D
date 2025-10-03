/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:55:27 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/30 11:41:41 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "draw.h"
#include "minimap.h"
#include "ray.h"

static void	minimap_draw_map(t_app *app)
{
	t_rectangle	r;
	int			i;
	int			j;

	if (app == NULL || app->minimap_draw == 0)
		return ;
	r.width = app->minimap_tilesize - 1;
	r.height = r.width;
	i = -1;
	while (++i < app->map->n_lines)
	{
		j = -1;
		r.pos.y = i * app->minimap_tilesize;
		while (++j < app->map->n_columns)
		{
			if (!map_is_cell_wall_d(app->map, j, i))
				continue ;
			r.pos.x = j * app->minimap_tilesize;
			if (map_is_cell_door(app->map, j, i))
				draw_rectangle(app->img, &r, MINIMAP_DOOR_COLOR);
			else
				draw_rectangle(app->img, &r, MINIMAP_TILE_COLOR);
		}
	}
	return ;
}

static void	minimap_draw_rays(t_app *app, t_point	*player_position)
{
	uint32_t	i;
	t_ray		*rays;
	t_point		pcolision;

	rays = ray_casting(app, MINIMAP_N_RAYS);
	if (rays == NULL)
		return ;
	i = 0;
	while (i < MINIMAP_N_RAYS)
	{
		pcolision.x = app->minimap_tilesize * rays[i].colision.x;
		pcolision.y = app->minimap_tilesize * rays[i].colision.y;
		draw_line(app->img, player_position, &pcolision, MINIMAP_RAY_COLOR);
		i++;
	}
	free(rays);
}

static void	minimap_draw_player(t_app *app)
{
	t_circle	c;

	c.center.x = (app->position_x * app->minimap_tilesize);
	c.center.y = (app->position_y * app->minimap_tilesize);
	c.radius = (app->minimap_tilesize * MINIMAP_PLAYER_SIZE);
	minimap_draw_rays(app, &c.center);
	draw_circle(app->img, &c, MINIMAP_PLAYER_COLOR);
}

void	minimap_draw(t_app *app)
{
	t_rectangle	wallpaper;

	if (app == NULL || app->minimap_draw == 0 || app->minimap_tilesize == 0)
		return ;
	wallpaper.pos.x = 0;
	wallpaper.pos.y = 0;
	wallpaper.width = app->minimap_tilesize * app->map->n_columns;
	wallpaper.height = app->minimap_tilesize * app->map->n_lines;
	draw_rectangle(app->img, &wallpaper, MINIMAP_BACKGROUND_COLOR);
	minimap_draw_map(app);
	minimap_draw_player(app);
}

void	minimap_calculate(t_app *app)
{
	int	ts_y;
	int	ts;

	ts = round((app->img->width * MINIMAP_SCALE) / app->map->n_columns);
	ts_y = round((app->img->height * MINIMAP_SCALE) / app->map->n_lines);
	if (ts > ts_y)
		ts = ts_y;
	if (ts < MINIMAP_MIN_TILESIZE)
		ts = 0;
	app->minimap_tilesize = ts;
	app->minimap_draw = 0;
}
