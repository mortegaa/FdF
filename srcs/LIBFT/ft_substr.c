/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:40:19 by mortega-          #+#    #+#             */
/*   Updated: 2021/09/09 17:41:41 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if (!s)
		return (0);
	if (start > ft_strlen(s) || s[0] == '\0')
		return (ft_strdup(""));
	substring = (char *)malloc(sizeof(char) * len + 1);
	if (!substring)
		return (0);
	i = -1;
	while (++i < len && s[start + i] != 0)
		substring[i] = s[start + i];
	substring[i] = '\0';
	return (substring);
}
