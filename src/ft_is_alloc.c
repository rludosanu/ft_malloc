/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 13:02:25 by rludosan          #+#    #+#             */
/*   Updated: 2017/03/28 15:33:42 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int			ft_search_alloc(t_block *head, void *ptr)
{
	char	*p;
	t_block	*tmp;

	tmp = head;
	while (tmp)
	{
		p = (char *)tmp + sizeof(t_block);
		if (p == ptr && tmp->free == 0)
			return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}

int			ft_is_alloc(void *ptr)
{
	if (g_base.tiny && ft_search_alloc(g_base.tiny, ptr) == TRUE)
		return (TRUE);
	if (g_base.small && ft_search_alloc(g_base.small, ptr) == TRUE)
		return (TRUE);
	if (g_base.large && ft_search_alloc(g_base.large, ptr) == TRUE)
		return (TRUE);
	return (FALSE);
}
