/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:19:38 by brturcio          #+#    #+#             */
/*   Updated: 2025/04/27 19:57:08 by brturcio         ###   ########.fr       */
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
		if (!clean_line)
			free_list2(lines, line, "ft_strtrim failed");
		free(line);
		new_node = ft_lstnew(clean_line);
		if (!new_node)
			free_list2(lines, clean_line, "ft_lstnew failed");
		ft_lstadd_back(&lines, new_node);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}


char	**convert_list_to_array(t_list *lines, t_game *game)
{
	int		i;
	int		map_size;
	t_list	*tmp;

	map_size = ft_lstsize(lines);
	game->map = malloc(sizeof(char *) * (map_size + 1));
	if (!game->map)
		free_list2(lines, NULL, "Failed malloc");
	tmp = lines;
	i = 0;
	while (tmp)
	{
		game->map[i++] = tmp->content;
		tmp = tmp->next;
	}
	game->map[i] = NULL;
	free_list(lines);
	return (game->map);
}

int	validate_map_not_empty(t_game *game)
{
	if (!game->map || !game->map[0] || game->map[0][0] == '\0')
		return (0);
	return (1);
}

char	**read_map(char *av, t_game *game)
{
	int		fd;
	t_list	*lines;

	fd = open_map_file(av);
	lines = read_lines_into_list(fd);
	convert_list_to_array(lines, game);
	if (!validate_map_not_empty(game))
		free_map_print_error(game->map, NULL, NULL, "Empty map");
	return (game->map);
}
