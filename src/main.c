/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:55:14 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/27 19:56:07 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_struct(t_game *game)
{
	game->mlx = NULL;
	game->map = NULL;
	game->width = 0;
	game->height = 0;
	game->map_rows = 0;
	game->map_cols = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->coins = 0;
	game->collected = 0;
	game->moves = 0;
	game->img_wall = NULL;
	game->img_floor = NULL;
	game->img_player = NULL;
	game->img_door = NULL;
	game->img_collec = NULL;
	game->texture = NULL;
	game->image = NULL;
}

int	main(int ac, char **av)
{
	t_game	game;

	init_game_struct(&game);
	check_args(ac, av);
	read_map(av[1], &game);
	if (!validate_size_lines_map(&game))
		free_map_print_error(game.map, NULL, NULL, \
			"Error : Invalid size map");
	validate_elements_map(game.map);
	if (!init_game(&game))
	{
		end_game(&game);
		free_map_print_error(NULL, NULL, NULL, \
			"Error: Failed to initialize");
	}
	return (0);
}
