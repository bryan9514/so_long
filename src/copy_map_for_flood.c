/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map_for_flood.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:27:05 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/21 07:18:44 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **copy_map(char **map)
{
	int		i;
	char	**map_copy = NULL;

	i = 0;
	while (map[i])
		i++;
	map_copy = malloc(sizeof(char *) * (i + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void flood_fill(char **map, int x, int y)
{
	if (y < 0 || x < 0 || map[y] == NULL || map[y][x] == '\0')
		return;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return;

	// Marcamos como visitado con 'F'
	map[y][x] = 'F';

	// Recorrer en las 4 direcciones: arriba, abajo, izquierda, derecha
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
int	find_player(char **map, int *player_x, int *player_y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*player_x = j;
				*player_y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	has_remainig(char **map, char character)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == character)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int verify_path(char **map)
{
	int		player_x;
	int		player_y;
	char	**map_copy = NULL;

	if (!find_player(map, &player_x, &player_y))
		free_map_print_error(map, NULL, NULL, "player not found");
	map_copy = copy_map(map);
	if (!map_copy)
		free_map_print_error(map, NULL, NULL, "copy_map failed");
	flood_fill(map_copy, player_x, player_y);
	if (has_remainig(map_copy, 'C') || has_remainig(map_copy, 'E'))
	{
			free_map(map_copy);
			return (0);
	}
	free_map(map_copy);
	return (1);
}
