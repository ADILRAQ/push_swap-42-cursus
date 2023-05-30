/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:29:16 by araqioui          #+#    #+#             */
/*   Updated: 2022/12/29 16:48:44 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_check_sort(t_list *lst)
{
	t_list	*first;
	t_list	*second;

	if (!lst)
		return (0);
	first = lst;
	second = lst->next;
	while (second && second->data > first->data)
	{
		first = first->next;
		second = second->next;
	}
	if (second && second->data < first->data)
		return (0);
	return (1);
}
