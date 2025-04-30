/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:42:43 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/30 13:58:40 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_cell(t_game *game, int new_x, int new_y)
{
	size_t i = 0;
	while (i < game->img_collec->count)
	{
		if (game->img_collec->instances[i].x == new_x * TILE_SIZE
			&& game->img_collec->instances[i].y == new_y * TILE_SIZE)
		{
			game->img_collec->instances[i].enabled = false;
			break;
		}
		i++;
	}
	game->collected++;
	game->map[new_y][new_x] = '0';
}

int	verify_end(t_game *game, char dest)
{
	if (dest == 'E')
	{
		if (game->collected == game->coins && dest == 'E')
		{
			ft_printf(GREEN"🎉 ¡YOU WIN IN %d MOVEMENTS!\n"RESET, game->moves);
			end_game(game);
		}
		else
		{
			ft_printf(CYAN"🚪 THE DOOR IS CLOSED 🎃\n"RESET);
		}
	}
	return (0);
}



void	move_player(t_game *game, int dx, int dy)
{
	int		new_y;
	int		new_x;
	char	dest;

	new_y = game->player_y + dy;
	new_x = game->player_x + dx;
	dest = game->map[new_y][new_x];
	if (dest == '1')
		return ;
	if (dest == 'C')
		change_cell(game, new_x, new_y);
	if (verify_end(game, dest))
		return ;
	game->img_player->instances[0].x = new_x * TILE_SIZE;
	game->img_player->instances[0].y = new_y * TILE_SIZE;
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf(CYAN"movements : %d\n"RESET, game->moves);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		move_player(game, 0, -1);
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		move_player(game, 0, 1);
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		move_player(game, -1, 0);
	else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		move_player(game, 1, 0);
	else if (keydata.key == MLX_KEY_ESCAPE)
		end_game(game);
}
