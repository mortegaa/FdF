/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 13:18:59 by mortega-          #+#    #+#             */
/*   Updated: 2021/10/09 17:21:48 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	my_mlx_put_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;
	t_fdf	*f;

	f = get_f();
	if (y < 0 || y >= f->y || x < 0 || x >= f->x)
		return ;
	dst = img->addr + (y * img->sizel + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	clear_image(t_image *img, int x, int y)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			dst = img->addr + (j * img->sizel + i * (img->bpp / 8));
			*(unsigned int *)dst = 0x00;
			j++;
		}
		i++;
	}
}

void	create_images(int x, int y, t_fdf *f)
{
	f->mlx.img.img = (int *)mlx_new_image(f->mlx.ptr, x, y);
	f->mlx.img.addr = mlx_get_data_addr(f->mlx.img.img, &f->mlx.img.bpp,
			&f->mlx.img.sizel, &f->mlx.img.endian);
}

void	set_const(t_fdf *f)
{
	int			i;
	int			j;
	t_matrix	matrix;

	matrix = *get_matrix();
	i = f->rows / 2;
	j = f->cols / 2;
	f->x = 2 * ft_max(f->rows, f->cols) * f->cons;
	if (f->x > 1000)
		f->x = 1000;
	f->y = ((f->cols + f->rows) / 2 + f->max) * f->cons;
	if (f->y > 800)
		f->y = 800;
	f->cons = 15 * (float)(1 - (float)((float)(f->cols + f->rows) / 400));
	if (f->cons < 2)
		f->cons = 3;
	f->consh = (int)((float)f->cons
			* (float)(1 - (float)((float)f->max / 600)));
	f->cx = (f->x / 2) - (i - j + ft_max(f->cols, f->rows) * f->cons);
	f->cy = ((f->y / 2) - (((i + j) * f->cons) / 2
				- (matrix[i][j][0] - f->max) * f->consh));
}

void	create_window(t_fdf	*f, t_matrix matrix)
{
	f->mlx.ptr = mlx_init();
	f->cons = CONST;
	f->i = 0;
	f->j = 0;
	f->vel = 5;
	f->base = 1;
	f->h = 0;
	f->zoomx = 0;
	f->zoomy = 0;
	set_const(f);
	f->mlx.win = mlx_new_window(f->mlx.ptr, f->x, f->y, "FDF");
	create_images(f->x, f->y, f);
	construct_map(matrix, f);
	write(1, "*****Terminado*****\n", 21);
	mlx_hook(f->mlx.win, 17, 1L << 17, ft_close, &f->mlx);
	mlx_hook(f->mlx.win, 2, 1L << 0, keypressed, f);
	mlx_hook(f->mlx.win, 4, 0L << 0, mouse_hook, f);
	mlx_loop(f->mlx.ptr);
}
