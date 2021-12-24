/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:08:03 by mortega-          #+#    #+#             */
/*   Updated: 2021/09/09 17:53:02 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newel;

	newel = (t_list *)malloc(sizeof(*newel));
	if (!newel)
		return (0);
	newel->content = content;
	newel->next = 0;
	return (newel);
}
