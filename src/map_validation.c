/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:00:17 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/23 17:55:13 by brturcio         ###   ########.fr       */
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
	if (line_refe > 49)
		return (0);
	if (i > 50)
		return (0);
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

void	check_required_elements(char **map, int *c, int *p, int *e)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				(*c)++;
			if (map[i][j] == 'P')
				(*p)++;
			if (map[i][j] == 'E')
				(*e)++;
			j++;
		}
		i++;
	}
}

int	validate_elements_map(char **map)
{
	int	count_c;
	int	count_p;
	int	count_e;

	count_c = 0;
	count_p = 0;
	count_e = 0;
	if (!validate_wall_map(map))
		free_map_print_error(map, NULL, NULL, "Error : Invalid wall");
	if (!check_valid_chars(map))
		free_map_print_error(map, NULL, NULL, "Error : Invalid characters");
	check_required_elements(map, &count_c, &count_p, &count_e);
	if (count_p < 1)
		free_map_print_error(map, NULL, NULL, "Error : Missing player");
	if (count_p > 1)
		free_map_print_error(map, NULL, NULL, "Error : Too many players");
	if (count_e < 1)
		free_map_print_error(map, NULL, NULL, "Error : Missing exit");
	if (count_e > 1)
		free_map_print_error(map, NULL, NULL, "Error : Too many exits");
	if (count_c < 1)
		free_map_print_error(map, NULL, NULL, "Erro : Missing collectible");
	if (!verify_path(map))
		free_map_print_error(map, NULL, NULL, "Error : Unreachable elements");
	return (1);
}
