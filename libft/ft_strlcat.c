/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:23:23 by leotran           #+#    #+#             */
/*   Updated: 2021/11/17 14:49:22 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = ft_strlen(dest);
	j = 0;
	len = i + ft_strlen(src);
	if (i >= n)
		len = ft_strlen(src) + n;
	while (i + 1 < n && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (len);
}
