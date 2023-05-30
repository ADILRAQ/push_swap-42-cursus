/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:30:27 by araqioui          #+#    #+#             */
/*   Updated: 2022/12/29 10:44:21 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_rotat_stacks_2(t_list **stack_a, t_list *min)
{
	if (min->mov[0] <= 0)
	{
		while (min->mov[0])
		{
			ft_reverse_rotate(stack_a);
			write(1, "rra\n", 4);
			min->mov[0]++;
		}
	}
	else
	{
		while (min->mov[0])
		{
			ft_rotate(stack_a);
			write(1, "ra\n", 3);
			min->mov[0]--;
		}
	}
}

static void	ft_continu_rotat_stacks_2(t_list **stack_b, t_list *min)
{
	if (min->mov[1] <= 0)
	{
		while (min->mov[1])
		{
			ft_reverse_rotate(stack_b);
			write(1, "rrb\n", 4);
			min->mov[1]++;
		}
	}
	else
	{
		while (min->mov[1])
		{
			ft_rotate(stack_b);
			write(1, "rb\n", 3);
			min->mov[1]--;
		}
	}
}

static void	ft_continue_rotat_1(t_list **stack_a, t_list **stack_b, t_list *min)
{
	while (min->mov[0] && min->mov[1])
	{
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
		write(1, "rrr\n", 4);
		min->mov[0]++;
		min->mov[1]++;
	}
	while (min->mov[0])
	{
		ft_reverse_rotate(stack_a);
		write(1, "rra\n", 4);
		min->mov[0]++;
	}
	while (min->mov[1])
	{
		ft_reverse_rotate(stack_b);
		write(1, "rrb\n", 4);
		min->mov[1]++;
	}
}

static void	ft_rotat_stacks_pos(t_list **stack_a, t_list **stack_b, t_list *min)
{
	if (min->mov[0] > 0)
	{
		while (min->mov[0] && min->mov[1])
		{
			ft_rotate(stack_a);
			ft_rotate(stack_b);
			write(1, "rr\n", 3);
			min->mov[0]--;
			min->mov[1]--;
		}
		while (min->mov[0])
		{
			ft_rotate(stack_a);
			write(1, "ra\n", 3);
			min->mov[0]--;
		}
		while (min->mov[1])
		{
			ft_rotate(stack_b);
			write(1, "rb\n", 3);
			min->mov[1]--;
		}
	}
	else
		ft_continue_rotat_1(stack_a, stack_b, min);
}

void	ft_sorting(t_list **stack_a, t_list **stack_b)
{
	t_list	*min_node;

	marking_long_incr_list(stack_a, stack_b);
	while (*stack_b)
	{
		ft_moves(stack_a, stack_b);
		min_node = ft_minimum_mov(*stack_b);
		if (min_node->mov[0] * min_node->mov[1] > 0)
			ft_rotat_stacks_pos(stack_a, stack_b, min_node);
		else
		{
			ft_rotat_stacks_2(stack_a, min_node);
			ft_continu_rotat_stacks_2(stack_b, min_node);
		}
		ft_push(stack_b, stack_a);
		write(1, "pa\n", 3);
	}
	ft_moves(stack_a, stack_b);
	ft_rotate_min_stk_a(stack_a, ft_minimum(*stack_a));
}
