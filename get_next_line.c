/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 08:59:13 by leo               #+#    #+#             */
/*   Updated: 2021/12/08 10:10:14 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	getlastline(char *stathicc, char *buffer, char **line)
{
	char	*temp;

	if (ft_strchr(stathicc, NL) != NULL)
	{
		*line = ft_strccpy(stathicc, NL);
		temp = ft_strdup(ft_strchr(stathicc, NL) + 1);
		ft_strdel(&stathicc);
		stathicc = ft_strdup(temp);
		ft_strdel(&temp);
	}
	else
	{
		*line = ft_strdup(stathicc);
		ft_strdel(&stathicc);
	}
	ft_strdel(&buffer);
	return (1);
}

static int	cpytostatic(char *stathicc, char *buffer, char **line)
{
	
}

static int	readfile(int fd, char *stathicc, char **line)
{
	char	*buffer;
	char	*temp;
	int		i;

	buffer = ft_strnew(BUFF_SIZE);
	i = read(fd, buffer, BUFF_SIZE);
	if (i == -1)
		return (-1);
	if (i == 0 && stathicc != NULL)
		return (getlastline(stathicc, buffer, line));
	if (i > 0)
	{
		
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*stathicc[8196];
	int			i;

	i = 1;
	if (fd < 0 || line == NULL)
		return (-1);
	while (i > 0)
	{
		i = readfile(fd, stathicc[fd], line);
		if (i == 2)
			return (1);
	}
	return (i);
}
