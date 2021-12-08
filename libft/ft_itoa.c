/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:49:29 by leotran           #+#    #+#             */
/*   Updated: 2021/11/13 23:15:39 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	icount(int num)
{
	int			count;
	long long	n;

	count = 0;
	n = num;
	if (n <= 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	int				count;
	char			*arr;

	num = n;
	count = icount(n);
	if (n < 0)
		num = num * (-1);
	arr = (char *)ft_memalloc(sizeof(char) * count + 1);
	if (!arr)
		return (NULL);
	arr[count] = '\0';
	while (--count >= 0)
	{
		arr[count] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		arr[0] = '-';
	return (arr);
}
