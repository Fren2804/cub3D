/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:58:02 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/30 14:46:00 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minimap.h"
#include "ray.h"
#include "vec2d.h"

static void	get_hv_rays(t_ray *rh, t_ray *rv, t_app *app)
{
	rh->len = DBL_MAX;
	if (rh->rdir.y != 0.0)
		ray_horizontals(rh, app);
	rv->len = DBL_MAX;
	if (rv->rdir.x != 0.0)
		ray_verticals(rv, app);
}

static void	ray_calculate(t_ray *ray, t_app *app)
{
	t_ray	rh;
	t_ray	rv;

	rh = *ray;
	rv = *ray;
	get_hv_rays(&rh, &rv, app);
	if (rh.len < rv.len)
	{
		*ray = rh;
		ray->face = FACE_NORTH;
		if (ray->rdir.y > 0.0)
			ray->face = FACE_SOUTH;
		return ;
	}
	*ray = rv;
	ray->face = FACE_WEST;
	if (ray->rdir.x > 0.0)
		ray->face = FACE_EAST;
}

t_ray	*ray_casting(t_app *app, int n_rays)
{
	t_ray	*rays;
	t_vec2d	pdir;
	int		i;
	double	f;

	if (app->map == NULL || n_rays <= 0)
		return (NULL);
	rays = ft_calloc(n_rays, sizeof(t_ray));
	if (rays == NULL)
		return (NULL);
	pdir.x = -app->dir_y * TAN_HALF_FOV;
	pdir.y = app->dir_x * TAN_HALF_FOV;
	i = -1;
	while (++i < n_rays)
	{
		f = (2.0 * i) / (n_rays - 1.0) - 1.0;
		rays[i].rdir.x = app->dir_x + f * pdir.x;
		rays[i].rdir.y = app->dir_y + f * pdir.y;
		vec2d_normalize(&rays[i].rdir);
		ray_calculate(rays + i, app);
	}
	return (rays);
}
