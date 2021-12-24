/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multmat44.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:00:36 by mortega-          #+#    #+#             */
/*   Updated: 2021/09/09 18:21:53 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_multimat44(t_mat44 mat, t_mat44 const a, t_mat44 const b)
{
	char	i;
	char	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			mat[(int)i][(int)j] = a[(int)i][0] * b[0][(int)j]
				+ a[(int)i][1] * b[1][(int)j]
				+ a[(int)i][2] * b[2][(int)j]
				+ a[(int)i][3] * b[3][(int)j];
	}
}
