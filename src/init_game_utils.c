/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:07:26 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/22 17:13:48 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_size(t_game *game, char **map)
{
	int	lin;
	int	col;

	lin = 0;
	col = ft_strlen(map[0]);
	while (map[lin])
		lin++;
	game->width = (col * TILE_SIZE);
	game->height = (lin * TILE_SIZE);
	game->map_rows = lin;
	game->map_cols = col;
}

int	count_collec(char **map)
{
	int	count;
	int	y;
	int	x;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
