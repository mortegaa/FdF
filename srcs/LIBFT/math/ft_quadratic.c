/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quadratic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 13:39:24 by mortega-          #+#    #+#             */
/*   Updated: 2021/09/09 18:23:24 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	ft_quadratic(float const a, float const b, float const c, float *x[2])
{
	float	q;
	float	discr;

	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		*x[0] = -0.5 * b / a;
		*x[1] = *x[0];
	}
	else
	{
		if (b < 0)
			q = -0.5 * (b + sqrt(discr));
		else
			q = -0.5 * (b - sqrt(discr));
		*x[0] = q / a;
		*x[1] = c / q;
	}
	return (1);
}
