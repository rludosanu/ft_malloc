/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:09:56 by rludosan          #+#    #+#             */
/*   Updated: 2017/03/28 13:21:28 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void				show_alloc_mem_block(uintptr_t start, uintptr_t end)
{
	ft_putaddr(start);
	ft_putstr(" - ");
	ft_putaddr(end);
	ft_putstr(" : ");
	ft_putnbr(end - start);
	ft_putstr(" octets\n");
}

void				show_alloc_mem_list(char *zone, t_block *block)
{
	t_block			*tmp;
	char			*start;
	char			*end;

	if (!(tmp = block) || tmp->free == 1)
		return ;
	ft_putstr(zone);
	ft_putstr(" : ");
	ft_putaddr((uintptr_t)tmp);
	ft_putstr("\n");
	while (tmp)
	{
		if (tmp->free == 0)
		{
			start = (char *)tmp + sizeof(t_block);
			end = start + tmp->size;
			show_alloc_mem_block((uintptr_t)start, (uintptr_t)end);
		}
		tmp = tmp->next;
	}
}

void				show_alloc_mem(void)
{
	ft_mutex(1, &g_mutex);
	show_alloc_mem_list("TINY", g_base.tiny);
	show_alloc_mem_list("SMALL", g_base.small);
	show_alloc_mem_list("LARGE", g_base.large);
	ft_mutex(0, &g_mutex);
}
