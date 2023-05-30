/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:19:32 by araqioui          #+#    #+#             */
/*   Updated: 2022/12/21 09:51:47 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*prev;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		prev = (*lst);
		(*lst) = (*lst)->next;
		prev->lis = NULL;
		free(prev);
	}
	lst = NULL;
}
