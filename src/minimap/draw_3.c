/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:03:18 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/29 16:46:37 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "draw.h"
#include <stdint.h>

static void	draw_points(mlx_image_t *img, t_point *center, t_point *p,
	uint32_t color)
{
	uint32_t	x;
	uint32_t	y;

	x = p->x;
	y = p->y;
	mlx_put_pixel(img, center->x + x, center->y + y, color);
	mlx_put_pixel(img, center->x - x, center->y + y, color);
	mlx_put_pixel(img, center->x + x, center->y - y, color);
	mlx_put_pixel(img, center->x - x, center->y - y, color);
	mlx_put_pixel(img, center->x + y, center->y + x, color);
	mlx_put_pixel(img, center->x - y, center->y + x, color);
	mlx_put_pixel(img, center->x + y, center->y - x, color);
	mlx_put_pixel(img, center->x - y, center->y - x, color);
}

static void	draw_lines(mlx_image_t *img, t_point *center, t_point *p,
	uint32_t color)
{
	t_point		p1;
	t_point		p2;
	uint32_t	x;
	uint32_t	y;

	x = p->x;
	y = p->y;
	p1.x = center->x - x;
	p1.y = center->y + y;
	p2.x = center->x + x;
	p2.y = p1.y;
	draw_line(img, &p1, &p2, color);
	p1.y = center->y - y;
	p2.y = p1.y;
	draw_line(img, &p1, &p2, color);
	p1.x = center->x - y;
	p1.y = center->y + x;
	p2.x = center->x + y;
	p2.y = p1.y;
	draw_line(img, &p1, &p2, color);
	p1.y = center->y - x;
	p2.y = p1.y;
	draw_line(img, &p1, &p2, color);
}

static int	internal_draw(mlx_image_t *img, t_circle *cf, uint32_t color,
	void (*f)(mlx_image_t *, t_point *, t_point *, uint32_t color))
{
	t_point	p;
	int		d;

	p.x = 0;
	p.y = cf->radius;
	d = 3 - 2 * cf->radius;
	f(img, &cf->center, &p, color);
	while (p.y >= p.x)
	{
		if (d > 0)
		{
			p.y--;
			d = d + 4 * (p.x - p.y);
		}
		else
		{
			d = d + 4 * p.x + 6;
		}
		p.x++;
		f(img, &cf->center, &p, color);
	}
	return (1);
}

int	draw_circumference(mlx_image_t *img, t_circle *cf, uint32_t color)
{
	return (internal_draw(img, cf, color, draw_points));
}

int	draw_circle(mlx_image_t *img, t_circle *cf, uint32_t color)
{
	return (internal_draw(img, cf, color, draw_lines));
}
