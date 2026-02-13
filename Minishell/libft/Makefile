LIB = ar -rcs

NAME = libft.a

SOURCES = ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_isnumeric.c\
		ft_itoa.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strrchr.c\
		ft_strchr.c\
		ft_strcmp.c\
		ft_strdup.c\
		ft_strndup.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strjoin3.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strtrim.c\
		ft_strnstr.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_mini_atoi.c\
		ft_print_char.c\
		ft_print_format.c\
		ft_print_hex.c\
		ft_print_number.c\
		ft_print_percent.c\
		ft_print_pointer.c\
		ft_print_string.c\
		ft_print_unsigned.c\
		ft_printf.c\
		ft_read_format.c\
		ft_reader.c\
		ft_utils_hex.c\
		utils_read.c\
		utils.c\
		get_next_line.c\
		get_next_line_utils.c\

BONUS = ft_lstadd_back_bonus.c\
		ft_lstadd_front_bonus.c\
		ft_lstclear_bonus.c\
		ft_lstdelone_bonus.c\
		ft_lstlast_bonus.c\
		ft_lstnew_bonus.c\
		ft_lstsize_bonus.c\
		ft_lstmap_bonus.c\
		ft_lstiter_bonus.c\
		get_next_line_bonus.c\
		get_next_line_utils_bonus.c\


OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(BONUS:.c=.o)

CC = gcc

CFLAGS += -Wall -Wextra -Werror -I .

$(NAME): $(OBJECTS)
	$(LIB) $(NAME) $(OBJECTS)
	ranlib ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME) $(OBJECTS) $(OBJECTS_BONUS)

re:     fclean all

bonus: $(OBJECTS_BONUS)
	$(LIB) $(NAME) $(OBJECTS_BONUS)


.PHONY: all clean fclean re
