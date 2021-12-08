/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:02:37 by leotran           #+#    #+#             */
/*   Updated: 2021/11/23 17:38:06 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstaddfront(t_dlist **alst, t_dlist *new)
{
	new->next = (*alst);
	(*alst)->previous = new;
	(*alst) = new;
}
