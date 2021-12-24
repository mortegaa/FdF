/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstwhich.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:09:28 by mortega-          #+#    #+#             */
/*   Updated: 2021/09/09 17:53:37 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstwhich(t_list *lst, int num)
{
	int	i;

	i = 0;
	while (i < num && lst->next)
		lst = lst->next;
}
