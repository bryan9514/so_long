/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:01:43 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/25 18:17:26 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(char **map, t_game *game)
{
	game->moves = 0;
	game->collected = 0;
	game->coins = count_collec(map);
	window_size(game, map);
	game->map = map;
	if (!init_window(game))
		return (0);
	if (!load_rscs(game))
		return (0);
	render_map(game);
	search_player(game);
	mlx_key_hook(game->mlx, my_keyhook, game);
	mlx_loop(game->mlx);
	return (1);
}
