/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:56:06 by araqioui          #+#    #+#             */
/*   Updated: 2022/12/29 16:54:30 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_swap(t_list **top)
{
	int		tmp;
	t_list	*tempo;

	if (!(*top) || !(*top)->next)
		return ;
	tempo = (*top)->next;
	tmp = (*top)->data;
	(*top)->data = tempo->data;
	tempo->data = tmp;
}
