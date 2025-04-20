/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:01:43 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/20 13:15:08 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// void	close_hook(void *param)
// {
// 	// t_game *game = (t_game *)param;

// 	// free_map_print_error(game->map, NULL, NULL, "Cerrando juego");

// 	t_game *game = (t_game *)param;
// 	free_map(game->map);
// 	mlx_close_window(game->mlx);

// }


// int	init_game(char **map)
// {
// 	int		i;
// 	int		width;
// 	int		height;
// 	t_game	game;

// 	i = 0;
// 	width = (ft_strlen(map[0]) * 64);
// 	while (map[i])
// 		i++;
// 	height = (i * 64);

// 	game.map = map;
// 	game.mlx = mlx_init(width, height, "so_long", false);
// 	if (!game.mlx)
// 		return (0);
// 	mlx_close_hook(game.mlx, close_hook, &game);


// 	mlx_loop(game.mlx);
// 	mlx_terminate(game.mlx);
// 	return (1);
// }

#include "so_long.h"

#define TILE_SIZE 64

void	close_hook(void *param)
{
	t_game *game = (t_game *)param;
	free_map(game->map);          // liberar el mapa
	mlx_close_window(game->mlx);  // cerrar la ventana
}

int	init_game(char **map)
{
	t_game			game;
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	int				rows = 0;
	int				cols;
	int				width;
	int				height;

	// Calcular dimensiones
	while (map[rows])
		rows++;
	cols = ft_strlen(map[0]); // Asumes que todas las líneas tienen la misma longitud
	width = cols * TILE_SIZE;
	height = rows * TILE_SIZE;

	// Guardar el mapa y crear la ventana
	game.map = map;
	game.mlx = mlx_init(width, height, "so_long", false);
	if (!game.mlx)
		return (0);

	// Registrar hook para cerrar con X
	mlx_close_hook(game.mlx, close_hook, &game);

	// Cargar textura (por ejemplo, floor.png)
	texture = mlx_load_png("so_long/resurs/Brick_01-128x128.png");
	if (!texture)
		return (free_map(map), mlx_close_window(game.mlx), 0);

	// Crear imagen desde la textura
	image = mlx_texture_to_image(game.mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		return (free_map(map), mlx_close_window(game.mlx), 0);

	// Dibujar la imagen en cada posición
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
			mlx_image_to_window(game.mlx, image, x * TILE_SIZE, y * TILE_SIZE);
	}

	// Iniciar el bucle
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (1);
}

