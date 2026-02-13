/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:57:12 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/04 13:16:53 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_heredoc(t_cmd *cmd)
{
	t_redir	*r;

	r = cmd->redirs;
	while (r)
	{
		if (r->type == TOKEN_HEREDOC)
			return (1);
		r = r->next;
	}
	return (0);
}

t_redir	*get_last_heredoc(t_redir *r)
{
	t_redir	*last;

	last = NULL;
	while (r)
	{
		if (r->type == TOKEN_HEREDOC)
			last = r;
		r = r->next;
	}
	return (last);
}
