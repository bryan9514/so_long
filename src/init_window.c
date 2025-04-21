/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:22:49 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/21 16:52:44 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_hook(void *param)
{
	t_game *game = (t_game *)param;
	free_map(game->map);
	mlx_close_window(game->mlx);
}

int	init_window(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(game->width, game->height, "so_long", false);
	if (!game->mlx)
		return (0);
	mlx_close_hook(game->mlx, close_hook, game);
	return (1);
}
void	end_game(t_game *game)
{
	if (game->map)
		free_map(game->map);

	if (game->mlx)
		mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	ft_printf("Game closed\n");
	exit(0);
}
