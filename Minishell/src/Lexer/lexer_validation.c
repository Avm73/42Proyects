/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:28:04 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/04 14:18:59 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_syntax(const char *msg, const char *tok)
{
	if (tok)
		return (ft_printf("minishell: syntax error near\
			unexpected token `%s'\n", tok), 1);
	return (ft_printf("minishell: syntax error near\
		 unexpected token `%s'\n", msg), 1);
}

int	validate_tokens(t_token *tok)
{
	t_token	*prev;

	prev = NULL;
	if (!tok)
		return (0);
	if (tok->type == TOKEN_PIPE)
		return (print_syntax("|", NULL));
	while (tok)
	{
		if (is_operator(tok->type))
		{
			if (!tok->next)
				return (print_syntax("newline", NULL));
			if (tok->type == TOKEN_PIPE && tok->next->type == TOKEN_PIPE)
				return (print_syntax("|", NULL));
			if (tok->type != TOKEN_PIPE && tok->next->type != TOKEN_WORD)
				return (print_syntax(tok->next->value, NULL));
		}
		prev = tok;
		tok = tok->next;
	}
	if (prev && prev->type == TOKEN_PIPE)
		return (print_syntax("|", NULL));
	return (0);
}
