NAME = minishell

SRC = src/main.c\
	src/frees.c\
	src/redirections.c\
	src/signals.c\
	src/expands.c\
	src/get_value_var.c\
	src/Builtins/builtin_cd.c\
	src/Builtins/builtin_echo.c\
	src/Builtins/builtin_env.c\
	src/Builtins/builtin_exit.c\
	src/Builtins/builtin_export.c\
	src/Builtins/builtin_pwd.c\
	src/Builtins/builtin_unset.c\
	src/Builtins/builtins.c\
	src/env/env_getters.c\
	src/env/env_setters.c\
	src/env/env_utils.c\
	src/Executor/executor_assignments.c\
	src/Executor/executor_external.c\
	src/Executor/executor_pipeline.c\
	src/Executor/executor_single.c\
	src/Executor/executor_utils.c\
	src/Heredoc/heredoc_child.c\
	src/Heredoc/heredoc_parent.c\
	src/Heredoc/heredoc_utils.c\
	src/Heredoc/heredoc_prepare_heredoc.c\
	src/Lexer/lexer_operators.c\
	src/Lexer/lexer_token_basics.c\
	src/Lexer/lexer_utils.c\
	src/Lexer/lexer_validation.c\
	src/Lexer/lexer.c\
	src/Parser/parser_cmd_modifiers.c\
	src/Parser/parser_helper.c\
	src/Parser/parser_utils.c\
	src/Parser/parser.c\
	src/Pipes/pipes_exec_child.c\
	src/Pipes/pipes_utils.c\
	src/Pipes/pipes.c
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilibft -lreadline
LIBS = -lreadline -lncurses 
LIBFT = libft/libft.a 
all: $(LIBFT) $(NAME) 
$(LIBFT): 
	@$(MAKE) -C libft 
$(NAME): $(OBJ) 
	$(CC) $(OBJ) $(LIBFT) -o $(NAME) $(LIBS)
clean:
	@rm -f $(OBJ) 
	@$(MAKE) clean -C libft 
fclean: clean
	@rm -f $(NAME) 
	@$(MAKE) fclean -C libft 
re: fclean all 
.PHONY: all clean fclean re 