/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:01:43 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/22 21:01:29 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	alloc_game(t_game **game, char **map)
{
	*game = malloc(sizeof(t_game));
	if (!*game)
		free_map_print_error(NULL, NULL, NULL, "Error: Memory \
			allocation failed");
	(*game)->map = map;
	(*game)->moves = 0;
	(*game)->collected = 0;
	(*game)->coins = count_collec(map);
}

int	init_game(char **map)
{
	t_game	*game;

	alloc_game(&game, map);
	window_size(game, map);
	if (!init_window(game))
	{
		free(game);
		return (0);
	}
	if (!load_rscs(game))
	{
		free(game);
		return (0);
	}
	render_map(game);
	search_player(game);
	mlx_key_hook(game->mlx, my_keyhook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	return (1);
}
