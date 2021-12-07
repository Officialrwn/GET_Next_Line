/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:51:02 by leotran           #+#    #+#             */
/*   Updated: 2021/12/07 15:38:44 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_getlinefromstatic(int fd, char **stathicc, char **line)
{
	char	*temp;
	char	*nextline;

	nextline = ft_strccpy(stathicc[fd], NL);
	*line = nextline;
	if (*(ft_strchr(stathicc[fd], NL) + 1) != '\0')
	{
		temp = ft_strdup(ft_strchr(stathicc[fd], NL) + 1);
		ft_strdel(&stathicc[fd]);
		stathicc[fd] = ft_strdup(temp);
		ft_strdel(&temp);
	}
	else
	{
		ft_strdel(&stathicc[fd]);
	}
	return (1);
}

void	ft_cpytostatic(int fd, char **stathicc, char *buffer)
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
	ft_bzero(buffer, BUFF_SIZE + 1);
}

int	ft_cpyjoinfromstatic(int fd, char **stathicc, char *buffer, char **line)
{
	char	*temp;
	char	*nextline;

	if (stathicc[fd] != NULL && ft_strchr(stathicc[fd], NL) != NULL)
	{
		temp = ft_strccpy(buffer, NL);
		nextline = ft_strjoin(stathicc[fd], temp);
		ft_strdel(&stathicc[fd]);
		ft_strdel(&temp);
	}
	else if (ft_strchr(buffer, NL) != NULL)
		nextline = ft_strccpy(buffer, NL);
	else
		nextline = ft_strsub(stathicc[fd], 0, ft_strlen(stathicc[fd]));
	stathicc[fd] = ft_strdup(ft_strchr(buffer, NL) + 1);
	*line = nextline;
	ft_bzero(buffer, BUFF_SIZE + 1);
	return (1);
}

int	ft_lastline(int fd, char **stathicc, char **line)
{
	if (stathicc[fd] != NULL)
	{
		*line = ft_strsub(stathicc[fd], 0, ft_strlen(stathicc[fd]));
		ft_strdel(&stathicc[fd]);
		return (1);
	}
	return (-1);
}

int	ft_readline(int fd, char **stathicc, char **line)
{
	int		i;
	char	*buffer;

	buffer = ft_strnew(BUFF_SIZE);
	i = read(fd, buffer, BUFF_SIZE);
	if (i < 0)
		return (-1);
		//printf("i = %d\n", i);
	while (i > 0)
	{
		
		if (ft_strchr(buffer, NL) == NULL && buffer[0] != '\0')
		{
			ft_cpytostatic(fd, stathicc, buffer);
		//	printf("test\n");
		}
		if (buffer[0] == '\0')
			i = 0;
		else
		{
			return (ft_cpyjoinfromstatic(fd, stathicc, buffer, line));
		//	printf("test1\n");
		}
	}
	//printf("test\n");
	return (ft_lastline(fd, stathicc, line));
}

int	get_next_line(const int fd, char **line)
{
	static char	*stathicc[4096];

	if (fd < 0 || line == NULL)
		return (-1);
	if (stathicc[fd] != NULL && ft_strchr(stathicc[fd], NL) != NULL)
		return (ft_getlinefromstatic(fd, stathicc, line));
	else
	{
		return (ft_readline(fd, stathicc, line)); 
	}
}
