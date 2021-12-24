/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:30:04 by mortega-          #+#    #+#             */
/*   Updated: 2021/10/21 13:59:40 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					negative;
	unsigned long long	sum;

	negative = 0;
	sum = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			negative++;
	if (*str < '0' || *str > '9')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + *str++ - 48;
		if ((sum > 2147483648 && negative != 0)
			|| (sum > 2147483647 && negative == 0))
			return (0);
	}
	if (negative != 0)
		return (-sum);
	else
		return (sum);
}
