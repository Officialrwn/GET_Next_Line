/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:51:02 by leotran           #+#    #+#             */
/*   Updated: 2021/12/04 16:27:30 by leotran          ###   ########.fr       */
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

int	get_next_line(const int fd, char **line)
{
	char		*buffer;
	char		*nextline;
	char		*temp;
	static char *stathicc[2];

	buffer = ft_strnew(BUFF_SIZE);
	if (stathicc[0] != NULL && ft_strchr(stathicc[0], NL) != NULL) //if static is not empty && static has NL
	{
		nextline = ft_strsub(stathicc[0], 0, countnextnl(stathicc[0])); // nextline = str before NL
		*line = nextline;
		if (*(ft_strchr(stathicc[0], NL) + 1) != '\0') // if NL + 1 is not NULLbyte
		{
			temp = ft_strdup(ft_strchr(stathicc[0], NL) + 1); //cpy leftover from static to temp
			free(stathicc[0]);
			stathicc[0] = ft_strdup(temp);
			free(temp);
			temp = NULL;
		}
		else
		{
			free(stathicc[0]);
			stathicc[0] = NULL;
		}
		return (1);
	}
	else
	{
		while (read(fd, buffer, BUFF_SIZE))
		{
			if (ft_strchr(buffer, NL) == NULL) //if buffer has no NL
			{
				if (stathicc[0] != NULL)
				{
					temp = ft_strdup(stathicc[0]);
					free(stathicc[0]);
					stathicc[0] = ft_strjoin(temp, buffer);
				}
				else
					stathicc[0] = ft_strdup(buffer);
			}
			else
			{
				if (stathicc[0] != NULL) // stat is not empty
				{
					temp = ft_strsub(buffer, 0,countnextnl(buffer)); // st1
					nextline = ft_strjoin(stathicc[0], temp); // nextline = Te + st1
					free(stathicc[0]);
				}
				else
					nextline = ft_strsub(buffer, 0, countnextnl(buffer)); //cpy str before NL
				*line = nextline;
				stathicc[0] = ft_strdup(ft_strchr(buffer, NL) + 1); //cpy leftover to static
				return (1);
			}
		}
	}
	return (0);
}
