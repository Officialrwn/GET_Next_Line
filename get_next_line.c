/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 08:59:13 by leo               #+#    #+#             */
/*   Updated: 2021/12/17 02:44:53 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	getlinefromstatic(int fd, char **stathicc, char **line)
{
	char	*temp;
	size_t	i;

	i = ft_strlen(stathicc[fd]) - ft_strlen(ft_strchr(stathicc[fd], NL));
	*line = ft_strsub(stathicc[fd], 0, i);
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
	buffer = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || fd >= FD_SIZE)
		i = -1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFF_SIZE);
		buffer[i] = '\0';
		if (i > 0)
			i = cpytostatic(fd, stathicc, buffer, line);
		if (i == 0 && stathicc[fd] != NULL)
			i = getlastline(fd, stathicc, line);
		if (i == 1)
			break ;
	}
	ft_strdel(&buffer);
	return (i);
}
