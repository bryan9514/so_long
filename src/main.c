/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:55:14 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/15 11:06:16 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int		main(int ac, char **av)
{
	char 	**map;
	int	i = 0;

	validate_all(ac , av);
	map = read_map(av[1]);
	while (map[i])
		ft_printf("%s", map[i++]);
	// validate_map(map);
	// init_game(map);

	free_all(map);
	ft_printf("\nfinal main\n");
	return (0);
}
