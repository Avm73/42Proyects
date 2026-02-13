/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_exec_child.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:59:41 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/05 12:35:39 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_child(t_cmd *cmd, int i, t_exec *ex, t_shell *sh)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (i > 0)
		dup2(ex->pipes[i - 1][0], STDIN_FILENO);
	if (i < ex->n - 1)
		dup2(ex->pipes[i][1], STDOUT_FILENO);
	close_all_pipes(ex->pipes, ex->n - 1);
	if (apply_redirections(cmd->redirs) < 0)
		exit(1);
	apply_assignments_to_child(cmd, sh);
	if (is_builtin(cmd->argv[0]))
		exit(exec_builtin(cmd, sh));
	exec_external(cmd, sh);
	exit(1);
}
