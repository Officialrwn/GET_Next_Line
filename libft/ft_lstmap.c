/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:10:38 by leotran           #+#    #+#             */
/*   Updated: 2021/11/22 13:01:11 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*temp;

	if (lst == NULL || f == NULL)
		return (NULL);
	temp = ft_lstnew((*f)(lst)->content, (*f)(lst)->content_size);
	if (!temp)
		return (NULL);
	head = temp;
	while (lst->next != NULL)
	{
		lst = lst->next;
		temp->next = ft_lstnew((*f)(lst)->content, (*f)(lst)->content_size);
		if (!temp->next)
		{
			ft_lstdel(&head, &ft_bzero);
			return (NULL);
		}
		temp = temp->next;
	}
	return (head);
}
