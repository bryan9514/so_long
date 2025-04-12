/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:55:14 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/10 15:52:16 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int		main(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (0);
	free(mlx_ptr);
	return (0);
}
