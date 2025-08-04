# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 15:50:10 by anvilla-          #+#    #+#              #
#    Updated: 2025/07/14 18:43:34 by anvilla-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SOURCE = ft_calloc.c ft_isascii.c ft_memchr.c ft_memmove.c ft_strdup.c \
ft_strlen.c ft_tolower.c ft_atoi.c ft_isalnum.c ft_isdigit.c ft_itoa.c\
ft_memcmp.c ft_memset.c ft_strlcat.c ft_strnstr.c ft_toupper.c ft_bzero.c \
ft_isalpha.c ft_isprint.c ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_strrchr.c \
ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_putchar_fd.c ft_split.c\
ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_striteri.c ft_strmapi.c\
ft_strncmp.c

B_SOURCE = ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c \
ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SOURCE:.c=.o)

B_OBJS = $(B_SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	ar rc $(NAME) $(OBJS)

bonus: $(OBJS) $(B_OBJS)
	ar rc $(NAME)  $(OBJS) $(B_OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(B_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
