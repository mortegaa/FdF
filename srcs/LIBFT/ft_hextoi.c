/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 11:42:57 by mortega-          #+#    #+#             */
/*   Updated: 2021/10/21 14:00:25 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hextoi(const char *s)
{
	int			num;
	int			i;
	static char	hex[16] = "0123456789abcdef";

	num = 0;
	i = 2;
	while (s[i] && ft_strchr(hex, s[i]))
	{
		num = num * 16 + ft_strchrnum(hex, s[i]);
		i++;
	}
	return (num);
}
