/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 21:40:20 by mortega-          #+#    #+#             */
/*   Updated: 2021/09/09 17:38:04 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				i;
	char			*smapi;

	smapi = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!smapi)
		return (0);
	i = -1;
	while (s[++i] != '\0')
		smapi[i] = f(i, s[i]);
	smapi[i] = '\0';
	return (smapi);
}
