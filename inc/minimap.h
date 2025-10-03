/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:51:48 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/30 14:46:58 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H
# include "map.h"
# include "MLX42/MLX42.h"

# define MINIMAP_BACKGROUND_COLOR	0x000000ff
# define MINIMAP_PLAYER_COLOR		0xff0000ff
# define MINIMAP_DOOR_COLOR     0x895129ff
# define MINIMAP_TILE_COLOR     0x808080ff
# define MINIMAP_RAY_COLOR		0xffff00ff
# define MINIMAP_N_RAYS			7
# define MINIMAP_SCALE			0.4
# define MINIMAP_MIN_TILESIZE	4
# define MINIMAP_PLAYER_SIZE	0.2
# define TAN_HALF_FOV			0.65 // tan(30,024 degrees)
# define DBL_MAX				1E+37

typedef struct s_app
{
	t_map			*map;
	mlx_t			*mlx;
	mlx_image_t		*img;
	double			position_x;
	double			position_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			rot_speed;
	double			last_time;
	int				height;
	int				width;
	int				last_mouse_x;
	int				last_mouse_y;
	int				mouse_inited;
	double			mouse_sens;
	mlx_texture_t	*text_wall_n;
	mlx_texture_t	*text_wall_e;
	mlx_texture_t	*text_wall_s;
	mlx_texture_t	*text_wall_w;
	mlx_texture_t	*texts[4];
	int				minimap_tilesize;
	int				minimap_draw;
	int				key_m_press;
	double			last_time_sprite;
	mlx_texture_t	*text_hands[6];
	int				sprite_hand;
	mlx_image_t		*hands[6];
	int				x_hand;
	int				y_hand;
	int				hand_instance[6];
	int				x_door;
	int				y_door;
	mlx_texture_t	*text_door;
	double			door_delay;
	int				door_opening;
	int				looking_door;
	int				is_door;
}	t_app;

void	minimap_draw(t_app *app);
void	minimap_calculate(t_app *app);
#endif
