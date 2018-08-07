/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:12:41 by rludosan          #+#    #+#             */
/*   Updated: 2017/03/28 15:45:17 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int				ft_check_block_type(t_block *head, t_block *block)
{
	t_block		*tmp;

	if (!head || !block)
		return (FALSE);
	tmp = head;
	while (tmp)
	{
		if (tmp == block)
			return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}

int				ft_get_block_type(t_block *block)
{
	if (g_base.tiny && ft_check_block_type(g_base.tiny, block) == TRUE)
		return (TTINY);
	else if (g_base.small && ft_check_block_type(g_base.small, block) == TRUE)
		return (TSMALL);
	else if (g_base.large && ft_check_block_type(g_base.large, block) == TRUE)
		return (TLARGE);
	else
		return (-1);
}

void			ft_free_block_large(t_block *block)
{
	t_block		*tmp;
	size_t		ps;

	ps = getpagesize();
	if (block && block->next && block->bid == block->next->bid)
	{
		block->size = block->size + sizeof(t_block) + block->next->size;
		block->next = block->next->next;
	}
	if (block == g_base.large)
	{
		munmap(block, (sizeof(t_block) + block->size) / ps);
		g_base.large = NULL;
		return ;
	}
	tmp = g_base.large;
	while (tmp && tmp->next && tmp->next != block)
		tmp = tmp->next;
	if (tmp && tmp->next && tmp->next == block)
	{
		tmp->next = block->next;
		munmap(block, (sizeof(t_block) + block->size) / ps);
	}
}

void			free(void *ptr)
{
	t_block		*block;

	if (!ptr)
		return ;
	ft_mutex(1, &g_mutex);
	if (ft_is_alloc(ptr) == TRUE)
	{
		block = ft_get_block_ptr(ptr);
		if (ft_get_block_type(block) == TLARGE)
			ft_free_block_large(block);
		else
			block->free = 1;
	}
	ft_mutex(0, &g_mutex);
}
