/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:05:51 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/07 18:30:21 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_token_word(t_token *tok, t_cmd *current)
{
	if (!current->argv && is_assignment_word(tok->value))
		cmd_add_assignment(current, tok->value);
	else
		cmd_add_arg(current, tok->value);
}

t_cmd	*parse_tokens(t_token *tok)
{
	t_cmd	*cmds;
	t_cmd	*current;

	cmds = NULL;
	current = new_cmd();
	while (tok)
	{
		if (tok->type == TOKEN_WORD)
			handle_token_word(tok, current);
		else if (tok->type == TOKEN_REDIR_IN || tok->type == TOKEN_REDIR_OUT
			|| tok->type == TOKEN_REDIR_APPEND || tok->type == TOKEN_HEREDOC)
		{
			if (handle_redirection(current, &tok))
				return (NULL);
		}
		else if (tok->type == TOKEN_PIPE)
		{
			append_cmd(&cmds, current);
			current = new_cmd();
		}
		tok = tok->next;
	}
	append_cmd(&cmds, current);
	return (cmds);
}
