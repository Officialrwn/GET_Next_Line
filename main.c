/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:02:42 by marvin            #+#    #+#             */
/*   Updated: 2021/12/04 16:47:35 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


int	main(int argc, char **argv)
{
	int	fd = open("test.txt", O_RDONLY);
	char	*line;

	while (get_next_line(fd, &line))
	{
		printf("main = %s\n", line);
	//	printf("stat = %s\n", stathicc[0]);
	}

	return (0);
}