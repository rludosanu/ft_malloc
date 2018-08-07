/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_memory_block.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:10:44 by rludosan          #+#    #+#             */
/*   Updated: 2017/03/28 11:38:44 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block				*ft_merge_memory_block(t_block *block, size_t size)
{
	t_block			*b;

	b = block;
	while (b)
	{
		if (b->size >= size && b->free == 1)
			return (b);
		if (b->free == 0)
			b = b->next;
		else
		{
			if (b && b->next && b->next->free == 1 && b->bid == b->next->bid)
			{
				b->size = b->size + sizeof(t_block) + b->next->size;
				b->next = b->next->next;
			}
			else
				b = b->next;
		}
	}
	return (NULL);
}
