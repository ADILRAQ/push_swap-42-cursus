/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:13:20 by araqioui          #+#    #+#             */
/*   Updated: 2022/12/29 20:34:43 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_push(t_list **lst1, t_list **lst2)
{
	t_list	*first;

	if (!(*lst1))
		return ;
	if (*lst2)
	{
		first = (*lst1);
		(*lst1) = (*lst1)->next;
		if (*lst1)
			(*lst1)->prev = NULL;
		first->next = (*lst2);
		(*lst2)->prev = first;
		(*lst2) = first;
	}
	else
	{
		(*lst2) = (*lst1);
		(*lst1) = (*lst1)->next;
		if (*lst1)
			(*lst1)->prev = NULL;
		(*lst2)->next = NULL;
	}
}
