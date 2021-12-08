/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:32:51 by leotran           #+#    #+#             */
/*   Updated: 2021/11/22 13:42:18 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelend(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	temp = (*alst);
	if (alst == NULL || del == NULL)
		return ;
	while (temp->next->next != NULL)
		temp = temp->next;
	(*del)(temp->next->content, temp->next->content_size);
	if (temp->next != NULL)
		free(temp->next);
	temp->next = NULL;
}
