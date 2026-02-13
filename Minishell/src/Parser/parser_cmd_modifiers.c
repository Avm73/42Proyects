/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd_modifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:07:30 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/04 13:07:10 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_add_assignment(t_cmd *cmd, char *assign)
{
	int		count;
	char	**new;

	count = 0;
	if (cmd->assignments)
		while (cmd->assignments[count])
			count++;
	new = grow_array(cmd->assignments, count);
	if (!new)
		return ;
	new[count] = ft_strdup(assign);
	cmd->assignments = new;
}

void	cmd_add_arg(t_cmd *cmd, char *arg)
{
	int		count;
	char	**new;

	count = 0;
	while (cmd->argv && cmd->argv[count])
		count++;
	new = grow_array(cmd->argv, count);
	if (!new)
		return ;
	new[count] = ft_strdup(arg);
	cmd->argv = new;
}

void	cmd_add_redir(t_cmd *cmd, t_token_type type, char *file, int quoted)
{
	t_redir	*new;
	t_redir	*tmp;

	new = malloc(sizeof(t_redir));
	if (!new)
		return ;
	new->type = type;
	new->file = ft_strdup(file);
	new->quoted = quoted;
	new->next = NULL;
	if (!cmd->redirs)
		cmd->redirs = new;
	else
	{
		tmp = cmd->redirs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
