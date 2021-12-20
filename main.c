/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:02:42 by marvin            #+#    #+#             */
/*   Updated: 2021/12/20 22:01:59 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	//int	fd = open("basic.txt", O_RDONLY);
	int	fd = open(argv[1], O_RDONLY);
	//int	fd = 42;

	char	*line = NULL;
	int i = 1;
	
	while (i > 0)
	{
		i = get_next_line(fd, &line);
		printf("%d: %s\n", i, line);
		ft_strdel(&line);
	}
	//system("leaks a.out");
	return (0);
}
