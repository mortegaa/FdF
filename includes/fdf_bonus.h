/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 12:57:33 by mortega-          #+#    #+#             */
/*   Updated: 2021/10/21 14:01:15 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <fcntl.h>
# include "../srcs/LIBFT/libft.h"
# include "../srcs/GNL/get_next_line.h"
# include "../srcs/minilibx/mlx.h"

# define CONST 15

typedef int	***t_matrix;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		sizel;
	int		endian;
}	t_image;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	t_image	img;
}				t_mlx;

typedef struct s_fdf
{
	int		cons;
	int		consh;
	int		zoomx;
	int		zoomy;
	int		rows;
	int		cols;
	int		max;
	int		x;
	int		y;
	int		i;
	int		j;
	char	h;
	int		cx;
	int		cy;
	int		vel;
	int		base;
	t_mlx	mlx;
}				t_fdf;

/*
**	READ & CREATE
*/
int			***read_file(char *file, t_fdf *f);
int			**create_line(char *line, int len);
int			create_matrix(char *file, int ***matrix);
void		construct_map(t_matrix matrix, t_fdf *f);

/*
**	WINDOWS FUNCTIONS
*/
void		create_window(t_fdf *f, t_matrix matrix);
void		clear_image(t_image *img, int x, int y);
int			ft_close(t_mlx *mlx);
int			mouse_hook(int button, int x, int y, t_fdf *f);
int			keypressed(int key, t_fdf *f);

/*
**	DRAW FUNCTIONS
*/
void		points(int i, int j, t_matrix matrix, t_fdf *f);
void		points_base(int i, int j, t_matrix matrix, t_fdf *f);
void		paint_line(int p1[2], int p2[2], int color);
void		paint(int p1[2], int p2[2], int color, t_fdf *f);
void		my_mlx_put_pixel(t_image *img, int x, int y, int color);
void		pxl(int xy[2], int p[2][2], int color, char c);

/*
**	UTILS
*/
void		exit_mess(char *str);
int			max_altitude(t_matrix matrix, t_fdf *f);
int			ft_max(int a, int b);
int			ft_min(int a, int b);
int			ft_abs(int num);
int			ft_utils(int p1[2], int p[2], char c);

t_matrix	*get_matrix(void);
void		set_const(t_fdf *f);
t_fdf		*get_f(void);
#endif
