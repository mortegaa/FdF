/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:11:36 by mortega-          #+#    #+#             */
/*   Updated: 2021/09/09 17:03:11 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	equal(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != 0)
	{
		j = 0;
		while (base[j] != 0)
		{
			if (base[i] == base[i + j + 1])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	rec(int nbr, int cont, char *base)
{
	if (nbr >= cont)
	{
		rec(nbr / cont, cont, base);
		write(1, &base[nbr % cont], 1);
	}
	else
		write(1, &base[nbr], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	cont;
	int	flag;

	flag = 0;
	cont = 0;
	while (base[cont] != '\0')
	{
		if (base[cont] == '-' || base[cont] == '+')
			flag++;
		cont++;
	}
	if (cont > 1 && flag == 0 && equal(base) == 0)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = nbr * -1;
		}
		rec(nbr, cont, base);
	}
}
