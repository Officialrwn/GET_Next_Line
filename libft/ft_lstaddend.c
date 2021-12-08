/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:03:57 by leotran           #+#    #+#             */
/*   Updated: 2021/11/22 15:11:43 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*temp;

	temp = (*alst);
	if (alst == NULL || new == NULL)
		return ;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}
