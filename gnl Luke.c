/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:27:04 by llonnrot          #+#    #+#             */
/*   Updated: 2021/12/20 14:29:50 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct s_gnl
{
    char        *buffer;
    char        *temp;
    char        *temp2;
    int            readret;
}                t_gnl;
#define NL '\n'

static	int	ft_error(t_gnl vrbls) // a function to free allocated memory if error occurs;
{
	ft_strdel(&vrbls.temp);
	ft_strdel(&vrbls.temp2);
	ft_strdel(&vrbls.buffer);
	return (-1);
}

static	int	ft_return_1_or_0(const int fd, t_gnl vrbls, // a function that returns 1 or 0 depending on variable values;
								char **statik, char **line)
{
	if (vrbls.readret == 0 && ft_strlen(vrbls.temp) == 0) // this will execute when the file has been read;
	{
		*line = vrbls.temp; // temp stores anything before '\n' from statik variable;
		ft_strdel(&statik[fd]);
		return (0); // end of file;
	}
	else
	{
		*line = vrbls.temp;
		if (ft_strcmp(statik[fd], vrbls.temp) == 0) // this means that there is no '\n' in statik and that the last line has been read;
		{
			ft_strdel(&statik[fd]);
			return (1);
		}
		vrbls.temp2 = ft_strdup((ft_strchr(statik[fd], NL) + 1)); // copy anything after '\n' in to temp2 to copy it afterword to statik;
		ft_strdel(&statik[fd]);
		statik[fd] = ft_strdup(vrbls.temp2);
		ft_strdel(&vrbls.temp2);
		return (1);
	}
}

static t_gnl	ft_read(const int fd, t_gnl vrbls, char **statik) // a function to read from file opened to fd and store it into statik variable
{																	// and everything before '\n' to temp variable;
	while (vrbls.readret) // will read until read returns 0;
	{
		vrbls.readret = read(fd, vrbls.buffer, BUFF_SIZE); // readret storing the return of read;
		if (vrbls.readret < 0) // read returns -1 if error;
		{
			vrbls.readret = -1;
			return (vrbls); // cant return -1 here right away because function returns a struct not a integer;
		}
		ft_strdel(&statik[fd]);
		statik[fd] = ft_strjoin(vrbls.temp, vrbls.buffer); // on first round temp is empty but does not matter;
		ft_strdel(&vrbls.temp);
		vrbls.temp = ft_strdup(statik[fd]); // storing statik to temp for joining on the next round;
		ft_bzero(vrbls.buffer, ft_strlen(vrbls.buffer)); // emptying buffer for next round;
		if (ft_strchr(statik[fd], NL)) // if a '\n' is stored in the string in statik, will break out from loop;
			break ;
	}
	ft_strdel(&vrbls.buffer);
	ft_strdel(&statik[fd]);
	statik[fd] = ft_strjoin(vrbls.temp2, vrbls.temp); // joining temp2 to the front of statik from previous function call;
	ft_strdel(&vrbls.temp2);
	ft_strdel(&vrbls.temp);
	vrbls.temp = ft_strsub(statik[fd], 0, ft_count_c(statik[fd], '\n')); // storing anything before '\n' from statik to temp;
	return (vrbls);
}

static int	ft_return_1(const int fd, t_gnl vrbls, char **statik, char **line) // a function to return 1;
{
	*line = ft_strsub(statik[fd], 0, ft_count_c(statik[fd], '\n')); // line will point to pointer that stores anything before '\n' from statik;
	ft_strdel(&vrbls.temp2);
	vrbls.temp2 = ft_strdup(statik[fd]); // temporary storage;
	ft_strdel(&statik[fd]);
	statik[fd] = ft_strsub(vrbls.temp2, ft_count_c(vrbls.temp2, '\n') + 1, // will store anything after '\n' temp2 that stores a copy of statik
			ft_strlen(ft_strchr(vrbls.temp2, NL) + 1));						// from the line before this;
	ft_strdel(&vrbls.temp);
	ft_strdel(&vrbls.temp2);		// freeing a bunch of pointers that were allocated in the beginning of function call;
	ft_strdel(&vrbls.buffer);
	return (1);
}

int	get_next_line(const int fd, char **line) // a function to get the next line of a file read to fd;
{
	static char	*statik[FD_SIZE]; // declaring a statik double pointer to store a string read from fd;
	t_gnl		vrbls; // declaring a struct of multiple variables, using struct to save lines and passing more than 4 variables;

	vrbls.readret = 1;
	vrbls.temp = ft_strnew(BUFF_SIZE);
	vrbls.temp2 = ft_strnew(BUFF_SIZE); // allocating memory and setting '\0' to end of string;
	vrbls.buffer = ft_strnew(BUFF_SIZE);
	if (line == NULL || fd < 0) // error checks;
		return (ft_error(vrbls)); // function call to function that handles memory freeing and returns -1;
	if (statik[fd] != NULL) // if there is something stored in statik;
	{
		if (ft_strchr(statik[fd], NL)) // if the string in statik has a '\n';
			return (ft_return_1(fd, vrbls, statik, line));
		else // if not '\n' in statik;
		{
			ft_strdel(&vrbls.temp2);
			vrbls.temp2 = ft_strsub(statik[fd], 0, ft_strlen(statik[fd]));
		}
	}
	vrbls = ft_read(fd, vrbls, statik); // function call to read from fd, save string to statik, and anything before '\n' to temp;
	if (vrbls.readret == -1) // error check;
		return (ft_error(vrbls));
	return (ft_return_1_or_0(fd, vrbls, statik, line));
}
