/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 18:28:23 by mortega-          #+#    #+#             */
/*   Updated: 2021/09/09 16:50:43 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isnumber(char *num)
{
	int	points;

	points = 0;
	if (!(*num >= 48 && *num <= 57) && !(*num == 45) && !(*num == 46))
		return (0);
	while ((*num >= 48 && *num <= 57) || *num == 45 || *num == 46)
	{
		if (points == 1 && *num == 46)
			return (0);
		if (*num == 46)
			points++;
		else if (*num == 45 && !(*(num + 1) >= 48 && *(num + 1) <= 57))
			return (0);
		else if (*num == 46 && !(*(num - 1) >= 48 && *(num - 1) <= 57)
			&& !(*(num + 1) >= 48 && *(num + 1) <= 57))
			return (0);
		num++;
	}
	return (1);
}
