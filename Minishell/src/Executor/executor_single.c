/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_single.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:56:48 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/06 14:41:31 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_single(t_cmd *cmd, t_shell *sh)
{
	pid_t	pid;

	if (!cmd || !cmd->argv || !cmd->argv[0])
		return (0);
	if (is_builtin(cmd->argv[0]))
		return (exec_builtin(cmd, sh));
	(signal(SIGINT, SIG_IGN), signal(SIGQUIT, SIG_IGN));
	pid = fork();
	if (pid < 0)
		return (ft_printf("minishell: fork error\n"),
			(signal(SIGINT, sigint_handler), signal(SIGQUIT, SIG_IGN), 1));
	if (pid == 0)
	{
		(signal(SIGINT, SIG_DFL), signal(SIGQUIT, SIG_DFL));
		if (apply_redirections(cmd->redirs) < 0)
			exit(1);
		exec_external(cmd, sh);
	}
	waitpid(pid, &sh->last_status, 0);
	if (WIFSIGNALED(sh->last_status))
		write(1, "\n", 1);
	(signal(SIGINT, sigint_handler), signal(SIGQUIT, SIG_IGN));
	if (WIFEXITED(sh->last_status))
		sh->last_status = WEXITSTATUS(sh->last_status);
	return (sh->last_status);
}
