/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:55:14 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/12 16:57:25 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int		main(int ac, char **av)
{
	if (validate_all(ac , av) == 0)
	{
		perror("Error");
		return (0);
	}
	ft_printf("paso validacion\n");
	// void	*mlx_ptr;

	// mlx_ptr = mlx_init();
	// if (!mlx_ptr)
	// 	return (0);
	// free(mlx_ptr);
	return (0);
}
