/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:46:34 by leotran           #+#    #+#             */
/*   Updated: 2021/12/20 15:14:26 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	int		i;
	char	*arr;

	i = 0;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr || s == NULL)
		return (NULL);
	arr[len] = '\0';
	while (len--)
	{
		arr[i] = s[start];
		i++;
		start++;
	}
	return (arr);
}
