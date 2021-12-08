/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:04:53 by leotran           #+#    #+#             */
/*   Updated: 2021/11/22 15:56:06 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;

	list = (*alst);
	(*del)(list->content, list->content_size);
	if (list != NULL)
	{
		free(list);
		list = NULL;
		*alst = NULL;
	}
}
