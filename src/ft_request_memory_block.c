/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_request_memory_block.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:11:50 by rludosan          #+#    #+#             */
/*   Updated: 2017/03/28 15:53:57 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block				*ft_request_memory_block(size_t size, int count)
{
	t_block			*memory;
	int				pagesz;
	int				pagenb;

	pagesz = getpagesize();
	pagenb = ((sizeof(t_block) + size) * count) / pagesz + 1;
	memory = mmap(NULL, pagenb * pagesz, MMAP_PROT, MMAP_MAP, -1, 0);
	if (memory == MAP_FAILED)
		return (NULL);
	memory = (t_block *)memory;
	memory->bid = 0;
	memory->free = 1;
	memory->size = pagenb * pagesz - sizeof(t_block);
	memory->next = NULL;
	return (memory);
}

t_block				*ft_request_memory(size_t size)
{
	t_block			*tmp;

	if (size <= TINY)
	{
		if ((tmp = ft_request_memory_block(TINY, (!g_base.tiny) ? 100 : 1)))
			ft_add_memory_block(&(g_base.tiny), tmp);
	}
	else if (size <= SMALL)
	{
		if ((tmp = ft_request_memory_block(SMALL, (!g_base.small) ? 100 : 1)))
			ft_add_memory_block(&(g_base.small), tmp);
	}
	else
	{
		if ((tmp = ft_request_memory_block(size, 1)))
			ft_add_memory_block(&(g_base.large), tmp);
	}
	return (tmp);
}
