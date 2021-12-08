/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:26:36 by leotran           #+#    #+#             */
/*   Updated: 2021/11/13 18:03:43 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*arr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)ft_memalloc(sizeof(char) * len + 1);
	if (!arr)
		return (NULL);
	arr = ft_strcpy(arr, s1);
	arr = ft_strcat(arr, s2);
	return (arr);
}
