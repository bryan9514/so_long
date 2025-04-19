/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:00:17 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/19 16:56:14 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_size_lines_map(char **map)
{
	int		i;
	size_t	line_refe;

	if (!map || !map[0])
		return (0);
	i = 1;
	line_refe = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != line_refe)
			return (0);
		i++;
	}
	return (1);
}

int	validate_wall_map(char **map)
{
	int	i;
	int	j;
	int	last;
	int	len;

	i = 1;
	last = 0;
	while (map[last])
		last++;
	j = 0;
	while (map[0][j])
		if (map[0][j++] != '1')
			return (0);
	while (i < (last - 1))
	{
		len = ft_strlen(map[i]);
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (map[last - 1][j])
		if (map[last - 1][j++] != '1')
			return (0);
	return (1);
}

int	check_valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C' && \
				map[i][j] != 'P' && map[i][j] != 'E')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}



int	validate_elements_map(char **map)
{
	if (!validate_wall_map(map))
		free_map_print_error(map, NULL, NULL, "Invalid wall");
	if (!check_valid_chars(map))
		free_map_print_error(map, NULL, NULL, "Invalid characters");
	return (1);
}
