/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:18:16 by mortega-          #+#    #+#             */
/*   Updated: 2021/09/09 17:40:33 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if ((!haystack && !needle) || (haystack == needle)
		|| ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = -1;
	while (++i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] == needle[j] && len > i + j
				&& haystack[i + j])
				j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
	}
	return (0);
}
