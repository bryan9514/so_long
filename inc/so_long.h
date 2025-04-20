/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:56:11 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/20 20:35:46 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

#include "MLX42/MLX42.h"
#include "libft.h"
#include <fcntl.h> //open
#include <unistd.h> // read and close

//Code the elements
# define PLAYER 'P'
# define EXIT 'E'
# define COLLEC 'C'
# define WALL '1'
# define EMPTY '0'

//Colors
# define BLACK   "\033[0;30m"
# define RED     "\033[0;31m"
# define GREEN   "\033[0;32m"
# define YELLOW  "\033[0;33m"
# define BLUE    "\033[0;34m"
# define PURPLE  "\033[0;35m"
# define CYAN    "\033[0;36m"
# define WHITE   "\033[0;37m"
# define RESET   "\033[0m"

# define TILE_SIZE 32
typedef struct s_game
{
	void	*mlx;        // puntero de conexión MiniLibX
	void	*win;        // puntero de la ventana
	char	**map;       // mapa leído (char **)
	int		width;      // ancho del mapa en tiles
	int		height;     // alto del mapa en tiles

	int		player_x;   // posición X del jugador
	int		player_y;   // posición Y del jugador
	int		coins;      // número total de coleccionables
	int		collected;  // número de coleccionables recogidos
	int		moves;      // contador de movimientos

	// sprites (imágenes)
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_coin;

}	t_game;


//chrck_args.c
int		check_file_extension(char *filename);
int		check_args(int ac, char **av);

//free.c
void	free_list(t_list *lines);
void	free_map(char **map);
void	free_map_print_error(char **map, t_list *lines, char *line, char *msj);

//init_game
int init_game(char **map);

//map.path.c
int verify_path(char **map);

//map_validation.c
int		validate_size_lines_map(char **map);
int		validate_elements_map(char **map);

//read_map.c
int		open_map_file(char *filename);
t_list	*read_lines_into_list(int fd);
char	**convert_list_to_array(t_list *lines);
int		validate_map_not_empty(char **map);
char	**read_map(char *av);

#endif


