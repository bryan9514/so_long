/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:27:05 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/19 19:58:10 by brturcio         ###   ########.fr       */
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

int verify_path(char **map)
{
	char	**map_copy = NULL;

	map_copy = copy_map(map);
	if (!map_copy)
		free_map_print_error(map, NULL, NULL, "copy_map failed");
	

}
