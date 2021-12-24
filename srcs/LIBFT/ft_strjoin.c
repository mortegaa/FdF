/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:53:57 by mortega-          #+#    #+#             */
/*   Updated: 2021/09/09 17:33:19 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		s2len;
	int		i;
	int		j;
	char	*sjoin;

	if (!s1 || !s2)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	sjoin = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!sjoin)
		return (0);
	i = -1;
	while (s1[++i] != '\0')
		sjoin[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		sjoin[i + j] = s2[j];
	sjoin[i + j] = '\0';
	return (sjoin);
}
