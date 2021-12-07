/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:02:42 by marvin            #+#    #+#             */
/*   Updated: 2021/12/07 13:38:52 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd = open("test.txt", O_RDONLY);
	char	*line = NULL;
	int fd2 = open(argv[1], O_RDONLY);
	int fd3 = open("42.txt", O_RDONLY);

	//get_next_line(42, ((void *)0));
	//get_next_line(42, &line);
	
	/*
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line); */

	
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
	}



	return (0);
}
