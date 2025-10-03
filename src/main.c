/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-23 17:14:53 by franmore          #+#    #+#             */
/*   Updated: 2025-09-23 17:14:53 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include "render.h"

void	ft_clean_texts(t_app *app)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_delete_texture(app->texts[i]);
		i ++;
	}
	i = 0;
	while (i < 6)
	{
		mlx_delete_texture(app->text_hands[i]);
		mlx_delete_image(app->mlx, app->hands[i]);
		i ++;
	}
	mlx_delete_texture(app->text_door);
}

void	ft_mlx_clean(t_app *app)
{
	map_destroy(&app->map);
	ft_clean_texts(app);
	mlx_delete_image(app->mlx, app->img);
	app->img = NULL;
	mlx_terminate(app->mlx);
	app->mlx = NULL;
}

int	main(int argc, char *argv[])
{
	t_app	app;

	if (argc != 2)
		return (ft_print_message_error("Error. Incorrect number of args. \n"));
	app.map = map_read(argv[1]);
	if (!app.map)
		return (1);
	ft_choose_ini(&app);
	map_print(app.map);
	if (ft_check_textures(&app) || ft_init_mlx(&app))
		return (1);
	if (ft_hands(&app))
		return (1);
	minimap_calculate(&app);
	mlx_loop_hook(app.mlx, ft_render, &app);
	mlx_loop(app.mlx);
	ft_mlx_clean(&app);
	return (0);
}
