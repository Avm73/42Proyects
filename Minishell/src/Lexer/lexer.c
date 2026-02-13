/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:26:52 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/10 11:44:08 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_structs(t_token **tokens, t_lexer *lex)
{
	lex->buf[0] = '\0';
	lex->buf_i = 0;
	lex->i = 0;
	lex->state = 0;
	*tokens = NULL;
}

static void	handle_concat(t_token *tokens, const char *input, t_lexer lex)
{
	if (input[lex.i + 1] && (input[lex.i + 1] != ' '))
		(get_last_token(tokens))->concat = 1;
}

t_token	*lexer(const char *input)
{
	t_token	*tokens;
	t_lexer	lex;

	init_structs(&tokens, &lex);
	while (input[lex.i])
	{
		if (lex.state == 0 && (input[lex.i] == ' ' || input[lex.i] == '\t'))
			(push_buffer(&tokens, &lex), lex.i++);
		else if (handle_quote_state(&lex, input[lex.i]))
			lex.i++;
		else if (handle_operator(input, &lex, &tokens))
			continue ;
		else if (handle_closing_quote(&lex, input[lex.i], &tokens, 1))
			lex.i++;
		else if (handle_closing_quote(&lex, input[lex.i], &tokens, 2))
			(handle_concat(tokens, input, lex), lex.i++);
		else
			lex.buf[lex.buf_i++] = input[lex.i++];
	}
	if (lex.state != 0)
		return (ft_printf("minishell: syntax error: unclosed quote\n"),
			free_tokens(tokens), NULL);
	push_buffer(&tokens, &lex);
	return (tokens);
}
