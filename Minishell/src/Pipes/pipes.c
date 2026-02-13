/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:59:54 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/12 16:39:00 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	**create_pipes(int n)
{
	int	**pipes;
	int	i;

	pipes = malloc(sizeof(int *) * n);
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < n)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (!pipes[i] || pipe(pipes[i]) < 0)
			return (NULL);
		i++;
	}
	return (pipes);
}

void	close_all_pipes(int **pipes, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}
