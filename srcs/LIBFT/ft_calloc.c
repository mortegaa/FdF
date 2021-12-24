/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:56:07 by mortega-          #+#    #+#             */
/*   Updated: 2021/09/09 16:48:36 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*aux;

	aux = malloc(count * size);
	if (!aux)
		return (0);
	i = -1;
	while (++i < size * count)
		((unsigned char *)aux)[i] = 0;
	return (aux);
}
