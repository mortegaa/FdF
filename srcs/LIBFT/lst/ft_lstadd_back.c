/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:48:01 by mortega-          #+#    #+#             */
/*   Updated: 2021/07/31 00:26:49 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (new)
	{
		aux = *lst;
		if (!*lst)
		{
			*lst = new;
			new->next = 0;
		}
		else
		{
			aux = ft_lstlast(*lst);
			aux->next = new;
		}
	}
}
