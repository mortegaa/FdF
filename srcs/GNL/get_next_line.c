/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 20:21:46 by mortega-          #+#    #+#             */
/*   Updated: 2021/10/16 19:28:56 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	filline(char **line, char **stat, int count, char **buffer)
{
	char	*tmp;
	ssize_t	i;

	if (*buffer)
		free(*buffer);
	if (count == 0)
	{
		*line = ft_strdup(*stat);
		free(*stat);
		*stat = NULL;
		return (0);
	}
	tmp = *stat;
	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	*line = ft_substr(*stat, 0, i);
	*stat = ft_substr(*stat, i + 1, ft_strlen(*stat) - i);
	free(tmp);
	if (!*line || !*stat)
		return (-1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		count;
	char		*buffer;
	char		*tmp;
	static char	*stat[4096];

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buffer, 0) == -1
		|| !buffer)
		return (-1);
	if (!stat[fd])
		stat[fd] = ft_strdup("");
	count = 1;
	if (ft_strchr(stat[fd], '\n'))
		return (filline(&*line, &stat[fd], count, &buffer));
	count = read(fd, buffer, BUFFER_SIZE);
	while (count > 0)
	{
		buffer[count] = '\0';
		tmp = stat[fd];
		stat[fd] = ft_strjoin(stat[fd], buffer);
		free(tmp);
		if (ft_strchr(stat[fd], '\n'))
			break ;
	}
	return (filline(&*line, &stat[fd], count, &buffer));
}
