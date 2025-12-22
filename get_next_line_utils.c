/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:59:00 by Serge             #+#    #+#             */
/*   Updated: 2025/12/16 19:31:58 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlcat(char *dst, t_line *src, ssize_t size)
{
	ssize_t	i;

	i = 0;
	while (i < src->size)
	{
		dst[size + i] = (src->part)[i];
		i++;
	}
	dst[size + i] = '\0';
	return (size + src->size);
}

char	*ft_substr(char *s, ssize_t start, ssize_t end)
{
	char	*sub_str;
	ssize_t	i;

	sub_str = (char *)malloc((end - start + 2) * sizeof(char));
	if (sub_str == NULL)
		return (NULL);
	i = 0;
	while (i <= end - start)
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

t_line	*ft_lstnew(char *content, ssize_t size)
{
	t_line	*lst_new;

	if (!content)
		return (NULL);
	lst_new = (t_line *)malloc(sizeof(t_line));
	if (!lst_new)
		return (NULL);
	lst_new->part = content;
	lst_new->size = size;
	lst_new->next = NULL;
	return (lst_new);
}

void	ft_lstadd_back(t_line **lst, t_line *new)
{
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

t_line	*ft_lstlast(t_line *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}
