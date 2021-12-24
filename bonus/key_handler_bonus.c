/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:02:29 by mortega-          #+#    #+#             */
/*   Updated: 2021/10/09 17:22:00 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	centered(t_fdf *f)
{
	int			i;
	int			j;
	t_matrix	matrix;

	matrix = *get_matrix();
	i = f->rows / 2;
	j = f->cols / 2;
	f->cx = (f->x / 2)
		- (i - j + ft_max(f->cols, f->rows) * f->cons);
	f->cy = ((f->y / 2) - (((i + j) * f->cons) / 2
				- (matrix[i][j][0] - f->max) * f->consh));
	f->i = 0;
	f->j = 0;
	f->zoomx = 0;
	f->zoomy = 0;
}

int	what_key(int key, t_fdf *f)
{
	if (key == 8)
		centered(f);
	else if (key == 0)
		f->i += f->vel;
	else if (key == 1)
		f->j -= f->vel;
	else if (key == 2)
		f->i -= f->vel;
	else if (key == 13)
		f->j += f->vel;
	else if (key == 15)
		set_const(f);
	else if (key == 4)
		f->h = !f->h;
	else if (key == 46)
		f->vel += 5;
	else if (key == 45)
		f->vel -= 5;
	else if (key == 123)
		f->base = 0;
	else if (key == 124)
		f->base = 1;
	else
		return (-1);
	return (0);
}

int	keypressed(int key, t_fdf *f)
{
	t_matrix	matrix;

	matrix = *get_matrix();
	if (key == 53)
		exit_mess("Closed with ESC\n");
	else if (what_key(key, f))
		return (-1);
	mlx_clear_window(f->mlx.ptr, f->mlx.win);
	clear_image(&f->mlx.img, f->x, f->y);
	construct_map(matrix, f);
	return (0);
}
