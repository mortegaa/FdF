/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:04:38 by mortega-          #+#    #+#             */
/*   Updated: 2021/10/09 17:22:07 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

int	ft_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit_mess("All Great\n");
	return (1);
}

t_matrix	*get_matrix(void)
{
	static t_matrix	matrix;

	return (&matrix);
}

t_fdf	*get_f(void)
{
	static t_fdf	f;

	return (&f);
}

void	zoom(int x, int y, t_fdf *f, char c)
{
	int	p[2];

	p[0] = x / f->cons;
	p[1] = y / f->cons;
	if (!c)
		f->cons--;
	else
		f->cons++;
	if (f->consh)
	{
		f->consh = (int)((float)f->cons
				* (float)(1 - (float)((float)f->max / 600)));
		if (f->consh < 1)
			f->consh = 1;
	}
	f->zoomx += (x - (p[0] * f->cons));
	f->zoomy += (y - (p[1] * f->cons));
}

int	mouse_hook(int button, int x, int y, t_fdf *f)
{
	t_matrix	*matrix;

	matrix = get_matrix();
	if (button == 04 && f->h == 1)
		f->consh--;
	else if (button == 04 && f->h == 0 && f->cons > 1)
		zoom(x, y, f, 0);
	else if (button == 05 && f->h == 1)
		f->consh++;
	else if (button == 05 && f->h == 0)
		zoom(x, y, f, 1);
	else
		return (-1);
	mlx_clear_window(f->mlx.ptr, f->mlx.win);
	clear_image(&f->mlx.img, f->x, f->y);
	construct_map(*matrix, f);
	return (0);
}
