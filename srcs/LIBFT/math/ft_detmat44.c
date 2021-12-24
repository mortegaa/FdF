/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detmat44.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 22:01:28 by mortega-          #+#    #+#             */
/*   Updated: 2021/07/31 00:15:16 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_detmat44(t_mat44 const mat)
{
	float	result;
	int		i;

	result = 0;
	i = -1;
	while (++i < 4)
		result = result + ft_adjmat44(mat, i, 0, mat[i][0]);
	return (result);
}
