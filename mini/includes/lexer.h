/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:05:54 by anvilla-          #+#    #+#             */
/*   Updated: 2025/07/29 21:00:59 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../Libft/libft.h"


typedef enum	e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC,
	TOKEN_END,
}	token_type;

typedef struct s_token
{
	token_type		type;
	char			*value;
	struct s_token	*next;
}	t_token;

int		main();
t_token	*get_token(const char *str);
void	print_token(t_token *head);
void	add_token(t_token **head, t_token *new);
t_token	*new_token(token_type type, const char *str);

#endif