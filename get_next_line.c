/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:51:02 by leotran           #+#    #+#             */
/*   Updated: 2021/12/06 10:50:08 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	countnextnl(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != NL)
		i++;
	return (i);
}

char	*ft_cpyfromstatic(int fd, char **stathicc)
{
	char	*temp;
	char	*nextline;
	
	nextline = ft_strsub(stathicc[fd], 0, countnextnl(stathicc[fd])); // nextline = str before NL
	if (*(ft_strchr(stathicc[fd], NL) + 1) != '\0') // if NL + 1 is not NULLbyte
	{
		temp = ft_strdup(ft_strchr(stathicc[fd], NL) + 1); //cpy leftover from static to temp
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
	return (nextline);
}

int	get_next_line(const int fd, char **line)
{
	char		*buffer;
	char		*nextline;
	char		*temp;
	static char *stathicc[4096];

	buffer = ft_strnew(BUFF_SIZE);
	if (stathicc[fd] != NULL && ft_strchr(stathicc[fd], NL) != NULL) //if static is not empty && static has NL
	{
		*line = ft_cpyfromstatic(fd, stathicc);
		return (1);
	}
	else
	{
		while (read(fd, buffer, BUFF_SIZE))
		{
			if (ft_strchr(buffer, NL) == NULL) //if buffer has no NL
			{
				if (stathicc[fd] != NULL)
				{
					temp = ft_strdup(stathicc[fd]);
					free(stathicc[fd]);
					stathicc[fd] = ft_strjoin(temp, buffer);
				}
				else
					stathicc[fd] = ft_strdup(buffer);
			}
			else
			{
				if (stathicc[fd] != NULL) // stat is not empty
				{
					temp = ft_strsub(buffer, 0,countnextnl(buffer)); // st1
					nextline = ft_strjoin(stathicc[fd], temp); // nextline = Te + st1
					free(stathicc[fd]);
				}
				else
					nextline = ft_strsub(buffer, 0, countnextnl(buffer)); //cpy str before NL
				*line = nextline;
				stathicc[fd] = ft_strdup(ft_strchr(buffer, NL) + 1); //cpy leftover to static
				return (1);
			}
		}
	}
	return (0);
}
