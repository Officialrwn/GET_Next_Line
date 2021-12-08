/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:26:41 by leotran           #+#    #+#             */
/*   Updated: 2021/11/16 14:38:58 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char*s, char (*f)(char))
{
	int		i;
	char	c;
	char	*arr;

	i = 0;
	if (!s)
		return (NULL);
	arr = ft_strdup(s);
	if (arr)
	{
		while (s[i])
		{
			c = (*f)(s[i]);
			arr[i] = c;
			i++;
		}
	}
	return (arr);
}
