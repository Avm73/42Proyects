/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:57:05 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/12 16:34:31 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_heredoc(char *limiter, int expand, t_shell *sh)
{
	int		pipefd[2];
	pid_t	pid;
	int		status;

	if (pipe(pipefd) < 0)
		return (-1);
	pid = fork();
	if (pid < 0)
		return (close(pipefd[0]), close(pipefd[1]), -1);
	if (pid == 0)
	{
		close(pipefd[0]);
		run_heredoc_child(limiter, expand, pipefd[1], sh);
	}
	close(pipefd[1]);
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (-2);
	}
	return (pipefd[0]);
}
