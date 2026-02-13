/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_external.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:56:39 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/04 13:23:56 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_path(char *dir, char *cmd)
{
	char	*tmp;
	char	*full;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	full = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	exec_external(t_cmd *cmd, t_shell *sh)
{
	char	*path;

	path = find_executable(cmd->argv[0], sh);
	if (!path)
	{
		ft_printf("minishell: %s: command not found\n", cmd->argv[0]);
		exit(127);
	}
	execve(path, cmd->argv, sh->env);
	ft_printf("minishell: %s: exec error\n", cmd->argv[0]);
	exit(126);
}
