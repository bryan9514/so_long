/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_print_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:47:01 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/23 17:13:10 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_list(t_list *lines)
{
	t_list	*tmp;

	while (lines)
	{
		tmp = lines->next;
		free(lines);
		lines = tmp;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_image(t_game *game)
{
	if (game->img_wall)
		mlx_delete_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_delete_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_delete_image(game->mlx, game->img_player);
	if (game->img_door)
		mlx_delete_image(game->mlx, game->img_door);
	if (game->img_collec)
		mlx_delete_image(game->mlx, game->img_collec);
}

void	free_map_print_error(char **map, t_list *lines, char *line, char *msj)
{
	if (lines)
		free_list(lines);
	if (line)
		free(line);
	if (map)
		free_map(map);
	if (msj)
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd(msj, 2);
		ft_putstr_fd(RESET"\n", 2);
	}
	exit(1);
}
