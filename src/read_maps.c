/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:19:38 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/22 15:36:38 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		free_map_print_error(NULL, NULL, NULL, "File does not exist");
	return (fd);
}

t_list	*read_lines_into_list(int fd)
{
	t_list	*lines;
	t_list	*new_node;
	char	*line;
	char	*clean_line;

	lines = NULL;
	line = get_next_line(fd);
	while (line)
	{
		clean_line = ft_strtrim(line, "\r\n");
		free(line);
		if (!clean_line)
			free_map_print_error(NULL, lines, NULL, "ft_strtrim failed");
		new_node = ft_lstnew(clean_line);
		if (!new_node)
			free_map_print_error(NULL, lines, clean_line, "ft_lstnew failed");
		ft_lstadd_back(&lines, new_node);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

char	**convert_list_to_array(t_list *lines)
{
	int		i;
	int		map_size;
	char	**map;
	t_list	*tmp;

	map_size = ft_lstsize(lines);
	map = malloc(sizeof(char *) * (map_size + 1));
	if (!map)
		free_map_print_error(NULL, NULL, NULL, "Failed malloc");
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

int	validate_map_not_empty(char **map)
{
	if (!map || !map[0] || map[0][0] == '\0')
		return (0);
	return (1);
}

char	**read_map(char *av)
{
	int		fd;
	t_list	*lines;
	char	**map;

	fd = open_map_file(av);
	lines = read_lines_into_list(fd);
	map = convert_list_to_array(lines);
	if (!validate_map_not_empty(map))
		free_map_print_error(map, NULL, NULL, "Empty map");
	return (map);
}
