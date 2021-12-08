/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:40:52 by leotran           #+#    #+#             */
/*   Updated: 2021/11/23 18:09:20 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdelfront(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist	*list;

	list = (*alst);
	(*del)(list->content, list->content_size);
	if (list != NULL)
	{
		*alst = list->next;
		free(list);
		list = NULL;
		(*alst)->previous = NULL;
	}
}
