/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:28:11 by araqioui          #+#    #+#             */
/*   Updated: 2022/12/25 17:33:04 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_atoi(const char *str, t_list **top)
{
	long long	res;
	int			sign;

	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == 43 || *str == 45)
	{
		if (*str++ == 45)
			sign *= -1;
	}
	res = 0;
	while (*str && *str >= 48 && *str <= 57)
	{
		res = res * 10 + *str - 48;
		str++;
	}
	res *= sign;
	if (*str == 45 || *str == 43 || 2147483647 < res || res <= -2147483649)
	{
		write(1, "Error\n", 6);
		ft_lstclear(top);
		exit(EXIT_FAILURE);
	}
	return (res);
}
