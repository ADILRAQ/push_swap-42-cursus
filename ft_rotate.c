/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:44:26 by araqioui          #+#    #+#             */
/*   Updated: 2022/12/29 20:35:15 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_rotate(t_list **top)
{
	t_list	*first;
	t_list	*last;

	if (!(*top) || !(*top)->next)
		return ;
	first = (*top);
	(*top) = (*top)->next;
	(*top)->prev = NULL;
	first->next = NULL;
	last = ft_lstlast(*top);
	last->next = first;
	first->prev = last;
}
