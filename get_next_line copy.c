/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:31:04 by Serge             #+#    #+#             */
/*   Updated: 2025/12/19 15:20:08 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*get_next_line(int fd)
{
	t_line			**new_line;
	ssize_t			size_line;
	static char		*enrg;
	static ssize_t	size_read;
	static ssize_t	start_enrg;
	ssize_t			pos_enrg;

	if (BUFFER_SIZE < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!enrg)
		enrg = (char *)malloc((BUFFER_SIZE) * sizeof(char));
	if (!enrg)
		return (NULL);
	if (start_enrg == size_read)
	{
		size_read = read(fd, enrg, BUFFER_SIZE);
		start_enrg = 0;
	}
	if (size_read <= 0)
	{
		free(enrg);
		enrg = NULL;
		return (NULL);
	}
	new_line = (t_line **)malloc(sizeof(t_line *));
	if (!new_line)
		return (NULL);
	*new_line = NULL;
	size_line = 0;
	pos_enrg = start_enrg;
	while (size_read > 0)
	{
		pos_enrg = start_enrg;
		while (pos_enrg < size_read - 1 && enrg[pos_enrg] != '\n')
			pos_enrg++;
		ft_lstadd_back(new_line, ft_lstnew(
				ft_substr(enrg, start_enrg, pos_enrg),
				pos_enrg - start_enrg + 1));
		size_line += pos_enrg - start_enrg + 1;
		start_enrg = pos_enrg + 1;
		if (enrg[pos_enrg] == '\n')
			return (create_next_line(size_line, new_line));
		size_read = read(fd, enrg, BUFFER_SIZE);
		start_enrg = 0;
	}
	return (create_next_line(size_line, new_line));
}
