/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:41:44 by andres            #+#    #+#             */
/*   Updated: 2026/02/05 11:20:22 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_redirs(t_redir *r)
{
	t_redir	*tmp;

	while (r)
	{
		tmp = r->next;
		free(r->file);
		free(r);
		r = tmp;
	}
}

void	free_tokens(t_token *tok)
{
	t_token	*tmp;

	while (tok)
	{
		tmp = tok->next;
		free(tok->value);
		free(tok);
		tok = tmp;
	}
}

void	free_cmds(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	while (cmd)
	{
		tmp = cmd->next;
		i = 0;
		while (cmd->argv && cmd->argv[i])
		{
			free(cmd->argv[i]);
			i++;
		}
		free(cmd->argv);
		free_redirs(cmd->redirs);
		free(cmd);
		cmd = tmp;
	}
}
