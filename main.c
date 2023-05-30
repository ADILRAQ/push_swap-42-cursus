/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:40:18 by araqioui          #+#    #+#             */
/*   Updated: 2022/12/29 18:42:49 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac >= 2 && ft_check_digit(av))
	{
		stack_b = NULL;
		stack_a = ft_split_digit(av + 1);
		if (!ft_check_sort(stack_a))
		{
			if (ft_lstsize(stack_a) == 2)
				ft_case_2_nb(&stack_a);
			else if (ft_lstsize(stack_a) == 3)
				ft_case_3_nb(&stack_a);
			else if (ft_lstsize(stack_a) == 4)
				ft_case_4_nb(&stack_a, &stack_b);
			else if (ft_lstsize(stack_a) == 5)
				ft_case_5_nb(&stack_a, &stack_b);
			else
				ft_sorting(&stack_a, &stack_b);
		}
		ft_lstclear(&stack_a);
	}
	return (0);
}
