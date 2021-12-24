/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:49:53 by mortega-          #+#    #+#             */
/*   Updated: 2021/10/09 16:38:38 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	ft_x(int *x, int p1[2], int p2[2], int steps)
{
	int	dx;
	int	dy;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	if (*x == p2[0])
		return (*x);
	if (ft_abs(dx) <= ft_abs(dy) && steps == 1 && dx > 0)
		return ((*x = *x + 1));
	else if (ft_abs(dx) <= ft_abs(dy) && steps == 1 && dx < 0)
		return ((*x = *x - 1));
	else if (ft_abs(dx) >= ft_abs(dy) && steps == 2 && dx > 0)
		return ((*x = *x + 1));
	else if (ft_abs(dx) >= ft_abs(dy) && steps == 2 && dx < 0)
		return ((*x = *x - 1));
	else if (ft_abs(dx) < ft_abs(dy) && !steps)
		return (*x);
	else if (ft_abs(dx) > ft_abs(dy) && !steps && dx > 0)
		return ((*x = *x + 1));
	else if (ft_abs(dx) > ft_abs(dy) && !steps && dx < 0)
		return ((*x = *x - 1));
	else
		return (*x);
}

int	ft_y(int *y, int p1[2], int p2[2], int steps)
{
	int	dx;
	int	dy;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	if (*y == p2[1])
		return (*y);
	if (ft_abs(dy) <= ft_abs(dx) && steps == 1 && dy > 0)
		return ((*y = *y + 1));
	else if (ft_abs(dy) <= ft_abs(dx) && steps == 1 && dy < 0)
		return ((*y = *y - 1));
	else if (ft_abs(dy) >= ft_abs(dx) && steps == 2 && dy > 0)
		return ((*y = *y + 1));
	else if (ft_abs(dy) >= ft_abs(dx) && steps == 2 && dy < 0)
		return ((*y = *y - 1));
	else if (ft_abs(dy) < ft_abs(dx) && !steps)
		return (*y);
	else if (ft_abs(dy) > ft_abs(dx) && !steps && dy > 0)
		return ((*y = *y + 1));
	else if (ft_abs(dy) > ft_abs(dx) && !steps && dy < 0)
		return ((*y = *y - 1));
	else
		return (*y);
}

int	ft_utils(int p1[2], int p2[2], char c)
{
	int	dx;
	int	dy;
	int	res;
	int	result;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	if (ft_min(ft_abs(dx), ft_abs(dy)) == 0)
		return (0);
	if (c == 0)
	{
		result = ft_max(ft_abs(dx), ft_abs(dy))
			/ ft_min(ft_abs(dx), ft_abs(dy));
		return (result);
	}
	res = ft_max(ft_abs(dx), ft_abs(dy)) % ft_min(ft_abs(dx), ft_abs(dy));
	if (res)
	{
		result = ft_max(ft_abs(dx), ft_abs(dy)) / res;
		return (result);
	}
	return (0);
}

void	pxl(int xy[2], int p[2][2], int color, char c)
{
	t_fdf	*f;

	f = get_f();
	my_mlx_put_pixel(&f->mlx.img,
		ft_x(&xy[0], p[0], p[1], c) + f->cx,
		ft_y(&xy[1], p[0], p[1], c) + f->cy, color);
}
