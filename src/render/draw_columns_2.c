/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_columns_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-26 20:03:35 by franmore          #+#    #+#             */
/*   Updated: 2025-09-26 20:03:35 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_draw_3(t_app *app, t_render *r)
{
	if (r->side == 2)
	{
		r->color = ft_texel_rgba(app->texts[2],
				(unsigned int)r->text_x, (unsigned int)r->text_y);
		mlx_put_pixel(app->img, (unsigned int)r->x,
			(unsigned int)r->y, r->color);
	}
	else
	{
		r->color = ft_texel_rgba(app->texts[3],
				(unsigned int)r->text_x, (unsigned int)r->text_y);
		mlx_put_pixel(app->img, (unsigned int)r->x,
			(unsigned int)r->y, r->color);
	}
}

void	ft_draw_2(t_app *app, t_render *r)
{
	if (r->side == 0)
	{
		r->color = ft_texel_rgba(app->texts[0],
				(unsigned int)r->text_x, (unsigned int)r->text_y);
		mlx_put_pixel(app->img, (unsigned int)r->x,
			(unsigned int)r->y, r->color);
	}
	else if (r->side == 1)
	{
		r->color = ft_texel_rgba(app->texts[1],
				(unsigned int)r->text_x, (unsigned int)r->text_y);
		mlx_put_pixel(app->img, (unsigned int)r->x,
			(unsigned int)r->y, r->color);
	}
	else
		ft_draw_3(app, r);
}

void	ft_draw_1(t_app *app, t_render *r)
{
	while (r->y <= r->draw_end)
	{
		r->text_y = (int)r->text_pos;
		if (r->text_y < 0)
			r->text_y = 0;
		if (r->text_y >= TEXT_H)
			r->text_y = TEXT_H - 1;
		if (app->is_door)
		{
			r->color = ft_texel_rgba(app->text_door, (unsigned int)r->text_x,
					(unsigned int)r->text_y);
			mlx_put_pixel(app->img, (unsigned int)r->x,
				(unsigned int)r->y, r->color);
		}
		else
		{
			ft_draw_2(app, r);
		}
		r->text_pos += r->step;
		r->y ++;
	}
}

void	ft_side_2(t_render *r)
{
	r->wall_x -= floor(r->wall_x);
	r->text_x = (int)(r->wall_x * (double)TEXT_W);
	if ((r->side == 0 && r->raydir_x > 0.0)
		|| (r->side == 2 && r->raydir_y < 0.0))
		r->text_x = TEXT_W - 1 - r->text_x;
	r->step = (double)64 / (double)r->line_h;
	r->text_pos = ((double)r->draw_start - (double)HEIGHT
			/ 2.0 + (double)r->line_h / 2.0) * r->step;
}

void	ft_side_1(t_app *app, t_render *r)
{
	if (r->side == 0 || r->side == 1)
		r->perp_dist = (r->pos_x - app->position_x
				+ (1.0 - r->step_x) * 0.5) / r->raydir_x;
	else
		r->perp_dist = (r->pos_y - app->position_y
				+ (1.0 - r->step_y) * 0.5) / r->raydir_y;
	if (r->perp_dist <= 0.0001)
		r->perp_dist = 0.0001;
	r->line_h = (int)((double)HEIGHT / r->perp_dist);
	r->draw_start = -r->line_h / 2 + HEIGHT / 2;
	r->draw_end = r->line_h / 2 + HEIGHT / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	if (r->draw_end >= HEIGHT)
		r->draw_end = HEIGHT - 1;
	if (r->side == 0 || r->side == 1)
		r->wall_x = app->position_y + r->perp_dist * r->raydir_y;
	else
		r->wall_x = app->position_x + r->perp_dist * r->raydir_x;
	ft_side_2(r);
}
