/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:01:15 by mortega-          #+#    #+#             */
/*   Updated: 2021/10/09 17:21:30 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	paint_line(int p1[2], int p2[2], int color)
{
	int	xy[2];
	int	steps[2];
	int	ij[2];

	steps[0] = ft_utils(p1, p2, 0);
	steps[1] = ft_utils(p1, p2, 2);
	xy[0] = p1[0];
	xy[1] = p1[1];
	ij[1] = 1;
	while (xy[0] != p2[0] || xy[1] != p2[1])
	{
		ij[0] = -1;
		while (++ij[0] < steps[0])
		{
			pxl(xy, (int [2][2]){{p1[0], p1[1]}, {p2[0], p2[1]}}, color, 0);
			if (++ij[1] == steps[1])
			{
				pxl(xy, (int [2][2]){{p1[0], p1[1]}, {p2[0], p2[1]}}, color, 0);
				ij[1] = 1;
			}
		}
		if (!steps[0])
			pxl(xy, (int [2][2]){{p1[0], p1[1]}, {p2[0], p2[1]}}, color, 2);
		pxl(xy, (int [2][2]){{p1[0], p1[1]}, {p2[0], p2[1]}}, color, 1);
	}
}

void	paint(int p1[2], int p2[2], int color, t_fdf *f)
{
	int	x;
	int	y;

	x = p1[0];
	y = p1[1];
	while (x < p2[0] || y < p2[1])
	{
		if (x == p2[0])
			my_mlx_put_pixel(&f->mlx.img,
				x + f->i,
				y++ + f->j, color);
		else if (y == p2[1])
			my_mlx_put_pixel(&f->mlx.img,
				x++ + f->i,
				y + f->j, color);
	}
}

void	points_base(int i, int j, t_matrix matrix, t_fdf *f)
{
	int	p0[2];
	int	p1[2];
	int	p2[2];

	p0[0] = (i - j + ft_max(f->cols, f->rows)) * f->cons;
	p0[1] = ((i + j) * f->cons) / 2 - (matrix[i][j][0] - f->max) * f->consh;
	if (i + 1 < f->rows)
	{
		p1[0] = (i + 1 - j + ft_max(f->cols, f->rows)) * f->cons;
		p1[1] = ((i + 1 + j) * f->cons) / 2
			- (matrix[i + 1][j][0] - f->max) * f->consh;
		paint_line(p0, p1, matrix[i][j][1]);
	}
	if (j + 1 < f->cols)
	{
		p2[0] = (i - (j + 1) + ft_max(f->cols, f->rows)) * f->cons;
		p2[1] = ((i + j + 1) * f->cons) / 2
			- (matrix[i][j + 1][0] - f->max) * f->consh;
		paint_line(p0, p2, matrix[i][j][1]);
	}
}

void	points(int i, int j, t_matrix matrix, t_fdf *f)
{
	int	p0[2];
	int	p1[2];
	int	p2[2];

	p0[0] = i * f->cons + ft_max(f->cols, f->rows) / 2;
	p0[1] = j * f->cons + ft_max(f->rows, f->cols) / 2;
	if (i + 1 < f->rows)
	{
		p1[0] = (i + 1) * f->cons + ft_max(f->rows, f->cols) / 2;
		p1[1] = j * f->cons + ft_max(f->cols, f->rows) / 2;
		paint(p0, p1, matrix[i][j][1], f);
	}
	if (j + 1 < f->cols)
	{
		p2[0] = i * f->cons + ft_max(f->cols, f->rows) / 2;
		p2[1] = (j + 1) * f->cons + ft_max(f->cols, f->rows) / 2;
		paint(p0, p2, matrix[i][j][1], f);
	}
}
