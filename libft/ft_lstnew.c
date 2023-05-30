/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:28:02 by araqioui          #+#    #+#             */
/*   Updated: 2022/12/25 18:22:41 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_list	*ft_lstnew(int content)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (0);
	head->prev = NULL;
	head->data = content;
	head->length = 1;
	head->mov[0] = 0;
	head->mov[1] = 0;
	head->mov[2] = 0;
	head->lis = NULL;
	head->next = NULL;
	return (head);
}
