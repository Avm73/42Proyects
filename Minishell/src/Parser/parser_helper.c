/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:06:39 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/04 13:06:08 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*new_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	ft_memset(cmd, 0, sizeof(t_cmd));
	return (cmd);
}

int	handle_redirection(t_cmd *current, t_token **tok)
{
	t_token_type	op;
	int				quoted;

	op = (*tok)->type;
	*tok = (*tok)->next;
	if (!*tok || (*tok)->type != TOKEN_WORD)
	{
		ft_printf("syntax error near redirection\n");
		return (1);
	}
	quoted = (*tok)->single_quoted || (*tok)->double_quoted;
	cmd_add_redir(current, op, (*tok)->value, quoted);
	return (0);
}

void	append_cmd(t_cmd **cmds, t_cmd *current)
{
	t_cmd	*tmp;

	if (!*cmds)
		*cmds = current;
	else
	{
		tmp = *cmds;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = current;
	}
}
