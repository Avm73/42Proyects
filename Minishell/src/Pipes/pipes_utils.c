/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:59:46 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/04 13:13:51 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_cmds(t_cmd *cmd)
{
	int	count;

	count = 0;
	while (cmd)
	{
		count++;
		cmd = cmd->next;
	}
	return (count);
}

int	wait_all(pid_t *pids, int n)
{
	int	i;
	int	status;
	int	last;

	last = 0;
	i = 0;
	while (i < n)
	{
		waitpid(pids[i], &status, 0);
		if (WIFSIGNALED(status))
			last = 128 + WTERMSIG(status);
		else if (WIFEXITED(status))
			last = WEXITSTATUS(status);
		i++;
	}
	return (last);
}
