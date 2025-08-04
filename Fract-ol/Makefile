# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/08 14:12:33 by anvilla-          #+#    #+#              #
#    Updated: 2025/07/14 19:09:13 by anvilla-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

MINI_DIR = ./minilibx-linux
MINI = $(MINI_DIR)/libmlx.a

LIBFT_DIR= ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

SRCS = main.c window.c keyboard.c mouse.c name.c utils.c fractals.c

OBJS = $(SRCS:.c=.o)

all:  $(MINI) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINI)
	$(CC) $(CFLAGS) -v -o $(NAME) $(OBJS) $(LIBFT) -L$(MINI_DIR) -lmlx -lXext -lX11 -lm

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINI):
	make -C $(MINI_DIR)

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINI_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MINI_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
