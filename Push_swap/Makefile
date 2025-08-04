# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/27 19:24:05 by anvilla-          #+#    #+#              #
#    Updated: 2025/07/04 20:00:40 by anvilla-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Werror -Wextra -g

SRCS = main.c ft_validation.c ft_create_stack.c create_node.c delete_node.c \
a_movements.c b_movements.c double_moves.c index_size.c tiny_sort.c \
radix_sort.c

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all : $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME) : $(OBJS) $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
