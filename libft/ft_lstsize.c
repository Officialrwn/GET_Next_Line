/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:48:03 by leotran           #+#    #+#             */
/*   Updated: 2021/11/22 10:19:02 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list **lst)
{
	int	i;

	i = 1;
	if (*lst == NULL)
		return (0);
	while ((*lst)->next != NULL)
	{
		i++;
		(*lst) = (*lst)->next;
	}
	return (i);
}
