/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 08:59:13 by leo               #+#    #+#             */
/*   Updated: 2021/12/08 15:41:33 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	getlastline(int fd, char **stathicc, char *buffer, char **line)
{
	char	*temp;

	if (ft_strchr(stathicc[fd], NL) != NULL)
	{
		*line = ft_strccpy(stathicc[fd], NL);
		temp = ft_strdup(ft_strchr(stathicc[fd], NL) + 1);
		ft_strdel(&stathicc[fd]);
		stathicc[fd] = ft_strdup(temp);
		ft_strdel(&temp);
		return (2);
	}
	else
	{
		*line = ft_strdup(stathicc[fd]);
		ft_strdel(&stathicc[fd]);
	}
	ft_strdel(&buffer);
	return (0);
}

static int	cpytostatic(int fd, char **stathicc, char *buffer, char **line)
{
	char	*temp;

	if (stathicc[fd] != NULL)
	{
		temp = ft_strdup(stathicc[fd]);
		ft_strdel(&stathicc[fd]);
		stathicc[fd] = ft_strjoin(temp, buffer);
		ft_strdel(&temp);
	}
	else
		stathicc[fd] = ft_strdup(buffer);
	ft_bzero(buffer, ft_strlen(buffer));
	if (ft_strchr(stathicc[fd], NL) != NULL)
	{
		*line = ft_strccpy(stathicc[fd], NL);
		temp = ft_strdup(ft_strchr(stathicc[fd], NL) + 1);
		ft_strdel(&stathicc[fd]);
		stathicc[fd] = ft_strdup(temp);
		ft_strdel(&temp);
		return (2);
	}
	return (1);
}

static int	readfile(int fd, char **stathicc, char **line)
{
	char	*buffer;
	char	*temp;
	int		i;

	buffer = ft_strnew(BUFF_SIZE);
	i = read(fd, buffer, BUFF_SIZE);
	if (i == -1)
		return (-1);
	if (i == 0 && stathicc[fd] != NULL)
		return (getlastline(fd, stathicc, buffer, line));
	if (i == 0 && stathicc[fd] == NULL)
	{
		ft_strdel(line);
		return (0);
	}
	if (i > 0)
		return (cpytostatic(fd, stathicc, buffer, line));
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*stathicc[8192];
	int			i;

	i = 1;
	if (fd < 0 || line == NULL || fd > 8192)
		return (-1);
	while (i > 0)
	{
		i = readfile(fd, stathicc, line);
		if (i == 2)
			return (1);
	}
	return (i);
}
