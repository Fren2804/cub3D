/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 22:15:08 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/30 11:21:56 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"

int	map_set_player(t_map *map)
{
	int	jx;
	int	iy;
	int	found;

	if (map == NULL)
		return (0);
	found = 0;
	iy = -1;
	while (!found && ++iy < map->n_lines)
	{
		jx = -1;
		while (!found && ++jx < map->n_columns)
			found = ft_strchr("NSWE", map->plane[iy][jx]) != NULL;
	}
	if (!found)
		return (ft_dprintf(2, "Error\nProcessing player position\n"), 0);
	map->player_init_y = iy;
	map->player_init_x = jx;
	map->player_init_dir = map->plane[iy][jx];
	map->plane[iy][jx] = '0';
	return (1);
}

t_map	*map_check(t_map *map)
{
	if (map == NULL)
		return (NULL);
	if (!map_check_textures(map))
		return (NULL);
	if (!map_check_size(map))
		return (NULL);
	if (!map_adjust_lines(map))
		return (NULL);
	if (map_count_players(map) != 1 || !map_set_player(map))
		return (NULL);
	if (!map_walls_check(map))
		return (NULL);
	map_trim(map);
	map_normalize(map);
	return (map);
}

static int	flood(t_map *map, int x, int y)
{
	if (y < 0 || y >= map->n_lines || x < 0 || x >= map->n_columns)
		return (0);
	if (map->plane[y][x] != WALL_CHAR && map->plane[y][x] != EMPTY_CHAR)
	{
		map->plane[y][x] = EMPTY_CHAR;
		if (!flood(map, x, y - 1)
			|| !flood(map, x, y + 1)
			|| !flood(map, x - 1, y)
			|| !flood(map, x + 1, y))
			return (0);
	}
	return (1);
}

int	map_walls_check(t_map *map)
{
	if (map == NULL)
		return (0);
	if (!flood(map, map->player_init_x, map->player_init_y))
	{
		ft_dprintf(2, "Error\nMap not surrounded by walls\n");
		return (0);
	}
	return (1);
}

int	map_largest_line(char **lines)
{
	int	i;
	int	len;
	int	llen;

	if (lines == NULL)
		return (-1);
	i = -1;
	llen = 0;
	while (lines[++i] != NULL)
	{
		len = ft_strlen(lines[i]);
		if (len > llen)
			llen = len;
	}
	return (llen);
}
