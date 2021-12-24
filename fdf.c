/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 13:02:14 by mortega-          #+#    #+#             */
/*   Updated: 2021/10/09 16:59:09 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	construct_map(t_matrix matrix, t_fdf *f)
{
	int	i;
	int	j;

	i = 0;
	while (i < f->rows)
	{
		j = 0;
		while (j < f->cols)
		{
			points_base(i, j, matrix, f);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, f->mlx.img.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_matrix	*matrix;
	t_fdf		*fdf;

	if (argc < 1)
		return (-1);
	else if (argc != 2)
		exit_mess("Incorrect number of parameters\n");
	matrix = get_matrix();
	fdf = get_f();
	*matrix = read_file(argv[1], fdf);
	fdf->max = max_altitude(*matrix, fdf);
	create_window(fdf, *matrix);
	return (0);
}
