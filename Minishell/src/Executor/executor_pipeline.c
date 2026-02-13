/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_pipeline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:56:44 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/12 15:37:17 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_assignments_only(t_cmd *cmds, t_shell *sh)
{
	int	saved_in;
	int	saved_out;

	if (!cmds->next && !cmds->argv && cmds->assignments)
		return (apply_assignments_to_shell(cmds, sh), 1);
	if (!cmds->next && !cmds->argv && cmds->redirs->type == TOKEN_HEREDOC)
		return (handle_heredocs(cmds, sh), 1);
	if (!cmds->argv && cmds->redirs)
	{
		saved_in = dup(STDIN_FILENO);
		saved_out = dup(STDOUT_FILENO);
		apply_redirections(cmds->redirs);
		dup2(saved_in, STDIN_FILENO);
		dup2(saved_out, STDOUT_FILENO);
		close(saved_in);
		close(saved_out);
		return (1);
	}
	return (0);
}

int	handle_heredocs(t_cmd *cmds, t_shell *sh)
{
	int	ret;

	ret = prepare_heredocs(cmds, sh);
	if (ret == -2)
	{
		write(1, "\n", 1);
		sh->last_status = 130;
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, SIG_IGN);
		return (-1);
	}
	if (ret < 0)
		return (-1);
	return (0);
}

static void	fork_all(t_cmd *cmds, t_exec *ex, t_shell *sh)
{
	t_cmd	*tmp;
	int		i;

	tmp = cmds;
	i = 0;
	while (i < ex->n)
	{
		ex->pids[i] = fork();
		if (ex->pids[i] == 0)
			exec_child(tmp, i, ex, sh);
		tmp = tmp->next;
		i++;
	}
}

int	execute_pipeline(t_cmd *cmds, t_shell *sh)
{
	t_exec	ex;

	if (handle_assignments_only(cmds, sh))
		return (0);
	if (handle_heredocs(cmds, sh) < 0)
		return (1);
	if (!cmds->next && is_special_builtin(cmds->argv[0]) && !has_heredoc(cmds))
		return (execute_single(cmds, sh));
	ex.n = count_cmds(cmds);
	ex.pipes = create_pipes(ex.n - 1);
	ex.pids = malloc(sizeof(pid_t) * ex.n);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	fork_all(cmds, &ex, sh);
	close_all_pipes(ex.pipes, ex.n - 1);
	sh->last_status = wait_all(ex.pids, ex.n);
	if (sh->last_status == 130)
		write(1, "\n", 1);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	free(ex.pids);
	free_split_int(ex.pipes, ex.n - 1);
	return (sh->last_status);
}
