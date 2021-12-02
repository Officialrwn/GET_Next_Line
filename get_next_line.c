/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:51:02 by leotran           #+#    #+#             */
/*   Updated: 2021/12/02 15:04:01 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFF_SIZE 8
static char temp[4096];

typedef struct s_nextline
{
	char *nextline;
	int i;
}				t_nextline;

int	countnextnl(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	return (i);
}

t_nextline	ft_checknewline(char *src, char *buffer)
{
	int	i;
	t_nextline var;
	char *test;
	
	i = 0;
	if (ft_strchr(buffer, '\n') == 0)
	{
		ft_strcpy(src, buffer);
	}
	else
	{
		ft_strncpy(src, buffer, countnextnl(buffer));
		var.nextline = ft_strjoin(temp, src);
		ft_strcpy(temp, ft_strchr(buffer, '\n') + 1);
	}
	return (var);
}

int	get_next_line(const int fd, char **line)
{
	char	*src;
	char	*buffer;
	t_nextline var;

	src = ft_strnew(BUFF_SIZE);
	buffer = ft_strnew(BUFF_SIZE);

	if (read(fd, buffer, BUFF_SIZE))
	{
		var = ft_checknewline(src, buffer);
		*line = var.nextline;
	}
	else
		return (0);
	return (1);
}


int	main(int argc, char **argv)
{
	int	fd = open(argv[1], O_RDONLY);
	char	**line;

	while (get_next_line(fd, line))
	{
		printf("main = %s\n", *line);
	}
	return (0);
}

getnextfunction(int fd, **line)
{
	char *temp = "Hello";
	*line = temp;
}
static char temp[8192];
read 10 bytes

Hello\n
Tesa sdasdt\n 
sadasd\n