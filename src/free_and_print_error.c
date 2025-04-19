/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_print_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:47:01 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/19 15:57:45 by brturcio         ###   ########.fr       */
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

void	free_map_print_error(char **map, t_list *lines, char *line, char *msj)
{
	int	i;

	i = 0;
	if (lines)
		free_list(lines);
	if (line)
		free(line);
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	if (msj)
		ft_printf(YELLOW"%s\n"RESET, msj);
	exit(1);
}
