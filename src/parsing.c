/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:22:09 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/15 11:35:29 by brturcio         ###   ########.fr       */
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
	if (ac != 2)
		ft_print_error(INVALID_ARGUMENTS);
	if (check_file_extension(av[1]))
		ft_print_error(INVALID_EXTENSION);
		
	return (1);
}
