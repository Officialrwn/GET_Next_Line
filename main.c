/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:02:42 by marvin            #+#    #+#             */
/*   Updated: 2021/12/06 17:14:06 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


int	main(int argc, char **argv)
{
	int	fd = open("test.txt", O_RDONLY);
	char	*line;
	int fd2 = open(argv[1], O_RDONLY);
	int fd3 = open("42", O_RDONLY);

	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
	}

	return (0);
}