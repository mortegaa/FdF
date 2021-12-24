/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:02:29 by mortega-          #+#    #+#             */
/*   Updated: 2021/10/21 13:36:35 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

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

int	keypressed(int key, t_fdf *f)
{
	t_matrix	matrix;

	matrix = *get_matrix();
	if (key == 53)
		exit_mess("Closed with ESC\n");
	(void)f;
	return (0);
}
