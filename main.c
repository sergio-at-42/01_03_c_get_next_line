/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:39:35 by sbeldjao          #+#    #+#             */
/*   Updated: 2025/12/19 12:01:11 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_suspend_display()
{
	int	i;

	while (scanf("%d", &i) == 1);
}

int	main()
{
	int		file_descriptor;
	char	*line;

	file_descriptor = open("test_file.txt", O_RDONLY);
	// file_descriptor = open("empty", O_RDONLY);
	// file_descriptor = open("41_with_nl", O_RDONLY);
	// file_descriptor = open("41_no_nl", O_RDONLY);
	// file_descriptor = open("multiple_line_no_nl", O_RDONLY);
	while ((line = get_next_line(file_descriptor)))
	{
		printf("%s", line);
		free(line);
	}
	// get_next_line(file_descriptor);
	// free(line);
	// get_next_line(file_descriptor);
	// free(line);
	close(file_descriptor);
	
// ft_suspend_display();

	return (0);
}
