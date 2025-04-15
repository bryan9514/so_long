/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:19:38 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/15 11:38:48 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_list(t_list *lines)
{
	t_list	*tmp;

	while (lines)
	{
		tmp = lines->next;
		free(lines);
		lines = tmp;
	}
	free(lines);
}

char	**read_map(char *av)
{
	t_list	*lines = NULL;
	t_list	*tmp = NULL;
	char	*line = NULL;
	char	**map = NULL;
	int		fd;
	int		i;
	int		map_size;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_print_error(INVALID_FILE);
	while ((line = get_next_line(fd)))
		ft_lstadd_back(&lines, ft_lstnew(line));
	close(fd);
	map_size = ft_lstsize(lines);
	map = malloc(sizeof(char *) * (map_size + 1));
	if (!map)
		ft_print_error(MALLOC_FAILED);
	tmp = lines;
	while (tmp)
	{
		map[i++] = tmp->content;
		tmp = tmp->next;
	}
	map[i] = NULL;
	free_list(lines);
	return (map);
}

	// 1. Abrir el archivo
	// 2. Leer todas las líneas con get_next_line en un bucle
	// 3. Guardar las líneas en una lista temporal
	// 4. Contar cuántas líneas hay
	// 5. Reservar memoria para char **map
	// 6. Copiar cada línea al map[i]
	// 7. Cerrar el archivo
	// 8. Liberar la lista si la usaste
	// 9. Retornar el map

