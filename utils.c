/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 12:55:33 by mortega-          #+#    #+#             */
/*   Updated: 2021/10/09 17:09:43 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	exit_mess(char *str)
{
	write(1, str, ft_strlen(str));
	exit(EXIT_SUCCESS);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	ft_abs(int	num)
{
	if (num < 0)
		num = -num;
	return (num);
}

int	max_altitude(int ***matrix, t_fdf *f)
{
	int	max;
	int	i;
	int	j;

	i = 0;
	j = 0;
	max = 0;
	while (i < f->rows)
	{
		j = -1;
		while (++j < f->cols)
			if (max < matrix[i][j][0])
				max = matrix[i][j][0];
		i++;
	}
	return (max);
}
