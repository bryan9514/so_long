/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:55:14 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/20 11:52:51 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		main(int ac, char **av)
{
	char 	**map;

	check_args(ac , av);
	map = read_map(av[1]);
	if (!validate_size_lines_map(map))
		free_map_print_error(map, NULL, NULL, "Invalid size map");
	validate_elements_map(map);
	init_game(map);

	free_map_print_error(map, NULL, NULL, "Game termined");
	return (0);
}
