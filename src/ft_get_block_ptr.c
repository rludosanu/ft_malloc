/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_block_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 13:37:22 by rludosan          #+#    #+#             */
/*   Updated: 2017/03/28 13:39:32 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block		*ft_get_block_ptr(void *ptr)
{
	char	*tmp;

	if (!ptr)
		return (NULL);
	tmp = (char *)ptr - sizeof(t_block);
	return ((t_block *)tmp);
}
