/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:13:46 by leotran           #+#    #+#             */
/*   Updated: 2021/11/16 14:41:27 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	int		i;
	char	*arr;

	i = 0;
	if (s == NULL)
		return ;
	arr = (char *)s;
	while (arr[i])
	{
		write(fd, &arr[i], 1);
		i++;
	}
}
