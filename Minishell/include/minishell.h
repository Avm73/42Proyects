/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:20:21 by andres            #+#    #+#             */
/*   Updated: 2026/02/12 15:37:38 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"
# include <signal.h>
# include <termios.h>

typedef enum e_redir_type
{
	NO_REDIR,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_IN
}	t_redir_type;

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_APPEND,
	TOKEN_HEREDOC,
	TOKEN_EOF
}	t_token_type;

typedef struct s_shell
{
	char			**env;
	int				last_status;
	struct termios	original_term;
}	t_shell;

typedef enum e_lex_state
{
	STATE_GENERAL,
	STATE_IN_SQUOTE,
	STATE_IN_DQUOTE
}	t_lex_state;

typedef struct s_redir
{
	t_token_type	type;
	char			*file;
	int				heredoc_fd;
	int				quoted;
	struct s_redir	*next;
}	t_redir;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	int				single_quoted;
	int				double_quoted;
	int				concat;
	struct s_token	*next;
}	t_token;

typedef struct s_lexer
{
	char	buf[4096];
	int		buf_i;
	int		i;
	int		state;
}	t_lexer;

typedef struct s_cmd
{
	char			**argv;
	t_redir			*redirs;
	char			**assignments;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_exec
{
	int		n;
	int		**pipes;
	pid_t	*pids;
}	t_exec;

//Builtin
int				builtin_cd(char **argv, t_shell *sh);
int				builtin_echo(char **argv);
int				builtin_env(t_shell *sh);
int				builtin_exit(char **argv, t_shell *sh);
int				is_valid_export_identifier(const char *s);
void			print_export(t_shell *sh);
int				builtin_export(char **argv, t_shell *sh);
int				builtin_pwd(void);
int				is_valid_identifier(const char *s);
int				builtin_unset(char **argv, t_shell *sh);
int				is_builtin(char *cmd);
int				exec_builtin(t_cmd *cmd, t_shell *sh);
//env;
char			*get_env_value(char *key, char **env);
int				find_key_index(char **env, const char *key);
char			**dup_env(char **envp);
void			set_env_value(const char *name, const char *value, t_shell *sh);
int				find_key_index(char **env, const char *key);
char			*find_executable(char *cmd, t_shell *sh);
int				unset_env_value(const char *key, t_shell *sh);
int				env_size(char **env);
char			**copy_env_without(char **env, int index);
//Executor
void			apply_assignments_to_shell(t_cmd *cmd, t_shell *sh);
void			apply_assignments_to_child(t_cmd *cmd, t_shell *sh);
char			*join_path(char *dir, char *cmd);
void			exec_external(t_cmd *cmd, t_shell *sh);
int				execute_pipeline(t_cmd *cmds, t_shell *sh);
int				execute_single(t_cmd *cmd, t_shell *sh);
int				is_special_builtin(char *cmd);
//Heredoc
void			run_heredoc_child(char *limiter, int expand, \
				int write_fd, t_shell *sh);
int				handle_heredoc(char *limiter, int expand, t_shell *sh);
int				prepare_heredocs(t_cmd *cmds, t_shell *sh);
int				has_heredoc(t_cmd *cmd);
t_redir			*get_last_heredoc(t_redir *r);
int				handle_heredocs(t_cmd *cmds, t_shell *sh);
//Lexer
t_token_type	detect_operator(const char *s, int *adv);
int				is_operator(t_token_type t);
t_token			*token_new(t_token_type type, char *value);
void			token_add_back(t_token **list, t_token *new);
void			push_buffer(t_token **tokens, t_lexer *lex);
int				handle_operator(const char *input, t_lexer *lex, \
				t_token **tokens);
int				handle_quote_state(t_lexer *lex, char c);
int				handle_closing_quote(t_lexer *lex, char c, \
				t_token **tokens, int q_type);
int				validate_tokens(t_token *tok);
t_token			*lexer(const char *input);
t_token			*get_last_token(t_token *tokens);
void			merge_concat_tokens(t_token **tokens);
//Parser
void			cmd_add_assignment(t_cmd *cmd, char *assign);
void			cmd_add_arg(t_cmd *cmd, char *arg);
void			cmd_add_redir(t_cmd *cmd, t_token_type type, \
				char *file, int quoted);
t_cmd			*new_cmd(void);
int				handle_redirection(t_cmd *current, t_token **tok);
void			append_cmd(t_cmd **cmds, t_cmd *current);
int				is_assignment_word(const char *s);
char			*merge_words(t_token **tok);
t_cmd			*parse_tokens(t_token *tok);
char			**grow_array(char **arr, int count);
//Pipes
void			exec_child(t_cmd *cmd, int i, t_exec *ex, t_shell *sh);
pid_t			fork_child(t_cmd *cmd, int i, t_exec ex, t_shell *sh);
int				count_cmds(t_cmd *cmd);
int				wait_all(pid_t *pids, int n);
int				**create_pipes(int n);
void			close_all_pipes(int **pipes, int n);
//Redirections
int				apply_redirections(t_redir *r);
//expands
void			expand_tokens(t_token *tok, t_shell *sh);
char			*expand_word(char *word, t_shell *sh);
char			*expand_dollar(char *word, int *i, t_shell *sh);
char			*get_var_value(char *name, t_shell *sh);
//signals
void			sigint_handler(int sig);
void			sigint_child(int sig);
void			sigquit_child(int sig);
void			sigint_heredoc(int sig);
//frees
void			free_redirs(t_redir *r);
void			free_cmds(t_cmd *cmd);
void			free_tokens(t_token *tok);
void			free_split(char **arr);
void			free_split_int(int **arr, int n);
#endif