/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:21:57 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/21 11:06:52 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	render_map(t_game *game)
{
	int 	x;
	int		y;
	char	cel;

	y = 0;
	while (y < (game->height / TILE_SIZE))
	{
		x = 0;
		while (x < (game->width / TILE_SIZE))
		{
			cel = game->map[y][x];
			mlx_image_to_window(game->mlx, game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
			if (cel == '1')
				mlx_image_to_window(game->mlx, game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (cel == 'P')
				mlx_image_to_window(game->mlx, game->img_player, x * TILE_SIZE, y * TILE_SIZE);
			else if (cel == 'E')
				mlx_image_to_window(game->mlx, game->img_door, x * TILE_SIZE, y * TILE_SIZE);
			else if (cel == 'C')
				mlx_image_to_window(game->mlx, game->img_collec, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	search_player(t_game *game)
{
	int		x;
	int		y;
	char	cel;

	y = 0;
	while (y < (game->height / TILE_SIZE))
	{
		x = 0;
		while (x < (game-> width / TILE_SIZE))
		{
			cel = game->map[y][x];
			if (cel == 'P')
			{
				game->player_y = y;
				game->player_x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}
