/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:18:42 by araqioui          #+#    #+#             */
/*   Updated: 2022/12/29 10:20:57 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_rotate_min_stk_a(t_list **stack_a, t_list *min)
{
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
		while (min->mov[0])
		{
			ft_reverse_rotate(stack_a);
			write(1, "rra\n", 4);
			min->mov[0]++;
		}
	}
}
