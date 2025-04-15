/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:56:11 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/15 10:49:30 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

#include "MLX42/MLX42.h"
#include "libft.h"
#include "stdio.h"
#include <fcntl.h> //open
#include <unistd.h> // read and close

# define PLAYER 'P'
# define EXIT 'E'
# define COLLEC 'C'
# define WALL '1'
# define EMPTY '0'

# define INVALID_ARGUMENTS 1
# define INVALID_FILE 2
# define INVALID_EXTENSION 3
# define INVALID_MAP 4
# define MALLOC_FAILED 5



# define BLACK   "\033[0;30m"
# define RED     "\033[0;31m"
# define GREEN   "\033[0;32m"
# define YELLOW  "\033[0;33m"
# define BLUE    "\033[0;34m"
# define PURPLE  "\033[0;35m"
# define CYAN    "\033[0;36m"
# define WHITE   "\033[0;37m"
# define RESET   "\033[0m"

int		check_file_extension(char *filename);
int		validate_all(int ac, char **av);
//funtion printf the erros
void	ft_print_error(int error);

char	**read_map(char *av);

#endif


