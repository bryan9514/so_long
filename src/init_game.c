/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:01:43 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/20 20:35:25 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_hook(void *param)
{
	t_game *game = (t_game *)param;
	free_map(game->map);
	mlx_close_window(game->mlx);
}

void	render_floor(t_game *game, mlx_image_t *img)
{
	int x, y;

	for (y = 0; y < game->height / TILE_SIZE; y++)
	{
		for (x = 0; x < game->width / TILE_SIZE; x++)
		{
			mlx_image_to_window(game->mlx, img, x * TILE_SIZE, y * TILE_SIZE);
		}
	}
}
int	init_game(char **map)
{
	int		i;
	t_game	game;
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	i = 0;
	game.width = (ft_strlen(map[0]) * 32);
	while (map[i])
		i++;
	game.height = (i * 32);

	game.map = map;
	game.mlx = mlx_init(game.width, game.height, "so_long", false);
	if (!game.mlx)
		return (0);
	mlx_close_hook(game.mlx, close_hook, &game);

	texture = mlx_load_png("rscs/floor.png");
	if (!texture)
		return (0);
	image = mlx_texture_to_image(game.mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		return (0);
	render_floor(&game, image);

	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (1);
}


