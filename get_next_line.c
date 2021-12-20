/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 08:59:13 by leo               #+#    #+#             */
/*   Updated: 2021/12/20 22:11:42 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	getline(int i, int fd, char **stat_str, char **line)
{
	char	*temp;
	int		len;

	len = 0;
	if (ft_strchr(stat_str[fd], '\n') != NULL)
	{
		while (stat_str[fd][len] != '\n')
			len++;
		*line = ft_strsub(stat_str[fd], 0, len);
		temp = ft_strdup(ft_strchr(stat_str[fd], '\n') + 1);
		ft_strdel(&stat_str[fd]);
		stat_str[fd] = temp;
		i = 1;
	}
	else if (i == 0)
	{
		*line = ft_strdup(stat_str[fd]);
		ft_strdel(&stat_str[fd]);
		if (*line[0] != '\0')
			i = 1;
	}
	return (i);
}

static int	cpytostatic(int fd, char **stat_str, char *buffer)
{
	char	*temp;

	if (stat_str[fd] != NULL)
	{
		temp = ft_strjoin(stat_str[fd], buffer);
		ft_strdel(&stat_str[fd]);
		stat_str[fd] = temp;
	}
	else
		stat_str[fd] = ft_strdup(buffer);
	return (2);
}

int	get_next_line(const int fd, char **line)
{
	static char	*stat_str[FD_SIZE];
	char		*buffer;
	int			i;

	i = 2;
	buffer = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || fd >= FD_SIZE)
		i = -1;
	while (i >= 0)
	{
		if (stat_str[fd] != NULL)
			i = getline(i, fd, stat_str, line);
		if (i == 1 || i == 0)
			break ;
		i = read(fd, buffer, BUFF_SIZE);
		if (i > 0)
		{
			buffer[i] = '\0';
			i = cpytostatic(fd, stat_str, buffer);
		}
	}
	ft_strdel(&buffer);
	return (i);
}
