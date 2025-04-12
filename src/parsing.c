/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:22:09 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/12 16:56:39 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_file_extension(char *filename)
{
	size_t		len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", len));
}

int		validate_all(int ac, char **av)
{
	int		fd;

	if (ac != 2)
	{
		ft_printf(YELLOW "Syntax : %s  map_name.ber\n"RESET, av[0]);
		return (0);
	}
	if (check_file_extension(av[1]))
	{
		ft_printf(YELLOW"No valid extension map\n"RESET);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf(YELLOW"File does not exist\n"RESET);
		return(0);
	}


	return (1);
}
