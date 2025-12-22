/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:31:04 by Serge             #+#    #+#             */
/*   Updated: 2025/12/20 19:39:14 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	init_buffer(t_buff *buffer, int fd)
{
	buffer->fd = fd;
	buffer->content = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	buffer->pos = 0;
	buffer->size = 0;
}

char	*create_next_line(ssize_t size_line, t_line **new_line)
{
	char	*line;
	t_line	*part_next;
	t_line	*part_prev;

	if (size_line == 0 || !new_line || !*new_line)
		return (NULL);
	line = (char *)malloc((size_line + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	size_line = 0;
	part_next = *new_line;
	while (part_next)
	{
		size_line = ft_strlcat(line, part_next, size_line);
		part_prev = part_next;
		part_next = (part_next)->next;
		free(part_prev->part);
		free(part_prev);
	}
	free(new_line);
	return (line);
}

char	*extract_next_line(t_buff *buffer)
{
	t_line	**new_line;
	ssize_t	size_line;
	ssize_t	pinb;

	new_line = (t_line **)malloc(sizeof(t_line *));
	*new_line = NULL;
	size_line = 0;
	pinb = buffer->pos;
	while (buffer->size > 0)
	{
		pinb = buffer->pos;
		while (pinb < buffer->size - 1 && buffer->content[pinb] != '\n')
			pinb++;
		ft_lstadd_back(new_line, ft_lstnew(
				ft_substr(buffer->content, buffer->pos, pinb),
				pinb - buffer->pos + 1));
		size_line += pinb - buffer->pos + 1;
		buffer->pos = pinb + 1;
		if (buffer->content[pinb] == '\n')
			return (create_next_line(size_line, new_line));
		buffer->size = read(buffer->fd, buffer->content, BUFFER_SIZE);
		buffer->pos = 0;
	}
	return (create_next_line(size_line, new_line));
}

char	*get_next_line(int fd)
{
	static t_buff	*buffer;

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (t_buff *)malloc(sizeof(t_buff));
		init_buffer(buffer, fd);
	}
	if (buffer->pos == buffer->size)
	{
		buffer->size = read(buffer->fd, buffer->content, BUFFER_SIZE);
		buffer->pos = 0;
	}
	if (buffer->size <= 0)
	{
		free(buffer->content);
		buffer->content = NULL;
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (extract_next_line(buffer));
}
