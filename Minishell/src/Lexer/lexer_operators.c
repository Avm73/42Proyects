/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:28:28 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/04 12:06:38 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token_type	detect_operator(const char *s, int *adv)
{
	if (s[0] == '|')
		return (*adv = 1, TOKEN_PIPE);
	if (s[0] == '<' && s[1] == '<')
		return (*adv = 2, TOKEN_HEREDOC);
	if (s[0] == '>' && s[1] == '>')
		return (*adv = 2, TOKEN_REDIR_APPEND);
	if (s[0] == '<')
		return (*adv = 1, TOKEN_REDIR_IN);
	if (s[0] == '>')
		return (*adv = 1, TOKEN_REDIR_OUT);
	return (-1);
}

int	is_operator(t_token_type t)
{
	return (t == TOKEN_PIPE || t == TOKEN_REDIR_IN
		|| t == TOKEN_REDIR_OUT || t == TOKEN_REDIR_APPEND
		|| t == TOKEN_HEREDOC);
}
