/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 14:09:53 by mortega-          #+#    #+#             */
/*   Updated: 2021/07/31 00:16:44 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_normalize(t_vector *vector)
{
	float	module;

	module = 1 / sqrt(vector->x * vector->x
			+ vector->y * vector->y
			+ vector->z * vector->z);
	vector->x = vector->x * module;
	vector->y = vector->y * module;
	vector->z = vector->z * module;
}
