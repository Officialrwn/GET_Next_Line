/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:02:42 by marvin            #+#    #+#             */
/*   Updated: 2021/12/08 13:01:03 by leotran          ###   ########.fr       */
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

	//printf("%d", get_next_line(42, ((void *)0)));
	//printf("%d", get_next_line(42, &line));
	
	/*
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line); */


	printf("%d ", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d ", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d ", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d ", get_next_line(fd, &line));
	printf("%s\n", line);




	return (0);
}
