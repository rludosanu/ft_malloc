/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:06:31 by rludosan          #+#    #+#             */
/*   Updated: 2017/03/28 13:41:58 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void				*malloc(size_t size)
{
	t_block			*tmp;

	ft_mutex(1, &g_mutex);
	if (!size)
	{
		ft_mutex(0, &g_mutex);
		return (NULL);
	}
	if (!(tmp = ft_find_free_block(size)))
	{
		if (!(tmp = ft_merge_memory_block(tmp, size)))
		{
			if (!(tmp = ft_request_memory(size)))
			{
				ft_mutex(0, &g_mutex);
				return (NULL);
			}
		}
	}
	ft_split_memory_block(tmp, size);
	tmp->free = 0;
	ft_mutex(0, &g_mutex);
	return ((void *)(tmp + 1));
}
