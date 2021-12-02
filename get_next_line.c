/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:51:02 by leotran           #+#    #+#             */
/*   Updated: 2021/12/02 18:37:45 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFF_SIZE 4
static char temp[1096]];

int	countnextnl(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	return (i);
}

char	*ft_checknewline(char *buffer)
{
	char	*nextline;
	char	*src;

	src = ft_strnew(BUFF_SIZE + 1);
	ft_strncpy(src, buffer, countnextnl(buffer));
	nextline = ft_strjoin(temp, src);
	ft_bzero(temp, 1024);
	ft_strcpy(temp, ft_strchr(buffer, '\n') + 1);
	
	return (nextline);
}

int	get_next_line(const int fd, char **line)
{
	char	*buffer;

	buffer = ft_strnew(BUFF_SIZE + 1);
	while (read(fd, buffer, BUFF_SIZE))
	{
		if (ft_strchr(buffer, '\n') == 0)
		{
			ft_strcat(temp, buffer);
		}
		else
		{
			*line = ft_checknewline(buffer);
			return (1);
		}
	}
	
	return (0);
}


int	main(int argc, char **argv)
{
	int	fd = open(argv[1], O_RDONLY);
	char	*line;

	while (get_next_line(fd, &line))
	{
		printf("main = %s ", line);
		printf("stat = %s\n", temp);
	}
	return (0);
}
