/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:46:30 by leotran           #+#    #+#             */
/*   Updated: 2021/11/17 14:01:12 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countstrings(const char *s, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			x++;
		i++;
	}
	if (x == 0)
		x = 1;
	return (x);
}

static void	*freearrays(char **arr, int x)
{
	while (x--)
	{
		if (arr[x])
			free(arr[x]);
	}
	return (NULL);
}

static void	*cptoarray(char **arr, const char *s, char c)
{
	t_var	i;

	i.i = 0;
	i.x = 0;
	while (s[i.i])
	{
		i.count = 0;
		if (s[i.i] != c)
		{
			i.j = i.i;
			while (s[i.i + 1] != c && s[i.i + 1] != '\0')
			{
				i.count++;
				i.i++;
			}
			arr[i.x] = ft_strsub(s, i.j, i.count + 1);
			if (!arr[i.x])
				return (freearrays(arr, i.x));
			i.x++;
		}
		i.i++;
	}
	return (0);
}

char	**ft_strsplit(const char *s, char c)
{
	int		wrdlen;
	char	**arr;

	if (!s)
		return (NULL);
	wrdlen = countstrings(s, c);
	arr = (char **)ft_memalloc(sizeof(char *) * wrdlen + 1);
	if (arr)
	{
		cptoarray(arr, s, c);
		arr[wrdlen] = (char *)ft_memalloc(sizeof(char) * 1);
		if (!arr[wrdlen])
		{
			freearrays(arr, wrdlen);
			free(arr);
			return (NULL);
		}
		arr[wrdlen] = 0;
	}
	return (arr);
}
