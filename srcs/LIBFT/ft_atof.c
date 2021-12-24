/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 17:24:08 by mortega-          #+#    #+#             */
/*   Updated: 2021/09/09 18:26:22 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

float	ft_atof(const char *str)
{
	int		i;
	float	numdec[2];
	char	negative;

	i = 0;
	negative = 0;
	numdec[0] = 0;
	numdec[1] = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' && str++)
		negative++;
	while (*str >= '0' && *str <= '9')
		numdec[0] = numdec[0] * 10 + *str++ - 48;
	if (*str == '.')
		str++;
	while (str[i] >= '0' && str[i] <= '9')
		numdec[1] = numdec[1] * 10 + str[i++] - 48;
	while (i-- > 0)
		numdec[1] = numdec[1] / 10;
	if (numdec[0] == 0 && negative > 0)
		numdec[1] = -numdec[1];
	else if (negative > 0)
		numdec[0] = -numdec[0];
	return (numdec[0] + numdec[1]);
}
