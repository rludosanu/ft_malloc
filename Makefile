# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rludosan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/24 18:12:00 by rludosan          #+#    #+#              #
#    Updated: 2017/03/29 10:11:23 by rludosan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME		=	libft_malloc_$(HOSTTYPE).so
LINK		=	libft_malloc.so
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRC_FILES	=	free \
				ft_add_memory_block \
				ft_find_free_block \
				ft_memcpy \
				ft_merge_memory_block \
				ft_mutex \
				ft_put \
				ft_request_memory_block \
				ft_split_memory_block \
				malloc \
				realloc \
				show_alloc_mem \
				ft_is_alloc \
				ft_get_block_ptr
OBJ_FILES	=	$(addsuffix .o, $(SRC_FILES))
OBJ			=	$(addprefix obj/, $(OBJ_FILES))
INC			=	-Iinc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -shared -o $@ $^
	ln -s $@ $(LINK)

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) && rm -f $(LINK)

re: fclean all

.PHONY: all clean fclean re
