/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:58:39 by leotran           #+#    #+#             */
/*   Updated: 2021/11/23 18:09:28 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist	*list;

	list = (t_dlist *)ft_memalloc(sizeof(t_dlist));
	if (!list)
		return (NULL);
	list->content = ft_memalloc(sizeof(content) * content_size);
	if (!list->content)
	{
		free(list);
		list = NULL;
		return (NULL);
	}
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	list->previous = NULL;
	list->next = NULL;
	return (list);
}
