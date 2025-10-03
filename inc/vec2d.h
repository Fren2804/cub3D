/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:42:03 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/29 15:30:57 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2D_H
# define VEC2D_H

typedef struct s_vec2d
{
	double	x;
	double	y;
}	t_vec2d;

typedef double	*t_rotation;

t_vec2d	*vec2d_create(double x, double y);
void	vec2d_destroy(t_vec2d **v);
double	vec2d_length(t_vec2d *v);
void	vec2d_normalize(t_vec2d *v);
double	vec2d_distance(t_vec2d *a, t_vec2d *b);
int		vec2d_gen_rotation(t_rotation m, double angle_rad);
int		vec2d_gen_rotation_degree(t_rotation m, double angle_degrees);
int		vec2d_rotate(t_vec2d *v, t_rotation r);
#endif
