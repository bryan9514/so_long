/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:59:51 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/18 15:00:58 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_file_extension(char *filename)
{
	size_t		len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", 4));
}

int		check_args(int ac, char **av)
{
	if (ac != 2)
		ft_print_error(INVALID_ARGUMENTS);
	if (check_file_extension(av[1]))
		ft_print_error(INVALID_EXTENSION);
	return (1);
}
