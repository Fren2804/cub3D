/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-23 16:49:31 by franmore          #+#    #+#             */
/*   Updated: 2025-09-23 16:49:31 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <math.h>
# include <stdio.h>
# include <stdint.h>
# include "map.h"
# include "minimap.h"

# define WIDTH  800
# define HEIGHT  620
# define TEXT_H 64
# define TEXT_W 64

typedef struct s_render
{
	int				column_x;
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	double			delta_x;
	double			delta_y;
	int				pos_x;
	int				pos_y;
	int				step_x;
	double			side_x;
	int				step_y;
	double			side_y;
	int				hit;
	int				side;
	double			perp_dist;
	int				line_h;
	int				draw_start;
	int				draw_end;
	unsigned int	color;
	int				y;
	int				x;
	double			wall_x;
	int				text_x;
	int				text_y;
	double			step;
	double			text_pos;
}	t_render;

typedef struct s_floor_ceil
{
	int				half_h;
	double			pos_z;
	double			ray_dir_x1;
	double			ray_dir_y1;
	double			ray_dir_x2;
	double			ray_dir_y2;
	double			vertical;
	double			row_distance;
	double			step_x;
	double			step_y;
	double			floor_x;
	double			floor_y;
	int				y_top;
	int				cell_x;
	int				cell_y;
	int				tx;
	int				ty;
	unsigned int	floor_rgba;
	unsigned int	ceil_rgba;
	int				y;
	int				x;
}	t_floor_ceil;

//Errors

int				ft_print_message_error(char *messg);
int				ft_check_textures(t_app *app);

//Init

void			ft_choose_ini(t_app *app);
void			ft_put_door(t_app *app);
int				ft_assign_door(t_app *app, int x, int y);
void			ft_assign_door_aux(t_app *app, int x, int y);
void			ft_assign_values(t_app *app, int x, int y, int dir);
void			ft_general_atributes(t_app *app, int x, int y);
void			ft_textures(t_app *app);
int				ft_init_mlx(t_app *app);
int				ft_hands(t_app *app);
int				ft_hands_aux(t_app *app, unsigned int width,
					unsigned int height, int i);

//Move

void			ft_handle_input(t_app *app, double dt);
void			ft_move(t_app *app, double new_x, double new_y,
					double distance_frame);
void			ft_rot(t_app *app, double rot_frame);
void			ft_try_move(t_app *app, double new_x, double new_y);
void			ft_sprite_hand(t_app *app);
void			ft_mouse_move(t_app *app);
void			ft_door_inputs(t_app *app);

//Render

void			ft_render(void *param);
unsigned int	ft_texel_rgba(const mlx_texture_t *text,
					unsigned int tx, unsigned int ty);
void			ft_put_pixel_safe(mlx_image_t *img, unsigned int x,
					unsigned int y, unsigned int rgba);
void			ft_modify_img(t_app *app);
void			ft_draw_columns(t_app *app);
void			ft_ray_dir_1(t_app *app, t_render *r);
void			ft_ray_dir_2(t_app *app, t_render *r);
void			ft_hit_1(t_app *app, t_render *r);
int				ft_hit_2(t_app *app, t_render *r);
void			ft_side_1(t_app *app, t_render *r);
void			ft_draw_1(t_app *app, t_render *r);
void			ft_draw_2(t_app *app, t_render *r);
void			ft_draw_3(t_app *app, t_render *r);

//Clean

void			ft_mlx_clean(t_app *app);
void			ft_clean_texts(t_app *app);

#endif