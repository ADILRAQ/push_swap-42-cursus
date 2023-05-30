/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:58:54 by araqioui          #+#    #+#             */
/*   Updated: 2022/12/29 09:26:04 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_case_2_nb(t_list **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void	ft_case_3_nb(t_list **stack_a)
{
	t_list	*max;
	t_list	*min;

	while (!ft_check_sort(*stack_a))
	{
		max = ft_maximum(*stack_a);
		min = ft_minimum(*stack_a);
		if (max->data == (*stack_a)->data
			&& min->data == (*stack_a)->next->data)
		{
			ft_rotate(stack_a);
			write(1, "ra\n", 3);
		}
		else if (max->data == (*stack_a)->next->data
			&& min->data == ft_lstlast(*stack_a)->data)
		{
			ft_reverse_rotate(stack_a);
			write(1, "rra\n", 4);
		}
		else
			ft_case_2_nb(stack_a);
	}
}

static void	ft_mov_top(t_list **lst)
{
	t_list	*ptr;
	int		i;

	ptr = (*lst);
	i = 0;
	while (i <= 2)
	{
		ptr->mov[0] = i++;
		ptr = ptr->next;
	}
	ptr->mov[0] = -1;
}

void	ft_case_4_nb(t_list **stack_a, t_list **stack_b)
{
	t_list	*min;

	ft_mov_top(stack_a);
	min = ft_minimum(*stack_a);
	if (min->mov[0] >= 0)
	{
		while (min->mov[0])
		{
			ft_rotate(stack_a);
			write(1, "ra\n", 3);
			min->mov[0]--;
		}
	}
	else
	{
		ft_reverse_rotate(stack_a);
		write(1, "rra\n", 4);
	}
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
	ft_case_3_nb(stack_a);
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ft_case_5_nb(t_list **stack_a, t_list **stack_b)
{
	t_list	*min;
	t_list	*ptr;

	ft_update_indices(stack_a);
	ptr = (*stack_a);
	while (ptr->indice >= 0)
	{
		ptr->mov[0] = 2 - ptr->indice;
		ptr = ptr->next;
	}
	ptr->mov[0] = -2;
	ptr->next->mov[0] = -1;
	min = ft_minimum(*stack_a);
	ft_rotate_min_stk_a(stack_a, min);
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
	ft_case_4_nb(stack_a, stack_b);
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}
