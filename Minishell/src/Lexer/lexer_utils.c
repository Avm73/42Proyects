/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:27:28 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/10 11:42:23 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	append_to_last_token(t_token **list, char *extra)
{
	t_token	*last;
	char	*new_value;

	if (!list || !*list)
		return ;
	last = *list;
	while (last->next)
		last = last->next;
	new_value = ft_strjoin(last->value, extra);
	free (last->value);
	last->value = new_value;
}

void	push_buffer(t_token **tokens, t_lexer *lex)
{
	if (lex->buf_i > 0)
	{
		lex->buf[lex->buf_i] = '\0';
		token_add_back(tokens, token_new(TOKEN_WORD, ft_strdup(lex->buf)));
		lex->buf_i = 0;
	}
}

int	handle_operator(const char *input, t_lexer *lex, t_token **tokens)
{
	int				adv;
	t_token_type	op;

	op = detect_operator(&input[lex->i], &adv);
	if ((int)op == -1)
		return (0);
	push_buffer(tokens, lex);
	token_add_back(tokens, token_new(op, ft_strndup(&input[lex->i], adv)));
	lex->i += adv;
	return (1);
}

int	handle_quote_state(t_lexer *lex, char c)
{
	if (lex->state == 0 && c == '\'')
	{
		lex->state = 1;
		return (1);
	}
	if (lex->state == 0 && c == '"')
	{
		lex->state = 2;
		return (1);
	}
	return (0);
}

int	handle_closing_quote(t_lexer *lex, char c, t_token **tokens, int q_type)
{
	t_token	*t;
	char	q_char;

	if (q_type == 1)
		q_char = '\'';
	else
		q_char = '"';
	if (lex->state != q_type || c != q_char)
		return (0);
	lex->buf[lex->buf_i] = '\0';
	t = token_new(TOKEN_WORD, ft_strdup(lex->buf));
	if (!t)
		return (0);
	if (q_type == 1)
		t->single_quoted = 1;
	else
		t->double_quoted = 1;
	token_add_back(tokens, t);
	lex->buf_i = 0;
	lex->state = 0;
	return (1);
}
