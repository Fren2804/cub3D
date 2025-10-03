/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:47:30 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/29 16:47:44 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "map.h"

/*
limits[0] min y
limits[1] max y
limits[2] min x
limits[3] max x
*/
static void	map_find_limits(t_map *map, int *limits)
{
	int	indx[2];

	limits[0] = map->n_lines;
	limits[1] = -1;
	limits[2] = map->n_columns;
	limits[3] = -1;
	indx[0] = -1;
	while (++indx[0] < map->n_lines)
	{
		indx[1] = -1;
		while (++indx[1] < map->n_columns)
		{
			if (map->plane[indx[0]][indx[1]] == EMPTY_CHAR)
			{
				if (indx[0] < limits[0])
					limits[0] = indx[0];
				if (indx[0] > limits[1])
					limits[1] = indx[0];
				if (indx[1] < limits[2])
					limits[2] = indx[1];
				if (indx[1] > limits[3])
					limits[3] = indx[1];
			}
		}
	}
}

static void	map_trim_lines(t_map *map, int min_y, int max_y)
{
	int		i;
	int		n;
	char	**p;

	n = max_y - min_y + 3;
	p = ft_calloc(n + 1, sizeof(char *));
	if (p == NULL)
		return ;
	i = -1;
	while (++i < n)
		p[i] = ft_strdup(map->plane[i + min_y - 1]);
	ft_dispose_split(map->plane);
	map->plane = p;
	map->n_lines = n;
}

static void	map_trim_columns(t_map *map, int min_x, int max_x)
{
	int		i;
	char	*p;

	i = -1;
	while (++i < map->n_lines)
	{
		p = ft_substr(map->plane[i], min_x - 1, max_x - min_x + 3);
		free(map->plane[i]);
		map->plane[i] = p;
	}
	map->n_columns = max_x - min_x + 3;
}

int	map_trim(t_map *map)
{
	int	limits[4];

	if (map == NULL)
		return (0);
	map_find_limits(map, limits);
	if (limits[0] > 1 || limits[1] < map->n_lines - 2)
		map_trim_lines(map, limits[0], limits[1]);
	if (limits[2] > 1 || limits[3] < map->n_columns - 2)
		map_trim_columns(map, limits[2], limits[3]);
	map->player_init_x -= (limits[2] - 1);
	map->player_init_y -= (limits[0] - 1);
	return (1);
}

void	map_normalize(t_map *map)
{
	int	i;
	int	j;

	if (map == NULL)
		return ;
	i = -1;
	while (++i < map->n_lines)
	{
		j = -1;
		while (++j < map->n_columns)
			if (map->plane[i][j] != EMPTY_CHAR)
				map->plane[i][j] = WALL_CHAR;
	}
}
