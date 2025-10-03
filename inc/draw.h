/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:51:55 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/29 15:41:41 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <stdint.h>
# include "MLX42/MLX42.h"

typedef struct s_point
{
	int32_t		x;
	int32_t		y;
}	t_point;

typedef struct s_plot
{
	int32_t	dx;
	int32_t	dy;
	int32_t	inc;
	int32_t	d;
	int32_t	x;
	int32_t	y;
}	t_plot;

typedef struct s_rectangle
{
	t_point		pos;
	uint32_t	width;
	uint32_t	height;
}	t_rectangle;

typedef struct s_circle
{
	t_point		center;
	uint32_t	radius;
}	t_circle;

int32_t		draw_abs_dif(int32_t a, int32_t b);
int			draw_line(mlx_image_t *img, t_point *p0, t_point *p1,
				uint32_t color);
int			draw_rectangle(mlx_image_t *img, t_rectangle *rect, uint32_t color);
int			draw_circumference(mlx_image_t *img, t_circle *cf,
				uint32_t color);
int			draw_circle(mlx_image_t *img, t_circle *cf, uint32_t color);
void		draw_fill_image(mlx_image_t *img, uint32_t color);
#endif
