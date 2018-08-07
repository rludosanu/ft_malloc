/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_free_block.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:12:19 by rludosan          #+#    #+#             */
/*   Updated: 2017/03/28 11:35:41 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block				*ft_find_free_block(size_t size)
{
	t_block			*tmp;

	if (size <= TINY)
		tmp = g_base.tiny;
	else if (size <= SMALL)
		tmp = g_base.small;
	else
		tmp = g_base.large;
	if (!tmp)
		return (NULL);
	while (tmp && !(tmp->free == 1 && tmp->size >= size))
		tmp = tmp->next;
	return (tmp);
}
