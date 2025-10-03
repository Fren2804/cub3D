/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-26 20:03:48 by franmore          #+#    #+#             */
/*   Updated: 2025-09-26 20:03:48 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_modify_img(t_app *app)
{
	unsigned int	color;
	int				x;
	int				y;

	y = 0;
	while (y < HEIGHT)
	{
		if (y < app->height / 2)
		{
			color = app->map->ceiling_color;
		}
		else
		{
			color = app->map->floor_color;
		}
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(app->img, x, y, color);
			x ++;
		}
		y ++;
	}
}

void	ft_put_pixel_safe(mlx_image_t *img, unsigned int x,
		unsigned int y, unsigned int rgba)
{
	if (!img)
	{
		printf("Put pixel safe img error \n");
		return ;
	}
	if (x >= img->width || y >= img->height)
		return ;
	mlx_put_pixel(img, x, y, rgba);
}

unsigned int	ft_texel_rgba(const mlx_texture_t *text,
		unsigned int tx, unsigned int ty)
{
	int				texel_index;
	unsigned char	*p;
	unsigned int	color;

	if (!text)
	{
		printf("Texel error rgba \n");
		return (0);
	}
	if (tx >= text->width || ty >= text->height)
		return (0);
	texel_index = ty * text->width + tx;
	p = &text->pixels[texel_index * 4];
	color = ((unsigned int)p[0] << 24) | ((unsigned int)p[1] << 16)
		| ((unsigned int)p[2] << 8) | ((unsigned int)p[3]);
	return (color);
}

void	ft_render(void *param)
{
	t_app	*app;
	double	now;
	double	dt;

	app = (t_app *)param;
	now = mlx_get_time();
	if (app->last_time == 0.0)
		app->last_time = now;
	dt = now - app->last_time;
	app->last_time = now;
	ft_modify_img(app);
	ft_draw_columns(app);
	minimap_draw(app);
	ft_handle_input(app, dt);
	if (mlx_is_key_down(app->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(app->mlx);
}
