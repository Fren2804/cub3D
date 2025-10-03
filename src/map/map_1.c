/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   map_1.c                                            :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mvassall <mvassall@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/09/01 15:40:49 by mvassall		  #+#	#+#			 */
/*   Updated: 2025/09/29 16:11:17 by mvassall         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include "map.h"
#include "libft.h"

t_map	*map_create(void)
{
	t_map	*m;

	m = ft_calloc(1, sizeof(t_map));
	if (m == NULL)
		return (m);
	m->floor_color = -1;
	m->ceiling_color = -1;
	return (m);
}

void	map_destroy(t_map **map)
{
	t_map	*m;
	int		i;

	if (map == NULL || *map == NULL)
		return ;
	m = *map;
	i = -1;
	while (++i < LAST_TEXTURE)
	{
		if (m->textures[i] != NULL)
		{
			free(m->textures[i]);
			m->textures[i] = NULL;
		}
	}
	if (m->plane != NULL)
		ft_dispose_split(m->plane);
	free(*map);
	*map = NULL;
}

char	**map_read_all_lines(int fd, int buffer_size)
{
	t_buf	*rbuf;
	void	**lines;
	char	*line;
	char	*pnl;

	rbuf = gnl_alloc_buf(buffer_size);
	if (rbuf == NULL)
		return (NULL);
	lines = NULL;
	while (1)
	{
		line = gnl_getline(fd, rbuf);
		if (line == NULL)
			break ;
		pnl = ft_strchr(line, '\n');
		if (pnl != NULL)
			*pnl = '\0';
		lines = ptr_array_append(lines, line);
	}
	gnl_dispose(rbuf);
	return ((char **)lines);
}

t_map	*map_readfd(int fd)
{
	t_map	*map;
	char	**lines;

	lines = map_read_all_lines(fd, MAP_BUFFER_SIZE);
	if (lines == NULL || ft_split_count(lines) <= 0)
		return (ft_dprintf(2, "Error\nEmpty file\n"), NULL);
	map = ft_calloc(1, sizeof(t_map));
	if (map == NULL)
	{
		ft_dispose_split(lines);
		return (NULL);
	}
	if (map_parse(lines, map) != map)
	{
		map_destroy(&map);
		ft_dispose_split(lines);
		return (NULL);
	}
	ft_dispose_split(lines);
	return (map);
}

t_map	*map_read(char *filename)
{
	t_map	*map;
	int		fd;
	size_t	len;

	if (filename == NULL)
		return (ft_dprintf(2, "Error\nNULL filename\n"), NULL);
	len = ft_strlen(filename);
	if (len < ft_strlen(".cub") || ft_strcmp(filename + len - 4, ".cub") != 0)
		return (ft_dprintf(2, "Error\nInvalid filename extension\n"), NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_dprintf(2, "Error\n");
		perror(filename);
		return (NULL);
	}
	map = map_readfd(fd);
	close(fd);
	return (map);
}
