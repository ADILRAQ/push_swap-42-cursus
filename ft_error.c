/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:51:53 by araqioui          #+#    #+#             */
/*   Updated: 2022/12/29 16:01:23 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_check_digit(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		if (!str[i][0])
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		while (str[i][j])
		{
			if (!((str[i][j] >= 48 && str[i][j] <= 57) || str[i][j] == ' '
				|| str[i][j] == '-' || str[i][j] == '+'))
			{
				write(1, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static void	ft_check_double(t_list **lst)
{
	t_list	*handler;
	t_list	*trav;

	handler = (*lst);
	while (handler)
	{
		trav = handler->next;
		while (trav)
		{
			if (handler->data == trav->data)
			{
				write(1, "Error\n", 6);
				ft_lstclear(lst);
				exit(EXIT_FAILURE);
			}
			trav = trav->next;
		}
		handler = handler->next;
	}
}

t_list	*ft_split_digit(char **str)
{
	t_list	*top;
	int		j;

	top = NULL;
	while (*str)
	{
		j = 0;
		while (*(*str + j))
		{
			if (*(*str + j) != ' ')
				ft_lstadd_back(&top, ft_lstnew(ft_atoi((*str + j), &top)));
			while (*(*str + j) && *(*str + j) != ' ')
				j++;
			while (*(*str + j) && *(*str + j) == ' ')
				j++;
		}
		str++;
	}
	ft_check_double(&top);
	return (top);
}
