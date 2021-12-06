/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:51:02 by leotran           #+#    #+#             */
/*   Updated: 2021/12/06 17:13:42 by leotran          ###   ########.fr       */
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
		free(stathicc[fd]);
		stathicc[fd] = ft_strdup(temp);
		free(temp);
		temp = NULL;
	}
	else
	{
		free(stathicc[fd]);
		stathicc[fd] = NULL;
	}
	return (1);
}

void	ft_cpytostatic(int fd, char **stathicc, char *buffer)
{
	char	*temp;

	if (stathicc[fd] != NULL)
	{
		temp = ft_strdup(stathicc[fd]);
		free(stathicc[fd]);
		stathicc[fd] = ft_strjoin(temp, buffer);
	}
	else
		stathicc[fd] = ft_strdup(buffer);
}

int	ft_cpyjoinfromstatic(int fd, char **stathicc, char *buffer, char **line)
{
	char	*temp;
	char	*nextline;

	if (stathicc[fd] != NULL)
	{
		temp = ft_strccpy(buffer, NL);
		nextline = ft_strjoin(stathicc[fd], temp);
		free(stathicc[fd]);
	}
	else
		nextline = ft_strccpy(buffer, NL);
	stathicc[fd] = ft_strdup(ft_strchr(buffer, NL) + 1);
	*line = nextline;
	return (1);
}

int	ft_lastline(int fd, char **stathicc, char **line)
{
	if (stathicc[fd] != NULL)
	{
		*line = ft_strsub(stathicc[fd], 0, ft_strlen(stathicc[fd]));
		free(stathicc[fd]);
		stathicc[fd] = NULL;
		return (1);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*stathicc[4096];
	char		*buffer;

	buffer = ft_strnew(BUFF_SIZE);
	if (stathicc[fd] != NULL && ft_strchr(stathicc[fd], NL) != NULL)
		return (ft_getlinefromstatic(fd, stathicc, line));
	else
	{
		if (fd < 0)
			return (-1);
		while (read(fd, buffer, BUFF_SIZE))
		{
			if (ft_strchr(buffer, NL) == NULL)
				ft_cpytostatic(fd, stathicc, buffer);
			else
				return (ft_cpyjoinfromstatic(fd, stathicc, buffer, line));
		}
	}
	return (ft_lastline(fd, stathicc, line));
}
