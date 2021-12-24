/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 08:14:56 by mortega-          #+#    #+#             */
/*   Updated: 2021/10/16 19:33:22 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*sjoin;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	sjoin = (char *)malloc(sizeof(char) * (len + 1));
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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		slen;
	char		*substring;
	size_t		i;

	slen = ft_strlen(s);
	if (!s)
		return (0);
	if (start > slen)
		return (ft_strdup(""));
	substring = (char *)malloc(sizeof(char) * len + 1);
	if (!substring)
		return (0);
	i = -1;
	while (++i < len && s[start + i] != 0 && slen >= len)
		substring[i] = s[start + i];
	substring[i] = '\0';
	return (substring);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}
