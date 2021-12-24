/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:46:55 by mortega-          #+#    #+#             */
/*   Updated: 2021/09/09 17:32:20 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cpy;

	cpy = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!cpy)
		return (0);
	i = -1;
	while (s1[++i] != '\0')
		cpy[i] = s1[i];
	cpy[i] = '\0';
	return (cpy);
}
