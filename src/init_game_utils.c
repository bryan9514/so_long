/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:07:26 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/21 14:08:27 by brturcio         ###   ########.fr       */
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
	return(count);
}
