# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/29 18:14:32 by anvilla-          #+#    #+#              #
#    Updated: 2025/07/02 18:32:06 by anvilla-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

RM = rm -f

all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME_SERVER): $(SERVER_OBJ) $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME_SERVER)  $(SERVER_OBJ) $(LIBFT)

$(NAME_CLIENT): $(CLIENT_OBJ) $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(CLIENT_OBJ) $(LIBFT)

clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re