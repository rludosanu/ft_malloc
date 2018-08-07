/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:09:19 by rludosan          #+#    #+#             */
/*   Updated: 2017/03/28 10:18:53 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void				ft_putchar(char c)
{
	write(0, &c, 1);
}

void				ft_putstr(char *s)
{
	while (s && *s != '\0')
		ft_putchar(*s++);
}

void				ft_putnbr(int n)
{
	unsigned int	x;

	if (n < 0)
	{
		ft_putchar('-');
		x = (unsigned int)n * -1;
	}
	else
		x = (unsigned int)n;
	if (x >= 10)
		ft_putnbr(x / 10);
	ft_putchar((x % 10) + '0');
}

void				ft_putaddr_n(uintptr_t addr)
{
	const char		base[16] = "0123456789abcdef";
	uintptr_t		x;

	x = (unsigned int)addr;
	if (x >= 10)
		ft_putaddr_n(x / 16);
	ft_putchar(base[x % 16]);
}

void				ft_putaddr(uintptr_t addr)
{
	ft_putstr("0x");
	ft_putaddr_n(addr);
}
