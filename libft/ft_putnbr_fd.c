/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:13:34 by leotran           #+#    #+#             */
/*   Updated: 2021/11/16 14:40:02 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		i;
	int		count;

	num = n;
	i = 1;
	count = 0;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	while (i <= (num / 10))
	{
		i = i * 10;
		count++;
	}
	while (count > 0)
	{
		ft_putchar_fd((num / i) + '0', fd);
		num %= i;
		i /= 10;
		count--;
	}
	ft_putchar_fd(num + '0', fd);
}
