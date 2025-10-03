/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:42:53 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/29 15:30:04 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "minimap.h"
# include "vec2d.h"

typedef enum s_face
{
	FACE_NORTH = 0,
	FACE_SOUTH,
	FACE_EAST,
	FACE_WEST,
}	t_face;

typedef struct s_ray
{
	t_vec2d	rdir;
	t_vec2d	colision;
	t_face	face;
	double	len;
	double	p_len;
}	t_ray;

t_ray	*ray_casting(t_app *app, int n_rays);
double	ray_horizontals(t_ray *ray, t_app *app);
double	ray_verticals(t_ray *ray, t_app *app);
#endif
