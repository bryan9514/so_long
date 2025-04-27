/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_rscs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:21:46 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/25 18:17:43 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*load_img(t_game *game, char *img_addr)
{
	game->texture = mlx_load_png(img_addr);
	if (!game->texture)
		return (0);
	game->image = mlx_texture_to_image(game->mlx, game->texture);
	mlx_delete_texture(game->texture);
	if (!game->image)
		return (0);
	return (game->image);
}

int	load_rscs(t_game *game)
{
	game->img_wall = load_img(game, RSCS_WALL);
	game->img_floor = load_img(game, RSCS_FLOOR);
	game->img_player = load_img(game, RSCS_PLAYER);
	game->img_door = load_img(game, RSCS_DOOR);
	game->img_collec = load_img(game, RSCS_COLLEC);
	if (!game->img_wall || !game->img_floor || !game->img_player || \
		!game->img_door || !game->img_collec)
		return (0);
	return (1);
}
