/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 10:59:23 by mortega-          #+#    #+#             */
/*   Updated: 2021/10/09 17:22:14 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

int	create_matrix(char *file, t_matrix matrix)
{
	int		i;
	int		fd;
	int		x;
	char	*line;

	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	x = ft_split_count(line, ' ');
	i = 0;
	matrix[i++] = create_line(line, x);
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		matrix[i] = create_line(line, x);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	return (x);
}

int	**create_line(char *line, int len)
{
	int			i;
	int			**nline;
	char		**params;
	char		**data;

	if (ft_split_count(line, ' ') < len)
		exit_mess("Bad Map\n");
	nline = (int **)malloc(sizeof(int *) * len);
	params = ft_split(line, ' ');
	i = 0;
	while (++i <= len)
	{
		data = ft_split(params[i - 1], ',');
		nline[len - i] = (int *)malloc(sizeof(int) * 2);
		nline[len - i][0] = ft_atoi(data[0]);
		if (!data[1])
			nline[len - i][1] = 0xffffff;
		else
			nline[len - i][1] = ft_hextoi(data[1]);
		ft_split_free(data);
	}
	ft_split_free(params);
	return (nline);
}

int	***read_file(char *file, t_fdf *f)
{
	int	len;
	int	x;
	int	y;
	int	***matrix;

	len = ft_strlen(file);
	if (!(file[len - 1] == 'f' && file[len - 2] == 'd'
			&& file[len - 3] == 'f' && file[len - 4] == '.'))
		exit_mess("It is not a valid file\n");
	x = ft_count_lines(file);
	if (x < 0)
		exit_mess("Inaccesible archive\n");
	f->rows = x;
	matrix = (int ***)malloc(sizeof(int **) * x);
	y = create_matrix(file, matrix);
	f->cols = y;
	return (matrix);
}
