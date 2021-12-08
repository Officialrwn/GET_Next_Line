/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:26:48 by leotran           #+#    #+#             */
/*   Updated: 2021/11/13 18:50:32 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			c;
	char			*arr;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	arr = ft_strdup(s);
	if (arr)
	{
		while (s[i])
		{
			c = (*f)(i, s[i]);
			arr[i] = c;
			i++;
		}
	}
	return (arr);
}
