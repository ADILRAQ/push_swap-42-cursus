/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:52:04 by araqioui          #+#    #+#             */
/*   Updated: 2022/12/29 16:54:06 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// The last node be first

void	ft_reverse_rotate(t_list **top)
{
	t_list	*last;
	t_list	*previous;

	if (!(*top) || !(*top)->next)
		return ;
	last = ft_lstlast(*top);
	previous = *top;
	while (previous->next != last)
		previous = previous->next;
	last->prev = NULL;
	last->next = *top;
	(*top)->prev = last;
	previous->next = NULL;
	(*top) = last;
}
