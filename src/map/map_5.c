/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:39:08 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/29 16:18:47 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "stdlib.h"

int	map_get_cell(t_map *map, int x, int y)
{
	if (map == NULL || x < 0 || x >= map->n_columns
		|| y < 0 || y >= map->n_lines)
		return (-1);
	return (map->plane[y][x]);
}

int	map_is_cell_wall(t_map *map, int x, int y)
{
	return (map_get_cell(map, x, y) == WALL_CHAR
		|| map_get_cell(map, x, y) == DOOR_CHAR_OPEN
		|| map_get_cell(map, x, y) == DOOR_CHAR_CLOSE);
}

int	map_get_cell_d(t_map *map, double x, double y)
{
	int	i;
	int	j;

	if (map == NULL)
		return (-1);
	i = (int)y;
	j = (int)x;
	if (i < 0 || i >= map->n_lines || j < 0 || j >= map->n_columns)
		return (-1);
	return (map->plane[i][j]);
}

int	map_is_cell_wall_d(t_map *map, double x, double y)
{
	char	c;

	if (map == NULL)
		return (1);
	c = map_get_cell_d(map, x, y);
	if (c < 0)
		return (1);
	return (c == WALL_CHAR || c == DOOR_CHAR_CLOSE || c == DOOR_CHAR_OPEN);
}

int	map_is_cell_door(t_map *map, int x, int y)
{
	return (map_get_cell(map, x, y) == DOOR_CHAR_OPEN
		|| map_get_cell(map, x, y) == DOOR_CHAR_CLOSE);
}
