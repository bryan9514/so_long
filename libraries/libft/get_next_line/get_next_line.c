/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:44:30 by brturcio          #+#    #+#             */
/*   Updated: 2024/12/21 15:40:22 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buff(int fd, char *data)
{
	int		nb_buffer;
	char	*buffer_data;

	nb_buffer = 1;
	if (data == NULL)
		data = ft_strdup("");
	while (nb_buffer > 0 && !ft_strrchr(data, '\n'))
	{
		buffer_data = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer_data)
			return (free(data), NULL);
		nb_buffer = read(fd, buffer_data, BUFFER_SIZE);
		if (nb_buffer < 0)
			return (free(data), free(buffer_data), NULL);
		if (nb_buffer == 0)
		{
			free(buffer_data);
			buffer_data = NULL;
			break ;
		}
		buffer_data[nb_buffer] = '\0';
		data = ft_strjoin(data, buffer_data);
		free(buffer_data);
	}
	return (data);
}

char	*extract_line(char **data)
{
	char	*line;
	char	*after_newline;
	size_t	len;

	len = 0;
	while ((*data)[len] != '\n' && (*data)[len] != '\0')
		len++;
	if ((*data)[len] == '\n')
	{
		line = ft_substr(*data, 0, len + 1);
		after_newline = ft_strdup(*data + len + 1);
		free(*data);
		*data = after_newline;
	}
	else
	{
		line = ft_strdup(*data);
		free(*data);
		*data = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*data = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data = read_buff(fd, data);
	if (!data || *data == '\0')
	{
		free(data);
		data = NULL;
		return (NULL);
	}
	line = extract_line(&data);
	return (line);
}
