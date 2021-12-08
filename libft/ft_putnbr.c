/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:54:57 by leotran           #+#    #+#             */
/*   Updated: 2021/11/13 23:12:05 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	num;
	int		i;
	int		count;

	num = n;
	i = 1;
	count = 0;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	while (i <= (num / 10))
	{
		i = i * 10;
		count++;
	}
	while (count > 0)
	{
		ft_putchar((num / i) + '0');
		num %= i;
		i /= 10;
		count--;
	}
	ft_putchar(num + '0');
}
