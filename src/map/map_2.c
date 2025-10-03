/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:13:58 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/29 16:14:03 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "map.h"
#include "libft.h"

int	map_is_empty_line(char *line)
{
	if (line == NULL)
		return (1);
	while (*line)
	{
		if (!ft_isspace(*line))
			return (0);
		line++;
	}
	return (1);
}

int	map_is_map_line(char *line)
{
	char	*p;
	int		wall_counter;

	if (line == NULL)
		return (0);
	wall_counter = 0;
	p = line;
	while (*p == ' ')
		p++;
	if (*p == WALL_CHAR)
	{
		p++;
		wall_counter++;
		while (*p && ft_strchr(" 01NSWE", *p) != NULL)
		{
			if (*p == WALL_CHAR)
				wall_counter++;
			p++;
		}
		if (*p == '\0')
			return (wall_counter > 1);
	}
	return (0);
}

void	map_print_plane(t_map *map)
{
	int	i;

	if (map == NULL)
		return ;
	if (map->plane == NULL)
	{
		ft_putendl_fd("plane: empty", 2);
		return ;
	}
	i = -1;
	ft_dprintf(2, "plane:\n");
	while (++i < map->n_lines)
	{
		if (i < 10)
			ft_dprintf(2, " %d: '%s'\n", i, map->plane[i]);
		else
			ft_dprintf(2, "%d: '%s'\n", i, map->plane[i]);
	}
}

int	map_print(t_map *map)
{
	if (map == NULL)
		return (0);
	ft_putendl_fd("\n### MAP:", 2);
	ft_dprintf(2, "NO: '%s'\nSO: '%s'\n",
		map->textures[NO_TEXTURE], map->textures[SO_TEXTURE]);
	ft_dprintf(2, "WE: '%s'\nEA: '%s'\n",
		map->textures[WE_TEXTURE], map->textures[EA_TEXTURE]);
	ft_dprintf(2, "F: %x\nC: %x\n", map->floor_color, map->ceiling_color);
	ft_dprintf(2, "n_lines: %d\nn_columns: %d\n", map->n_lines, map->n_columns);
	ft_dprintf(2, "player_init_x: %d\n", map->player_init_x);
	ft_dprintf(2, "player_init_y: %d\n", map->player_init_y);
	ft_dprintf(2, "player_init_dir: %c\n", map->player_init_dir);
	map_print_plane(map);
	return (1);
}

int	map_is_texture_ok(char *filename)
{
	int	fd;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("ERROR", 2);
		perror(filename);
		return (0);
	}
	close(fd);
	return (1);
}
