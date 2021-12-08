/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:17:45 by leotran           #+#    #+#             */
/*   Updated: 2021/11/26 15:59:38 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*head;

	temp = (*alst);
	while (temp != NULL)
	{
		head = temp->next;
		(*del)(temp->content, temp->content_size);
		free(temp);
		temp = head;
	}
	*alst = NULL;
}
