/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 08:59:13 by leo               #+#    #+#             */
/*   Updated: 2021/12/17 01:46:02 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	getlinefromstatic(int fd, char **stathicc, char **line)
{
	char	*temp;

	*line = ft_strccpy(stathicc[fd], NL);
	temp = ft_strdup(ft_strchr(stathicc[fd], NL) + 1);
	ft_strdel(&stathicc[fd]);
	stathicc[fd] = ft_strdup(temp);
	ft_strdel(&temp);
	return (1);
}

static int	getlastline(int fd, char **stathicc, char **line)
{
	int	i;

	i = 0;
	if (ft_strchr(stathicc[fd], NL) != NULL)
		i = getlinefromstatic(fd, stathicc, line);
	else
	{
		*line = ft_strdup(stathicc[fd]);
		ft_strdel(&stathicc[fd]);
		if (*line[0] != '\0')
			i = 1;
	}
	return (i);
}

static int	cpytostatic(int fd, char **stathicc, char *buffer, char **line)
{
	char	*temp;
	int		i;

	i = 2;
	if (stathicc[fd] != NULL)
	{
		temp = ft_strdup(stathicc[fd]);
		ft_strdel(&stathicc[fd]);
		stathicc[fd] = ft_strjoin(temp, buffer);
		ft_strdel(&temp);
	}
	else
		stathicc[fd] = ft_strdup(buffer);
	if (ft_strchr(stathicc[fd], NL) != NULL)
		i = getlinefromstatic(fd, stathicc, line);
	return (i);
}

int	get_next_line(const int fd, char **line)
{
	static char	*stathicc[FD_SIZE];
	char		*buffer;
	int			i;

	i = 1;
	*line = NULL;
	buffer = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (fd < 0 || line == NULL)
		i = -1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFF_SIZE);
		buffer[i] = '\0';
		if (i > 0)
			i = cpytostatic(fd, stathicc, buffer, line);
		if (i == 0 && stathicc[fd] != NULL)
			i = getlastline(fd, stathicc, line);
		ft_strdel(&buffer);
		if (i == 1)
			break ;
	}
	return (i);
}
