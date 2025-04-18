/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:00:17 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/18 14:34:03 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		validate_size_lines_map(char **map)
{
	int	i;
	size_t	line_refe;

	if (!map || !map[0])
		return (0);
	i = 1;
	line_refe = ft_strlen(map[0]);
	while(map[i])
	{
		if (ft_strlen(map[i]) != line_refe)
			return (0);
		i++;
	}
	return (1);
}

int		validate_map_not_empty(char **map)
{
	if (!map || !map[0] || map[0][0] == '\0')
		return (0);
	return (1);
}

