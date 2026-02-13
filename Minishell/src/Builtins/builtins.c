/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:52:42 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/05 13:02:31 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	if (ft_strcmp(cmd, "export") == 0)
		return (1);
	if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	if (ft_strcmp(cmd, "env") == 0)
		return (1);
	if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	return (0);
}

int	exec_builtin(t_cmd *cmd, t_shell *sh)
{
	if (ft_strcmp(cmd->argv[0], "echo") == 0)
		return (builtin_echo(cmd->argv));
	if (ft_strcmp(cmd->argv[0], "pwd") == 0)
		return (builtin_pwd());
	if (ft_strcmp(cmd->argv[0], "env") == 0)
		return (builtin_env(sh));
	if (ft_strcmp(cmd->argv[0], "cd") == 0)
		return (builtin_cd(cmd->argv, sh));
	if (ft_strcmp(cmd->argv[0], "export") == 0)
		return (builtin_export(cmd->argv, sh));
	if (ft_strcmp(cmd->argv[0], "unset") == 0)
		return (builtin_unset(cmd->argv, sh));
	if (ft_strcmp(cmd->argv[0], "exit") == 0)
		return (builtin_exit(cmd->argv, sh));
	return (1);
}
