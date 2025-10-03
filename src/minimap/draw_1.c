/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:05:43 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/29 16:33:00 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "draw.h"

static void	plot_low(mlx_image_t *img, t_point *p0, t_point *p1, uint32_t color)
{
	t_plot	v;

	v.dx = p1->x - p0->x;
	v.dy = p1->y - p0->y;
	v.inc = 1;
	if (v.dy < 0)
	{
		v.inc = -1;
		v.dy = -v.dy;
	}
	v.d = (2 * v.dy) - v.dx;
	v.y = p0->y;
	v.x = p0->x - 1;
	while (++v.x < p1->x)
	{
		mlx_put_pixel(img, v.x, v.y, color);
		if (v.d > 0)
		{
			v.y += v.inc;
			v.d += 2 * (v.dy - v.dx);
		}
		else
			v.d += 2 * v.dy;
	}
}

static void	plot_high(mlx_image_t *img, t_point *p0, t_point *p1,
	uint32_t color)
{
	t_plot	v;

	v.dx = p1->x - p0->x;
	v.dy = p1->y - p0->y;
	v.inc = 1;
	if (v.dx < 0)
	{
		v.inc = -1;
		v.dx = -v.dx;
	}
	v.d = (2 * v.dx) - v.dy;
	v.x = p0->x;
	v.y = p0->y - 1;
	while (++v.y < p1->y)
	{
		mlx_put_pixel(img, v.x, v.y, color);
		if (v.d > 0)
		{
			v.x += v.inc;
			v.d += 2 * (v.dx - v.dy);
		}
		else
			v.d += 2 * v.dx;
	}
}

static int	plot_v(mlx_image_t *img, t_point *p0, t_point *p1, uint32_t color)
{
	int32_t	y;
	t_point	*aux;

	if (p0->y == p1->y)
		return (1);
	if (p0->y > p1->y)
	{
		aux = p0;
		p0 = p1;
		p1 = aux;
	}
	y = p0->y - 1;
	while (++y < p1->y)
		mlx_put_pixel(img, p0->x, y, color);
	return (1);
}

static int	plot_h(mlx_image_t *img, t_point *p0, t_point *p1, uint32_t color)
{
	int32_t	x;
	t_point	*aux;

	if (p0->x == p1->x)
		return (1);
	if (p0->x > p1->x)
	{
		aux = p0;
		p0 = p1;
		p1 = aux;
	}
	x = p0->x - 1;
	while (++x < p1->x)
		mlx_put_pixel(img, x, p0->y, color);
	return (1);
}

int	draw_line(mlx_image_t *img, t_point *p0, t_point *p1, uint32_t color)
{
	int32_t	dx;
	int32_t	dy;

	dx = draw_abs_dif(p0->x, p1->x);
	dy = draw_abs_dif(p0->y, p1->y);
	if (dx == 0)
		return (plot_v(img, p0, p1, color));
	if (dy == 0)
		return (plot_h(img, p0, p1, color));
	if (dy < dx)
	{
		if (p0->x > p1->x)
			plot_low(img, p1, p0, color);
		else
			plot_low(img, p0, p1, color);
	}
	else
	{
		if (p0->y > p1->y)
			plot_high(img, p1, p0, color);
		else
			plot_high(img, p0, p1, color);
	}
	return (1);
}
