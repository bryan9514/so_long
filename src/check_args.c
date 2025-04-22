/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:59:51 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/22 17:12:44 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_extension(char *filename)
{
	size_t		len;

	len = ft_strlen(filename);
	if (len < 4)
		return (1);
	return (ft_strncmp(filename + len - 4, ".ber", 4));
}

int	check_args(int ac, char **av)
{
	if (ac != 2)
		free_map_print_error(NULL, NULL, NULL, "Error : Syntax : \
		./so_long  map_name.ber");
	if (check_file_extension(av[1]))
		free_map_print_error(NULL, NULL, NULL, "Error : No valid \
		extension map");
	return (1);
}
