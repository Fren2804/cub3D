/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:07:20 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/29 16:33:52 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "draw.h"
#include <stdint.h>

int	draw_rectangle(mlx_image_t *img, t_rectangle *rect, uint32_t color)
{
	uint32_t	ix;
	uint32_t	iy;

	if (img == NULL || rect == NULL)
		return (0);
	iy = 0;
	while (iy < rect->height)
	{
		ix = 0;
		while (ix < rect->width)
		{
			mlx_put_pixel(img, rect->pos.x + ix, rect->pos.y + iy, color);
			ix++;
		}
		iy++;
	}
	return (1);
}

void	draw_fill_image(mlx_image_t *img, uint32_t color)
{
	uint32_t	x;
	uint32_t	y;

	if (img == NULL)
		return ;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

int32_t	draw_abs_dif(int32_t a, int32_t b)
{
	if (a < b)
		return (b - a);
	return (a - b);
}
