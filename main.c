/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:02:42 by marvin            #+#    #+#             */
/*   Updated: 2021/12/18 14:35:17 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd = open("bible.txt", O_RDONLY);
	char	*line = NULL;
	int i = 1;
	
	while (i > 0)
	{
		i = get_next_line(fd, &line);
		printf("%d: %s\n", i, line);
		ft_strdel(&line);
	}
	return (0);
}
