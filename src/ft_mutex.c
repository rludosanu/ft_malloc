/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:14:21 by rludosan          #+#    #+#             */
/*   Updated: 2017/03/28 10:15:42 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		ft_mutex(int action, pthread_mutex_t *g_mutex)
{
	if (g_mutex)
	{
		if (action == 1)
		{
			pthread_mutex_init(g_mutex, NULL);
			pthread_mutex_lock(g_mutex);
		}
		else
		{
			pthread_mutex_unlock(g_mutex);
			pthread_mutex_destroy(g_mutex);
		}
	}
}
