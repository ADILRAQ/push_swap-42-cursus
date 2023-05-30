/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:56:37 by araqioui          #+#    #+#             */
/*   Updated: 2022/12/29 10:34:48 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*ft_minimum(t_list *lst)
{
	t_list	*min;
	t_list	*ptr;

	min = lst;
	ptr = lst->next;
	while (ptr)
	{
		if (min->data > ptr->data)
			min = ptr;
		ptr = ptr->next;
	}
	return (min);
}

t_list	*ft_maximum(t_list *lst)
{
	t_list	*max;
	t_list	*ptr;

	max = lst;
	ptr = lst->next;
	while (ptr)
	{
		if (max->data < ptr->data)
			max = ptr;
		ptr = ptr->next;
	}
	return (max);
}

t_list	*ft_minimum_mov(t_list *lst)
{
	t_list	*min;
	t_list	*ptr;

	min = lst;
	ptr = lst->next;
	while (ptr)
	{
		if (min->mov[2] > ptr->mov[2])
			min = ptr;
		ptr = ptr->next;
	}
	return (min);
}
