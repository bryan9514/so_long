/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:04:49 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/15 09:05:03 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_error(int error)
{
	if (error == INVALID_ARGUMENTS)
		ft_printf(YELLOW "Syntax : ./so_long  map_name.ber\n"RESET);
	else if (error == INVALID_EXTENSION)
		ft_printf(YELLOW"No valid extension map\n"RESET);
	else if (error == INVALID_FILE)
		ft_printf(YELLOW"File does not exist\n"RESET);
	exit(1);
}
