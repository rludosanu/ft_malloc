/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_memory_block.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:11:27 by rludosan          #+#    #+#             */
/*   Updated: 2017/03/28 10:11:40 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void				ft_add_memory_block(t_block **head, t_block *block)
{
	t_block			*tmp;

	if (!(*head))
	{
		block->bid = 1;
		*head = block;
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		block->bid = tmp->bid + 1;
		tmp->next = block;
	}
}
