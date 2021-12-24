/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:16:51 by mortega-          #+#    #+#             */
/*   Updated: 2020/02/25 10:17:29 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	end;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0')
		return ((char *)s1);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	if (*s1 == '\0')
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (end && ft_strchr(set, s1[end]))
		end--;
	return (ft_substr(s1, 0, end + 1));
}
