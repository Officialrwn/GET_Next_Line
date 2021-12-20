/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:26:36 by leotran           #+#    #+#             */
/*   Updated: 2021/12/20 15:14:11 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*arr;
	int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		arr[len] = s1[len];
		len++;
	}
	while (s2[i])
	{
		arr[len] = s2[i];
		i++;
		len++;
	}
	arr[len] = '\0';
	return (arr);
}
