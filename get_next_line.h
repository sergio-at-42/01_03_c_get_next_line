/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:30:34 by Serge             #+#    #+#             */
/*   Updated: 2025/12/20 15:39:15 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_buff
{
	int		fd;
	char	*content;
	ssize_t	size;
	ssize_t	pos;
}			t_buff;

typedef struct s_line
{
	char			*part;
	ssize_t			size;
	struct s_line	*next;
}					t_line;

char	*get_next_line(int fd);
void	init_buffer(t_buff *buffer, int fd);
char	*extract_next_line(t_buff *buffer);
char	*create_next_line(ssize_t size_line, t_line **new_line);
t_line	*ft_lstnew(char *content, ssize_t size);
void	ft_lstadd_back(t_line **lst, t_line *new);
t_line	*ft_lstlast(t_line *lst);
ssize_t	ft_strlcat(char *dst, t_line *src, ssize_t size);
char	*ft_substr(char *s, ssize_t start, ssize_t end);

#endif
