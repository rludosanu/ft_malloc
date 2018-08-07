/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:12:58 by rludosan          #+#    #+#             */
/*   Updated: 2017/03/28 16:06:34 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			*ft_try_realloc(void *ptr, size_t size)
{
	void		*new;
	t_block		*blk;

	blk = ft_get_block_ptr(ptr);
	if (!size && ptr)
		free(ptr);
	else if (ft_is_alloc(ptr) == FALSE)
		return (NULL);
	else if (blk->size == size ||
			(blk->size > size && ft_split_memory_block(blk, size) == TRUE))
		return (ptr);
	else if ((new = malloc(size)))
	{
		ft_memcpy(new, ptr, size);
		free(ptr);
		return (new);
	}
	return (NULL);
}

void			*realloc(void *ptr, size_t size)
{
	void		*ret;

	ft_mutex(1, &g_mutex);
	ret = NULL;
	if (!ptr)
	{
		ft_mutex(0, &g_mutex);
		return (malloc(size));
	}
	ret = ft_try_realloc(ptr, size);
	ft_mutex(0, &g_mutex);
	return (ret);
}
