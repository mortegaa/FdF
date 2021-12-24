/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detmat33.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:59:34 by mortega-          #+#    #+#             */
/*   Updated: 2021/07/31 00:15:05 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_detmat33(t_mat33 mat)
{
	return ((mat[0][0] * mat[1][1] * mat[2][2]
				+ mat[2][0] * mat[1][2] * mat[0][1]
				+ mat[2][1] * mat[1][0] * mat[0][2])
			- (mat[0][2] * mat[1][1] * mat[2][0]
				+ mat[2][2] * mat[1][0] * mat[0][1]
				+ mat[2][1] * mat[1][2] * mat[0][0]));
}

/*
**int main(void)
**{
**	t_mat33 mat = {{2, 5, 7}, {0, 6, 1}, {8, 7, 1}};
**
**	printf("Esta es la matriz: \n\t");
**	for (int i = 0; i < 3; i++)
**	{
**		for (int j = 0; j < 3; j++)
**			printf(" %.0f ", mat[i][j]);
**		printf("\n\t");
**	}
**	printf("Y este su determinante: |%.0f|\n", ft_detmat33(mat));
**	return 0;
**}
*/
