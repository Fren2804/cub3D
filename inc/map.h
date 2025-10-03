/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:26:21 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/30 11:22:49 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <stdint.h>

# define MAP_BUFFER_SIZE 4096
# define WALL_CHAR   '1'
# define DOOR_CHAR_CLOSE  '2'
# define DOOR_CHAR_OPEN  '3'
# define EMPTY_CHAR  '.'

typedef enum e_tags
{
	NO_TEXTURE = 0,
	SO_TEXTURE,
	WE_TEXTURE,
	EA_TEXTURE,
	LAST_TEXTURE,
}	t_tags;

typedef struct s_map
{
	char		*textures[LAST_TEXTURE];
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	int			n_lines;
	int			n_columns;
	char		**plane;
	int			player_init_y;
	int			player_init_x;
	char		player_init_dir;
}	t_map;

typedef struct s_parser
{
	int		state;
	char	*cc;
	char	*cw;
	char	**words;
}	t_parser;

// General usage
t_map	*map_create(void);
void	map_destroy(t_map **map);
int		map_print(t_map *map);
t_map	*map_read(char *filename);
int		map_get_cell(t_map *map, int x, int y);
//0 es vacio 1 es muro
int		map_is_cell_wall(t_map *map, int x, int y);
int		map_is_cell_wall_d(t_map *map, double x, double y);
int		map_get_cell_d(t_map *map, double x, double y);
int		map_is_cell_door(t_map *map, int x, int y);

// Internal routines
t_map	*map_readfd(int fd);
char	**map_read_all_lines(int fd, int buffer_size);
t_map	*map_parse(char **lines, t_map *map);
int		map_is_empty_line(char *line);
int		map_is_map_line(char *line);
int		map_count_players(t_map *map);
void	map_print_parsing_status(t_parser *p);
void	map_texture_1(t_parser *p);
void	map_texture_2(t_parser *p);
void	map_texture_3(t_parser *p);
void	map_texture_4(t_parser *p);
void	map_texture_5(t_parser *p);
void	map_texture_6(t_parser *p);
void	map_texture_7(t_parser *p);
void	map_texture_8(t_parser *p);
void	map_texture_9(t_parser *p);
int		map_is_texture_line(char *line, t_map *map);
int		map_is_texture_ok(char *filename);
t_map	*map_check_textures(t_map *map);
int		map_largest_line(char **lines);
void	map_color1(t_parser *p);
void	map_color2(t_parser *p);
void	map_color3(t_parser *p);
void	map_color4(t_parser *p);
void	map_color5(t_parser *p);
int		map_is_color_line(char *line, t_map *map);
int		map_adjust_lines(t_map *map);
char	*map_trim_right(char *line);
t_map	*map_check(t_map *map);
int		map_check_size(t_map *map);
int		map_set_player(t_map *map);
int		map_walls_check(t_map *map);
int		map_trim(t_map *map);
void	map_normalize(t_map *map);
//debug
void	map_print_plane(t_map *map);
#endif
