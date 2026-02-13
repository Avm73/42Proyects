/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_assignments.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:56:34 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/04 13:24:29 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	assign_one(char *assign, t_shell *sh)
{
	char	*eq;

	eq = ft_strchr(assign, '=');
	*eq = '\0';
	set_env_value(assign, eq + 1, sh);
	*eq = '=';
}

void	apply_assignments_to_shell(t_cmd *cmd, t_shell *sh)
{
	int	i;

	i = 0;
	while (cmd->assignments && cmd->assignments[i])
	{
		assign_one(cmd->assignments[i], sh);
		i++;
	}
}

void	apply_assignments_to_child(t_cmd *cmd, t_shell *sh)
{
	int	i;

	i = 0;
	while (cmd->assignments && cmd->assignments[i])
	{
		assign_one(cmd->assignments[i], sh);
		i++;
	}
}
