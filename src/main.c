/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:55:14 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/19 16:14:55 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i = 0;

	while(map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	char 	**map;

	check_args(ac , av);
	map = read_map(av[1]);
	if (!validate_size_lines_map(map))
		free_map_print_error(map, NULL, NULL, "Invalid size map");
	validate_elements_map(map);
	// init_game(map);
	print_map(map); //ELIMINAR ESTO LUEGO
	free_map_print_error(map, NULL, NULL, 0);
	return (0);
}
