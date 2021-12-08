/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:23:23 by leotran           #+#    #+#             */
/*   Updated: 2021/11/03 13:25:32 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (src[j] == '\0')
			dest[i] = '\0';
		else
		{
			dest[i] = src[j];
			j++;
		}
		i++;
	}
	return (dest);
}
