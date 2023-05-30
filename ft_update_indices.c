/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_indices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:41:16 by araqioui          #+#    #+#             */
/*   Updated: 2022/12/26 11:26:42 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_update_indices(t_list **lst)
{
	t_list	*ptr;
	int		idx;

	idx = ft_lstsize((*lst)) / 2;
	ptr = (*lst);
	while (ptr)
	{
		ptr->indice = idx--;
		ptr = ptr->next;
	}
}
