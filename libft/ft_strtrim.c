/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:46:26 by leotran           #+#    #+#             */
/*   Updated: 2021/11/22 11:40:53 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	startpos;
	char			*arr;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	startpos = i;
	if (i != ft_strlen(s))
	{
		while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		{
			i++;
			j--;
		}
	}
	arr = ft_strsub(s, startpos, ft_strlen(s) - i);
	if (!arr)
		return (NULL);
	return (arr);
}
