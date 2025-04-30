/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:07:26 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/27 18:30:11 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_size(t_game *game)
{
	int	lin;
	int	col;

	lin = 0;
	col = ft_strlen(game->map[0]);
	while (game->map[lin])
		lin++;
	game->width = (col * TILE_SIZE);
	game->height = (lin * TILE_SIZE);
	game->map_rows = lin;
	game->map_cols = col;
}

int	count_collec(t_game *game)
{
	int	count;
	int	y;
	int	x;

	y = 0;
	count = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
