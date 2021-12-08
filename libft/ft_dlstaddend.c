/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:10:56 by leotran           #+#    #+#             */
/*   Updated: 2021/11/23 17:44:17 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstaddend(t_dlist **alst, t_dlist *new)
{
	t_dlist	*temp;

	temp = (*alst);
	if (alst == NULL || new == NULL)
		return ;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->previous = temp;
}
