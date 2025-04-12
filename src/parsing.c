/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:22:09 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/12 15:57:42 by brturcio         ###   ########.fr       */
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

int		validate_all(int ac, char *av)
{
	if (ac != 2)
	{
		ft_printf("Syntax : ./so_long  namemap.ber\n");
		return (0);
	}
	if (check_file_extension(av))
	{
		ft_printf("No valid extension map\n");
		return (0);
	}

	return (1);
}
