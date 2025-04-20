/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:07:26 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/20 21:13:20 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_size(t_game *game, char **map)
{
	int	i;

	i = 0;
	game->width = (ft_strlen(map[0]) * TILE_SIZE);
	while (map[i])
		i++;
	game->height = (i * TILE_SIZE);
}

int	init_window(t_game *game)
{
	game->mlx = mlx_init(game->width, game->height, "so_long", false);
	if (!game->mlx)
		return (0);
	mlx_close_hook(game->mlx, close_hook, game);
	return (1);
}
