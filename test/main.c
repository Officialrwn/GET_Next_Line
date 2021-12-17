/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errormain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:02:42 by marvin            #+#    #+#             */
/*   Updated: 2021/12/17 12:56:15 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd = 1;
	char	*line = NULL;
	

	printf("%d %s\n", get_next_line(fd, &line), line);
	ft_strdel(&line);
	printf("%d %s\n", get_next_line(fd, &line), line);
	ft_strdel(&line);
	printf("%d %s\n", get_next_line(fd, &line), line);
	ft_strdel(&line);
	printf("%d %s\n", get_next_line(fd, &line), line);

	return (0);
}
