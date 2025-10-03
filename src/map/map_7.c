/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:58:14 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/30 11:22:34 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"

t_map	*map_check_textures(t_map *map)
{
	int			counter;
	int			i;
	static char	*labels[] = {
		"North", "South", "West", "East",
	};

	if (map == NULL)
		return (NULL);
	counter = 0;
	i = -1;
	while (++i < LAST_TEXTURE)
	{
		if (map->textures[i] == NULL)
		{
			ft_dprintf(2, "Error\n%s texture undefined\n", labels[i]);
			counter++;
			continue ;
		}
		if (!map_is_texture_ok(map->textures[i]))
			counter++;
	}
	if (counter != 0)
		return (NULL);
	return (map);
}
