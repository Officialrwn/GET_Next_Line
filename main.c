/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:02:42 by marvin            #+#    #+#             */
/*   Updated: 2021/12/19 11:55:42 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	fd = open("basic.txt", O_RDONLY);
	int	fd2 = open(argv[1], O_RDONLY);
	
	char	*line = NULL;
	int i = 1;
	
	while (i > 0)
	{
		i = get_next_line(fd2, &line);
		printf("%d: %s\n", i, line);
		ft_strdel(&line);
	}
	return (0);
}
