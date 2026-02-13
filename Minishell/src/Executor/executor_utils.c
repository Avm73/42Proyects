/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:56:53 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/04 16:04:44 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_special_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	return (!ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset")
		|| !ft_strcmp(cmd, "exit"));
}

void	free_split_int(int **arr, int n)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (i < n)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
}
