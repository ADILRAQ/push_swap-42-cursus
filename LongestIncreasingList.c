/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LongestIncreasingList.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:06:22 by araqioui          #+#    #+#             */
/*   Updated: 2022/12/29 20:20:44 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	copy_stack_a(t_list *lst, t_list **temp)
{
	*temp = NULL;
	while (lst)
	{
		ft_lstadd_back(temp, ft_lstnew(lst->data));
		lst = lst->next;
	}
}

static void	ft_minimum_lis(t_list *lst, t_list **temp)
{
	t_list	*min;

	copy_stack_a(lst, temp);
	min = ft_minimum(*temp);
	if (min->indice > ft_lstsize(*temp) / 2)
		while ((*temp) != min)
			ft_rotate(temp);
	else
		while ((*temp) != min)
			ft_reverse_rotate(temp);
}

static int	longest_increasing_list(t_list *lst, t_list **temp)
{
	t_list	*trav;
	t_list	*ptr;
	int		max_len;

	ft_minimum_lis(lst, temp);
	max_len = 1;
	ptr = (*temp)->next;
	while (ptr)
	{
		trav = (*temp);
		while (trav != ptr)
		{
			if (ptr->data > trav->data && ptr->length < trav->length + 1)
			{
				ptr->length = trav->length + 1;
				ptr->lis = trav;
				if (max_len < ptr->length)
					max_len = ptr->length;
			}
			trav = trav->next;
		}
		ptr = ptr->next;
	}
	return (max_len);
}

static void	ft_pushing_to_stack_b(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(*stack_a);
	while (i < size)
	{
		if ((*stack_a)->length == -1)
		{
			ft_rotate(stack_a);
			ft_update_indices(stack_a);
			write(1, "ra\n", 3);
		}
		else
		{
			ft_push(stack_a, stack_b);
			ft_update_indices(stack_a);
			ft_update_indices(stack_b);
			write(1, "pb\n", 3);
		}
		i++;
	}
}

void	marking_long_incr_list(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*ptr;
	t_list	*ptr1;
	int		max_len;

	max_len = longest_increasing_list(*stack_a, &temp);
	ptr1 = temp;
	while (temp->next && temp->length != max_len)
		temp = temp->next;
	while (temp)
	{
		ptr = (*stack_a);
		while (ptr)
		{
			if (ptr->data == temp->data)
			{
				ptr->length = -1;
				break ;
			}
			ptr = ptr->next;
		}
		temp = temp->lis;
	}
	ft_lstclear(&ptr1);
	ft_pushing_to_stack_b(stack_a, stack_b);
}
