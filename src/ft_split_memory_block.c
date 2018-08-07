/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_memory_block.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:11:07 by rludosan          #+#    #+#             */
/*   Updated: 2017/03/28 15:47:25 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int					ft_split_memory_block(t_block *block, size_t size)
{
	t_block			*new;
	t_block			*next;
	char			*tmp;

	if (block && size)
	{
		if (block->free == 1 && block->size >= (size + sizeof(t_block) + 4))
		{
			next = block->next;
			tmp = (char *)block + sizeof(t_block) + size;
			new = (t_block *)tmp;
			new->bid = block->bid;
			new->free = 1;
			new->size = block->size - sizeof(t_block) - size;
			block->size = size;
			block->next = new;
			new->next = next;
			return (TRUE);
		}
	}
	return (FALSE);
}
