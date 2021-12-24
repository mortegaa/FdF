/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:00:00 by mortega-          #+#    #+#             */
/*   Updated: 2021/09/09 17:29:20 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**spl;
	int		i;

	count = !(--s);
	i = 0;
	while (*(++s) != '\0' && (++i))
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
	spl = (char **)malloc(sizeof(char *) * (count + 1));
	i = !(s -= i + 1);
	while (*(++s))
	{
		count = 1;
		if (*s != c)
		{
			while (*(s + count) && *(s + count) != c)
				count++;
			spl[i++] = ft_substr(s, 0, count);
			s = s + count - 1;
		}
	}
	spl[i] = NULL;
	return (spl);
}
