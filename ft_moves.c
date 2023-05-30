/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:57:02 by araqioui          #+#    #+#             */
/*   Updated: 2022/12/24 13:20:40 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_stack_a_b_moves_top(t_list **stack_a, t_list **stack_b, int j_b)
{
	t_list	*ptr;
	int		i;
	int		j;

	ptr = (*stack_b);
	i = 0;
	while (ptr)
	{
		if (i <= (*stack_b)->indice)
			ptr->mov[1] = i++;
		else
			ptr->mov[1] = j_b++;
		ptr = ptr->next;
	}
	ptr = (*stack_a);
	i = 0;
	j = ft_lstlast((*stack_a))->indice;
	while (ptr)
	{
		if (i <= (*stack_a)->indice)
			ptr->mov[0] = i++;
		else
			ptr->mov[0] = j++;
		ptr = ptr->next;
	}
}

static int	ft_maximum_pos(t_list *lst, t_list *ptr, t_list *first)
{
	t_list	*max;

	if (ptr->data > first->data && ptr->data < lst->data)
		return (0);
	max = lst;
	lst = lst->next;
	while (lst)
	{
		if (max->data < lst->data)
			max = lst;
		lst = lst->next;
	}
	if (!max->next)
		return (0);
	return (max->next->mov[0]);
}

static void	ft_marking_moves(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;
	t_list	*first;
	t_list	*second;

	ft_stack_a_b_moves_top(stack_a, stack_b, ft_lstlast(*stack_b)->indice);
	ptr = (*stack_b);
	while (ptr)
	{
		first = (*stack_a);
		second = (*stack_a)->next;
		while (second)
		{
			if (second->data > ptr->data && ptr->data > first->data)
			{
				ptr->mov[0] = second->mov[0];
				break ;
			}
			first = first->next;
			second = second->next;
		}
		if (!second)
			ptr->mov[0] = ft_maximum_pos(*stack_a, ptr, first);
		ptr = ptr->next;
	}
}

void	ft_moves(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;

	ft_update_indices(stack_a);
	if (*stack_b)
	{
		ft_update_indices(stack_b);
		ft_marking_moves(stack_a, stack_b);
		ptr = (*stack_b);
		while (ptr)
		{
			if (ptr->mov[0] < 0)
				ptr->mov[2] = -(ptr->mov[0]);
			else
				ptr->mov[2] = ptr->mov[0];
			if (ptr->mov[1] < 0)
				ptr->mov[2] += -(ptr->mov[1]);
			else
				ptr->mov[2] += ptr->mov[1];
			ptr = ptr->next;
		}
	}
	else
		ft_stack_a_b_moves_top(stack_a, stack_b, 0);
}
