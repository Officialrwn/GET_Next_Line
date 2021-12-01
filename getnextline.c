/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:51:02 by leotran           #+#    #+#             */
/*   Updated: 2021/12/01 16:17:05 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
# include <fcntl.h>
# define BUF_SIZE 5
int	countcharsbeforenewline(char *str)
{
	int i = 0;
	
	while (str[i] != '\n')
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	ft_bzero(buf, BUF_SIZE + 1);
	char arr[4][6];
	ft_bzero(arr[0], 6);
	ft_bzero(arr[1], 6);
	ft_bzero(arr[2], 6);
	ft_bzero(arr[3], 6);
	
	
	char temp[6];
	ft_bzero(temp, 6);
	int num[2] = { 0, 0 };

	static char *line;
	char *test;
	int i = 0, count = 0;
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd != -1)
	{
		while (read(fd, buf, BUF_SIZE))
		{
			if (!line)
			{
				printf("first cpy\n");
				ft_strncpy(arr[i], buf, countcharsbeforenewline(buf));
				line = ft_strdup(ft_strchr(buf, '\n') + 1);
				printf("line0 = %s\n", line);
				
			}
			else
			{
				ft_strncpy(temp, buf, countcharsbeforenewline(buf));
				test = ft_strjoin(line, temp);
				ft_strcpy(arr[i], test);
				free(line);
				line = ft_strdup(ft_strchr(buf, '\n') + 1);
				printf("line1 = %s\n", line);
			}
		
			printf("arr[%d] = %s\n", i, arr[i]);
			i++;
		}
		printf("line = %s\n", line);
		printf("test = %s\n", test);
		
		//printf("c = %c ", temp[0]);
		//printf("c = %c ", temp[1]);
		//printf("c = %c ", temp[2]);
		//printf("c = %c ", temp[3]);
		
		
		if (close(fd) == -1)
			return (0);
	}
	else
		ft_putstr("failed to open file.");
	return (0);
}
	/*if (i == 0)
			{
				printf("i count = %d\n", countcharsbeforenewline(temp));
				ft_strncpy(arr[0], temp, 3);
				printf("ft_atoi = %d\n", ft_atoi(arr[0]));
				i = 1;
			}*/