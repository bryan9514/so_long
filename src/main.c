/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:55:14 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/18 14:57:28 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int		main(int ac, char **av)
{
	char 	**map;
	int	i = 0;

	check_args(ac , av);
	map = read_map(av[1]);
	if(!validate_size_lines_map(map))
		ft_printf("Size no valid\n");
	// validate_map(map);
	// init_game(map);

	while(map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	free_map(map);
	ft_printf("\nfinal main\n");
	return (0);
}
