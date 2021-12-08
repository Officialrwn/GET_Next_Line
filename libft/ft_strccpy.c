/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:55:38 by leotran           #+#    #+#             */
/*   Updated: 2021/12/06 16:08:34 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strccpy(char *src, int c)
{
	char	*str;
	int		i;

	i = 0;
	if (src == NULL || c == 0 || ft_strchr(src, c) == NULL)
		return (0);
	else
	{
		while (src[i] != c)
			i++;
		str = ft_strsub(src, 0, i);
	}
	return (str);
}
