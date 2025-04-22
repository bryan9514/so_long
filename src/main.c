/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:55:14 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/22 19:55:09 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;

	check_args(ac, av);
	map = read_map(av[1]);
	if (!validate_size_lines_map(map))
		free_map_print_error(map, NULL, NULL, "Error : Invalid size map");
	validate_elements_map(map);
	if (!init_game(map))
		free_map_print_error(map, NULL, NULL, "Error: Failed to initialize");
	return (0);
}
