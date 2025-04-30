/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:21:57 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/27 21:03:12 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	render_map2(t_game *game, char cel, int x, int y)
// {
// 	mlx_image_to_window(game->mlx, game->img_floor, x, y);
// 	if (cel == '1')
// 		mlx_image_to_window(game->mlx, game->img_wall, x, y);
// 	else if (cel == 'P')
// 		mlx_image_to_window(game->mlx, game->img_player, x, y);
// 	else if (cel == 'E')
// 		mlx_image_to_window(game->mlx, game->img_door, x, y);
// 	else if (cel == 'C')
// 		mlx_image_to_window(game->mlx, game->img_collec, x, y);
// }
void	render_map2(t_game *game, char cel, int x, int y)
{
	mlx_image_to_window(game->mlx, game->img_floor, x, y); // Suelo siempre

	if (cel == '1')
		mlx_image_to_window(game->mlx, game->img_wall, x, y);
	else if (cel == 'E')
		mlx_image_to_window(game->mlx, game->img_door, x, y);
	else if (cel == 'C')
		mlx_image_to_window(game->mlx, game->img_collec, x, y); // Se crean instancias
}


void	render_map(t_game *game)
{
	int		x;
	int		y;
	int		x_size_img;
	int		y_size_img;
	char	cel;

	y = 0;
	while (y < game->map_rows)
	{
		x = 0;
		while (x < game->map_cols)
		{
			cel = game->map[y][x];
			x_size_img = x * TILE_SIZE;
			y_size_img = y * TILE_SIZE;
			render_map2(game, cel, x_size_img, y_size_img);
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
	while (y < game->map_rows)
	{
		x = 0;
		while (x < game->map_cols)
		{
			cel = game->map[y][x];
			if (cel == 'P')
			{
				game->player_y = y;
				game->player_x = x;
				// Dibuja el jugador solo una vez
				mlx_image_to_window(game->mlx, game->img_player, \
				game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
				return ;
			}
			x++;
		}
		y++;
	}
}
