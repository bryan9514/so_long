/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:56:11 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/27 10:15:24 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

//Colors
# define BLACK	"\033[0;30m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define PURPLE	"\033[0;35m"
# define CYAN	"\033[0;36m"
# define WHITE	"\033[0;37m"
# define RESET	"\033[0m"

//size pixel
# define TILE_SIZE 32

//adress imgs
# define RSCS_WALL "rscs/wall.png"
# define RSCS_FLOOR "rscs/floor.png"
# define RSCS_PLAYER "rscs/player.png"
# define RSCS_DOOR "rscs/door.png"
# define RSCS_COLLEC "rscs/collectible.png"

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	int				width;
	int				height;
	int				map_rows;
	int				map_cols;
	int				player_x;
	int				player_y;
	int				coins;
	int				collected;
	int				moves;
	mlx_image_t		*img_wall;
	mlx_image_t		*img_floor;
	mlx_image_t		*img_player;
	mlx_image_t		*img_door;
	mlx_image_t		*img_collec;
	mlx_texture_t	*texture;
	mlx_image_t		*image;

}	t_game;

//chrck_args.c
int				check_file_extension(char *filename);
int				check_args(int ac, char **av);

//copy_map_for_flood.c
char			**copy_map(char **map);
void			flood_fill(char **map, int x, int y);
int				find_player(char **map, int *player_x, int *player_y);
int				has_remainig(char **map, char character);
int				verify_path(char **map);

//free.c
void			free_list(t_list *lines);
void			free_map(char **map);
void			free_list2(t_list *list, char *msj);
void			free_map_print_error(char **map, t_list *lines, char *line, \
				char *msj);
void			free_image(t_game *game);

//init_game_utils.c
void			window_size(t_game *game, char **map);
int				count_collec(char **map);

//init_game
int				init_game(char **map, t_game *game);

//init_window
void			close_hook(void *param);
int				init_window(t_game *game);
void			end_game(t_game *game);

//key_movement.c
void			change_cell(t_game *game, int new_x, int new_y);
int				verify_end(t_game *game, char dest);
void			move_player(t_game *game, int dx, int dy);
void			my_keyhook(mlx_key_data_t keydata, void *param);

//load_texture.c
int				load_rscs(t_game *game);
mlx_image_t		*load_img(t_game *game, char *img_addr);

//map_validation.c
int				validate_size_lines_map(char **map);
int				validate_wall_map(char **map);
int				check_valid_chars(char **map);
void			check_required_elements(char **map, int *c, int *p, int *e);
int				validate_elements_map(char **map);

//read_map.c
int				open_map_file(char *filename);
t_list			*read_lines_into_list(int fd);
char			**convert_list_to_array(t_list *lines);
int				validate_map_not_empty(char **map);
char			**read_map(char *av);

//render_map.c
void			render_map2(t_game *game, char cel, int x, int y);
void			render_map(t_game *game);
void			search_player(t_game *game);

#endif
