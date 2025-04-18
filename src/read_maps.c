/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:19:38 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/18 14:31:32 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_print_error(INVALID_FILE);
	return (fd);
}

t_list	*read_lines_into_list(int fd)
{
	t_list	*lines = NULL;
	char	*line = NULL;
	char	*clean_line = NULL;

	while ((line = get_next_line(fd)))
	{
		clean_line = ft_strtrim(line, "\n");
		free(line);
		ft_lstadd_back(&lines, ft_lstnew(clean_line));
	}
	close(fd);
	return (lines);
}

char	**convert_list_to_array(t_list *lines)
{
	int		i;
	int		map_size;
	char	**map = NULL;
	t_list	*tmp = NULL;

	map_size = ft_lstsize(lines);
	map = malloc(sizeof(char *) * (map_size + 1));
	if (!map)
		ft_print_error(MALLOC_FAILED);
	tmp = lines;
	i = 0;
	while (tmp)
	{
		map[i++] = tmp->content;
		tmp = tmp->next;
	}
	map[i] = NULL;
	free_list(lines);
	return (map);
}

char	**read_map(char *av)
{
	int		fd;
	t_list	*lines = NULL;
	char	**map = NULL;

	fd = open_map_file(av);
	lines = read_lines_into_list(fd);
	map = convert_list_to_array(lines);
	if (!validate_map_not_empty(map))
		ft_print_error(EMPTY_MAP);
	return (map);
}

