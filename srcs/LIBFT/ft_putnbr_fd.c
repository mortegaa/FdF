/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 22:40:13 by mortega-          #+#    #+#             */
/*   Updated: 2021/09/09 17:03:53 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive(long n, int fd)
{
	long	nb;

	nb = 0;
	if (n > 9)
	{
		recursive(n / 10, fd);
		nb = n % 10 + 48;
		write(fd, &nb, 1);
	}
	else
	{
		nb = n + 48;
		write(fd, &nb, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * -1;
		recursive(nb, fd);
	}
	else
		recursive(nb, fd);
}
