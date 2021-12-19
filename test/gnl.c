/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 08:59:13 by leo               #+#    #+#             */
/*   Updated: 2021/12/19 00:32:45 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	getline(int i, int fd, char **stat_str, char **line)
{
	char	*temp;
	int		len;

	len = 0;
	if (ft_strchr(stat_str[fd], NL) != NULL)
	{
		while (stat_str[fd][len] != NL)
			len++;
		*line = ft_strsub(stat_str[fd], 0, len);
		temp = ft_strdup(ft_strchr(stat_str[fd], NL) + 1);
		ft_strdel(&stat_str[fd]);
		stat_str[fd] = ft_strdup(temp);
		ft_strdel(&temp);
		i = 1;
	}
	if (i == 0)
	{
		*line = ft_strdup(stat_str[fd]);
		ft_strdel(&stat_str[fd]);
		if (*line[0] != '\0')
			bytes_read = 1;
		else
			bytes_read = 0;
	}
	return (bytes_read);
}

static int	getlinefromstatic(int fd, char **stat_str, char **line)
{
	char	*temp;
	int		i;

	i = 0;
	while (stat_str[fd][i] != NL)
		i++;
	*line = ft_strsub(stat_str[fd], 0, i);
	temp = ft_strdup(ft_strchr(stat_str[fd], NL) + 1);
	ft_strdel(&stat_str[fd]);
	stat_str[fd] = ft_strdup(temp);
	ft_strdel(&temp);
	return (1);
}

static int	getlastline(int fd, char **stat_str, char **line)
{
	int	i;

	i = 0;
	*line = ft_strdup(stat_str[fd]);
	ft_strdel(&stat_str[fd]);
	if (*line[0] != '\0')
		i = 1;
	return (i);
}

static void	cpytostatic(int fd, char **stat_str, char *buffer, char **line)
{
	char	*temp;

	if (stat_str[fd] != NULL)
	{
		temp = ft_strdup(stat_str[fd]);
		ft_strdel(&stat_str[fd]);
		stat_str[fd] = ft_strjoin(temp, buffer);
		ft_strdel(&temp);
	}
	else
		stat_str[fd] = ft_strdup(buffer);
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
		//if (stat_str[fd] != NULL)
		//	i = getline(i, fd, stat_str, line);
		
		if (stat_str[fd] != NULL && ft_strchr(stat_str[fd], NL) != NULL)
			i = getlinefromstatic(fd, stat_str, line);
		if (i == 0 && stat_str[fd] != NULL)
			i = getlastline(fd, stat_str, line);
		if (i == 1 || i == 0)
			break ;
		i = read(fd, buffer, BUFF_SIZE);
		if (i >= 0)
			buffer[i] = '\0';
		if (i > 0)
			cpytostatic(fd, stat_str, buffer, line);
	}
	ft_strdel(&buffer);
	return (i);
}
