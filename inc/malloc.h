/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:06:42 by rludosan          #+#    #+#             */
/*   Updated: 2017/03/29 10:19:38 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <string.h>
# include <unistd.h>
# include <sys/mman.h>
# include <pthread.h>
# include <inttypes.h>

# define TINY 1024
# define SMALL 1024 * 128

# define MMAP_PROT PROT_READ | PROT_WRITE
# define MMAP_MAP MAP_ANON | MAP_PRIVATE

# define FALSE 0
# define TRUE 1

# define TTINY 1
# define TSMALL 2
# define TLARGE 3

typedef struct		s_block
{
	int				bid;
	int				free;
	size_t			size;
	struct s_block	*next;
}					t_block;

typedef struct		s_base
{
	struct s_block	*tiny;
	struct s_block	*small;
	struct s_block	*large;
}					t_base;

t_base				g_base;
pthread_mutex_t		g_mutex;

void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putnbr(int n);
void				ft_putaddr_n(uintptr_t addr);
void				ft_putaddr(uintptr_t addr);
void				show_alloc_mem(void);
t_block				*ft_merge_memory_block(t_block *block, size_t size);
int					ft_split_memory_block(t_block *block, size_t size);
void				ft_add_memory_block(t_block **head, t_block *block);
t_block				*ft_request_memory(size_t size);
t_block				*ft_find_free_block(size_t size);
void				*malloc(size_t size);
void				free(void *ptr);
void				*realloc(void *ptr, size_t size);
void				ft_mutex(int action, pthread_mutex_t *mutex);
int					ft_is_alloc(void *ptr);
t_block				*ft_get_block_ptr(void *ptr);

#endif
